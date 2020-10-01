#pragma once
#include <vector>
#include <string>
using namespace std;

// Student class declaration

class Student {
    private:
        char letter;
        double GPA;   // To hold the numeric score
        string name;


        

    public:
        // Default constructor
        Student() {
            GPA = 0.0; name = ' ';
        }


        Student(string n, double g) {
            name = n; 
            GPA = g;
        }


        // Accessor functions
        double getGPA() const { return GPA; }
        string getName()  { return name; }




        
};


//added vector of students 
//added identifyer for name to compile the list of grades
