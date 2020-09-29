#pragma once
#include <vector>
#include <string>
using namespace std;

// GradedActivity class declaration

class GradedActivity {
    protected:
        char letter;
        double score;   // To hold the numeric score
        string name;
        static vector<GradedActivity*> objList; 


        void determineGrade() { 
            if (score > 89)
                letter = 'A';
            else if (score > 79)
                letter = 'B';
            else if (score > 69)
                letter = 'C';
            else if (score > 59)
                letter = 'D';
            else
                letter = 'F';
        }

    public:
        // Default constructor
        GradedActivity() {
            score = 0.0; letter = ' '; name = ' ';
        }

        // Constructor
        GradedActivity(double s) {
            score = s; name = "NULL (:";
        }

        GradedActivity(string n) {
            name = n; 
            score = 0.0; letter = ' ';
        }

        GradedActivity(string n, double s) {
            name = n; 
            score = s;
        }

        // Mutator function
        void setScore(double s) {
            score = s; determineGrade();
        }

        // Accessor functions
        double getScore() const { return score; }
        string getName() const { return name; }

        // virtual char getLetterGrade() const { return letter;  }
        char getLetterGrade() const { return letter; }

        static vector<GradedActivity*> getAllObjects(){
            return objList;
        }

        
};


//added vector of students 
//added identifyer for name to compile the list of grades
