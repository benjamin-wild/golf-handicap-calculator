#include "users.h"

void Calculate::retrieve_handicap(){
    // Call to read the score inputted
    read_score(); 
}

void Calculate::input_scores(){
    // attempt to connect to the database
    //input score into scores table if possible
}

void Calculate::read_score(){
    // temp variables 
    string course_name; 
    double slope_index, course_rating; 
    int score; 

    while(true){
        // Give the correct format for inputting a score
        std::cout << "Please enter a score in format:\n<Score> <Slope Index> <Course Rating> <Course Name>\n"; 

        // Read in the associated values
        try{
            std::cin >> score >> slope_index >> course_rating >> course_name; 
        } catch(std::exception& e) {
            throw e.what(); 
        }

        // input this course into the database
        

        // calculate the new handicap differential
    }
}
