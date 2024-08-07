#include <iostream>
#include <string>
#include <sqlite3.h>
#include <memory>
#include <algorithm>

#include "calculate.h"

using std::cout; 
using std::string;

/**
 * Used for debugging - prints the entire database line by line
*/
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}
    
/**
 * main function that orchestrates calculating handicaps for different
 * users. Reads its variables from the input file
 */
std::unique_ptr<DB_Entry> read_score(){
    // temp variables
    string course_name;
    double slope_index, course_rating;
    int score;

    // Give the correct format for inputting a score
    std::cout << "Please enter a score in format:\n<Course Name> <Score> <Slope Index> <Course Rating>\n";
    std::cout << "To quit application, please enter quit | q\n"; 

    // Read in the associated values
    try{
        std::cin >> course_name; 
        if(course_name == "quit" || course_name == "q"){
            std::cout << "Thank you for using the handicap calculator!\n";
            exit(0);
        }
        std::cin >> score >> slope_index >> course_rating; 
    }
    catch (std::exception &e){
        throw e.what();
        exit(1);
    }

    // Store this in an object and return
    std::unique_ptr<DB_Entry> input = std::make_unique<DB_Entry>(course_name, course_rating, score, slope_index);
    return input;
}

/**
 * Handling function which handles prompting the current user for the
 * desired action they want to take - getting their handicap,
 * calculating their handicap for a new course, or inputting their
 * handicap score from a course previously played.
 */
int average_handicap(void *data, int argc, char **argv, char **azColName){
    std::vector<double>* result = static_cast<std::vector<double>*>(data);

    // only one column returned
    result->push_back(argv[0] ? std::stod(argv[0]) : 100); 
}

double calculate(int score, int course_rating, double slope_rating){
    return (113 / slope_rating) * (score - course_rating);
}

int open_db(sqlite3 *db_in){
    int rc; 

    // Open database
    rc = sqlite3_open("var/handicap-calculator.sqlite3", &db_in);

    return rc; 
}

/**
 * Inputs a user entry into the local database for
 * persistent storage
 */
void input_scores(std::unique_ptr<DB_Entry> entry, sqlite3 *db){
    // calculate actual handicap for course
    double handicap = calculate(entry->get_score(), 
                            entry->get_course_rating(), entry->get_slope_rating()); 

    // Run query here
    string testing_q = 
        "INSERT INTO scores (course, score, course_rating, slope_rating, handicap) VALUES (" + 
        entry->get_course_name() + ", " + std::to_string(entry->get_score()) + ", " +
        std::to_string(entry->get_course_rating()) + ", " + std::to_string(entry->get_slope_rating()) +
        ", " + std::to_string(handicap) + ")"; 
    try{
        if (sqlite3_exec(db, testing_q.c_str(), callback, NULL, NULL)){
            throw std::runtime_error(std::string("Failed query ") + testing_q);
        }
    }
    catch (const std::exception &e){
        cout << e.what() << "\n";
        exit(1);
    }
}

/**
 * Returns the handicap to the user via std out
 */
void retrieve_handicap(){
    // Open the db
    sqlite3 *db;
    int rc = open_db(db);

    if(rc){
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
        return;
    }

    while(true){
        // Call to read the score inputted
        std::unique_ptr<DB_Entry> entry = read_score();
        input_scores(std::move(entry), db); 
    }
    // pull 20 most recent records from database
    string query = "SELECT handicap from scores ORDER BY score_id DESC LIMIT 20";

    std::vector<double> data; 
    try{
        if (sqlite3_exec(db, query.c_str(), average_handicap, &data, NULL)){
            throw std::runtime_error(std::string("Failed query ") + query);
        }
    }
    catch (const std::exception &e){
        cout << e.what() << "\n";
        exit(1);
    }

    sort(data.begin(), data.end());
    // only 8 best of out last 20 scores are used for handicap
    int added; 
    double total; 
    for(int i = 0; i < (8 || data.size()); ++i){
        total += data[i]; 
        added++;  
    } 

    cout << "\bYour current handicap is: " << (total / added) << '\n'; 

    sqlite3_close(db); 
}

/*
    This applicaiton calculates a users handicap from their scores
    listed in the database. If the user is new/wants to add scores,
    this application allows for that.
*/

int main(int argc, char *argv[]){
    // Determine Help functionality or Action
    // Help Menu
    if (argc != 1){
        cout << "Usage " << argv[0] << " This program will calculate a\n";
        cout << "users current handicap differential based off the 20 most\n";
        cout << "scores. Note, 20 scores are not required for this calculator\n";
        cout << "to function properly. This interactive tool allows users to \n" <<
            "store thier data for easier use later on.";
        exit(1);
    }
    retrieve_handicap(); 
}
