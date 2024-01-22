#include "users.h"

// main function that orchestrates calculating handicaps
// for different users. Reads its variables from the input
// file
void Users::read_users(){
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
