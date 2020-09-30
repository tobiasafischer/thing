#include <iostream>
#include <iomanip>
#include "GradedActivity.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>

using namespace std;


//this returns a vector of strings which
//intake "num" of amount of names from a list of 1000 common names
//and give the amount of names desired for amount of students
vector<string> getNames(int num){
	vector<string> name;
	vector<string> lsName;
	string line;
	int numLines, randnum;
	srand(time(0));
	ifstream filein("Names.txt");
	
	//getting the count of file + all lines
	numLines = 0;

	while(getline(filein,line)) {
		numLines++;
		lsName.push_back(line);
	}

	//storing "num" amount of random names from ls of names 
	for (int i = 0; i < num; i++){
		
		randnum = rand() % numLines;
		name.push_back(lsName[randnum]);

	}
	filein.close();
	return name;

}

//this makes "num" amount of students with random names, score
//it stores all of the students in a student vector
void makeStudent(vector<string> names, int num, vector<GradedActivity> &students){	
	double randn;
	string name = "";

	//names the students with the 1 of the names and a random 
	//double as a score
	//stores student in vector of student
	for(int i = 0; i < num; i++){
		
		randn = rand() % 100 + 1;
		name = names.at(i);
		students.push_back(GradedActivity(name, randn));		
		
    }
	
}



//descending selection sort of students by grade
void sortScore(vector<GradedActivity> &student, int num){
	
	for (int j = 0; j < num - 1; ++j) {

		int min = j;

		for (int i = j+1; i < num; ++i) {

			if (student.at(min).getScore() < student.at(i).getScore()) {
				min = i;
			}

		}
		if (min != j)
			swap(student.at(j), student.at(min));

	}

}

//formats and prints the students
void print(vector<GradedActivity> &student){
	
	string name;
	double scores;
	char grade;
	int place = 1;
	
	//s is student withint
	//\t
	for (GradedActivity &s : student){
		
		name = s.getName();
		scores = s.getScore();
		grade = s.getLetterGrade();
		
		cout << "\t\t" <<
				place  << "\t"   << 
				name   << "\t\t\t" << 
				scores << "\t"   << 
				grade  << endl;

		place++;
	}
}

int main() { 
	int num = 20;
	vector<string> names = getNames(num); //giving all of our names
	vector<GradedActivity> student = {}; //vector of students

	makeStudent(names, num, student); //populates our vector of students
	sortScore(student,num); //sorting student on grade
		

	print(student);

	return 0;
}