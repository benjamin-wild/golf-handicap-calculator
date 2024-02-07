// Contains user(s) who have used the calculator

#include <unordered_map>
#include <deque>
#include "calculator.h"

class Users{
private:
	// relation from user to most recent courses played
	unordered_map<string, deque<Course>> users;
	string username; 
	int num_courses; 

public:
	//main function that orchestrates calculating handicaps 
	//for different users. Reads its variables from the input
	//file 
	void read_users(); 
};