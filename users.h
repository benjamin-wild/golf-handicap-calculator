// Contains user(s) who have used the calculator
#include <unordered_map>
#include <deque>
#include <string>
#include <iostream>

using std::string;

class Calculate{
private:
	// relation from user to most recent courses played
	string username;
	string password; 
	int num_courses; 

public:
	/**
	 * Returns the handicap to the user via std out
	*/
	void retrieve_handicap(); 

	/**
	 * Handling function which handles prompting the current user for the 
	 * desired action they want to take - getting their handicap, 
	 * calculating their handicap for a new course, or inputting their 
	 * handicap score from a course previously played. 
	*/
	void calcualte_differential();

	/**
	 * Inputs a user entry into the local database for 
	 * persistent storage
	*/
	void input_scores(); 

	/**
	 * main function that orchestrates calculating handicaps for different 
	 * users. Reads its variables from the input file
	*/
	void read_score(); 
};