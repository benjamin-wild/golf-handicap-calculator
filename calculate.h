#include <queue>
#include <string>
#include <iostream>

using std::string;

class DB_Entry{
private:
    int score;
    int slope_index; 
    double course_rating;
    string course_name; 
public:
    DB_Entry(){
        course_name = ""; 
        course_rating = 0; 
        score = 0; 
        slope_index = 0; 
    }

    DB_Entry(string &course_name_in, double &course_rating_in, int score_in, int slope_index_in){
        course_name = course_name_in; 
        course_rating = course_rating_in; 
        score = score_in; 
        slope_index = slope_index_in; 
    }

    // sets the course name of a calculate object
    void set_course_name(string &course_name_in){ course_name = course_name_in; }

    string get_course_name(){ return course_name; }

    // sets the course rating of a calculate object
    void set_course_rating(double &course_rating_in){ course_rating = course_rating_in; }

    double get_course_rating(){ return course_rating; }

    // sets the score of a calculate object
    void set_score(int score_in){ score = score_in; }

    int get_score(){ return score; }

    // sets the course name of a calculate object
    void set_slope_index(int slope_index_in){ slope_index = slope_index_in; }

    int get_slope_rating(){ return slope_index; }
};