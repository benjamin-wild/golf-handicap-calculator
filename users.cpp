#include "users.h"

/**
 * Handling function which handles prompting the current user for the
 * desired action they want to take - getting their handicap,
 * calculating their handicap for a new course, or inputting their
 * handicap score from a course previously played.
 */
void Calculate::retrieve_handicap(){
    // Call to read the score inputted
    read_score(); 
}

/**
 * main function that orchestrates calculating handicaps for different
 * users. Reads its variables from the input file
 */
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
        } catch(exception& e) {
            throw e.what(); 
        }
    }
}
