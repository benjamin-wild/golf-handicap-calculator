#include <iostream>
#include <string>
#include <sqlite3.h>

#include "users.h"

using std::cout; 
using std::string;

/*  
    This applicaiton calculates a users handicap from their scores 
    listed in the database. If the user is new/wants to add scores, 
    this application allows for that. 
*/

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

//   Command Line Input 
//   <Executable> <Number of Threads> Input_File
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
        sqlite3_exec(db, testing_q.c_str(), callback, NULL, NULL); 

        /*  Create thread to handle user input/program outputting, 
            thread to handle database accesses, and thread to handle
            any necessary computations. (not sure about the need of the last one)*/

        sqlite3_close(db); 
    }
}
