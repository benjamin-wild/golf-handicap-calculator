// Contains user(s) who have used the calculator

#include <unordered_map>
#include <deque>
#include "calculator.h"

class Users{
private:
	// relation from user to most recent courses played
	unordered_map<string, deque<Course>> users;

	// TODO - make a class/struct for specific user information/store in db
	string username; 
	int num_courses; 

public:
	// Default Ctor
	Users(); 

	string getUsername(); 
	void setUsername(string username); 
	string getPassword(); 
	void setPassword(string password); 
	/**
	 * Determines whether a user is a new user or has an existing account. 
	 * Confirms that their password matches to their username
	*/
	void login(); 

	/**
	 * Handling function which handles prompting the current user for the 
	 * desired action they want to take - getting their handicap, 
	 * calculating their handicap for a new course, or inputting their 
	 * handicap score from a course previously played. 
	*/
	void prompt_user();

	/**
	 * main function that orchestrates calculating handicaps for different 
	 * users. Reads its variables from the input file
	*/
	void read_score(); 
};