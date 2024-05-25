#include "users.h"

/**
 * Determines whether a user is a new user or has an existing account.
 * Confirms that their password matches to their username
 */
void Users::login(){

}

/**
 * Handling function which handles prompting the current user for the
 * desired action they want to take - getting their handicap,
 * calculating their handicap for a new course, or inputting their
 * handicap score from a course previously played.
 */
void Users::prompt_user(){
    while(true){
        string action; 
        std::cout << "Please select an action: Input Score | Calculate Handicap | Calculate Course Handicap\n"; 
        std::cin >> action;
    }
}

/**
 * main function that orchestrates calculating handicaps for different
 * users. Reads its variables from the input file
 */
void Users::read_score(){
    //read in user name and number of courses listed
    std::cin >> username >> num_courses; 
    string course_name; 
    double score, course_rating, course_slope; 

    //read in values associtated with each 
    for(int i = 0; i < num_courses; ++i){
        std::cin >> course_name >> score >> course_rating >> course_slope;
        std::cout << course_name << score << course_rating << course_slope;  
    }
}
