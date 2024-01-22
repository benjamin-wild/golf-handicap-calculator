// This application calculates and stores a handicap per user

#include <iostream>
#include <string>
#include "users.h"

int main(int argc, char *argv[])
{
    // Determine Help functionality or Action
    // Help Menu
    if (argc != 1){
        std::cout << "Usage " << argv[0] << " < in-txt-file\n";
        std::cout << "In txt file should contain #users followed by user name\n";
        std::cout << "and number of courses for each respective user\n";
        std::cout << "Each line following must contain course played\n";
        std::cout << "at, personal score, course rating and slope\n";
        std::cout << "rating with spaces in between. This program will calculate a\n";
        std::cout << "users current handicap differential based off the 20 most\n";
        std::cout << "scores. Note, 20 scores are not required for this calculator\n";
        std::cout << "to function properly\n";
        exit(1);
    }
    // Proper input
    else if (argc == 1){
        // read command line things here
        Users users;
    }
}
