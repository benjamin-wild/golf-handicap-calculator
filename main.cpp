#include <iostream>
#include <string>
#include <sqlite3.h>

#include "calculate.h"

using std::cout; 
using std::string;

/**
 * main function that orchestrates calculating handicaps for different
 * users. Reads its variables from the input file
 */
void read_score(){
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
        if(course_name == "quit"){
            return; 
        }
        std::cin >> score >> slope_index >> course_rating; 
    }
    catch (std::exception &e){
        throw e.what();
    }

    // Store this in an object and return
}

/**
 * Handling function which handles prompting the current user for the
 * desired action they want to take - getting their handicap,
 * calculating their handicap for a new course, or inputting their
 * handicap score from a course previously played.
 */
void calcualte_differential(){
    // pull 20 most recent records from database
    // calculate the current handicap differential from them
}

/**
 * Inputs a user entry into the local database for
 * persistent storage
 */
void input_scores(){
    // attempt to connect to the database
    // input score into scores table if possible
}

/**
 * Returns the handicap to the user via std out
 */
void retrieve_handicap(){
    while(true){
        // Call to read the score inputted
        read_score();
    }
}

// Function used to print the data base
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

/*
    This applicaiton calculates a users handicap from their scores
    listed in the database. If the user is new/wants to add scores,
    this application allows for that.
*/

int main(int argc, char *argv[])
{
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
    // Connect to Database
    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc = 0;

    // Open database
    rc = sqlite3_open("var/handicap-calculator.sqlite3", &db);

    // Check to ensure database opened correctly
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
        return 0;
    } else {
        cout << "Opened database successfully\n";

        // Testing query
        string testing_q = "SELECT * FROM users;"; 
        cout << "Current State of Table 'users'\n"; 
        // Table should be populated already
        try{
            if(sqlite3_exec(db, testing_q.c_str(), callback, NULL, NULL)){
                throw std::runtime_error(std::string("Failed query ") + testing_q); 
            } 
        }
        catch(const std::exception &e) {
            cout << e.what() << "\n"; 
            exit(1); 
        }
        /*  Create thread to handle user input/program outputting, 
            thread to handle database accesses, and thread to handle
            any necessary computations. (not sure about the need of the last one) */

        sqlite3_close(db); 
    }
}
