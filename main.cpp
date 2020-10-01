#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <algorithm>
#include <tgmath.h>

#include "Student.h"

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

int determineGrade(double score) { 
    int letter;
	if (score > 89)
        letter = 4;
    else if (score > 79)
        letter = 3;
    else if (score > 69)
        letter = 2;
    else if (score > 59)
        letter = 1;
    else
	    letter = 0;
	return letter;
}

double getAvg(){
	//amt credits to graduate HS
	//in real application of database on the inplementation we would be able to use double
	//in this case lets assume they are rounded

	double randn; double total = 0;
	int count=0;

	for(int i = 0; i < 22; i++){

		//make it so its higher % for students to be > 60%
		if(i % 5 == 0)
			randn = rand() % 100 + 1;
		else 
			randn = rand() % 100 + 60;
		total += determineGrade(randn);

		
		count++;
	}
	
	return total/count;
}


void makeStudent(vector<Student> &lsOfStudent, vector<string> names){

	string name;
	double randn;
	int num = names.size();
	for(int i = 0; i < num; i++){
		randn =  ceil(getAvg() * 100.0) / 100.0;

		name = names.at(i);
		lsOfStudent.push_back(Student(name, randn));		
		
    }

}




//sort
bool compareScore(const Student &a, const Student& b)
{
    return (a.getGPA() > b.getGPA());
}

//descending selection sort of students by grade
void sortScore(vector<Student> &lsOfStudent)
{
    sort(lsOfStudent.begin(), lsOfStudent.end(), compareScore);
}

//formats and prints the students
void print(vector<Student> &lsOfStudent){
	
	string name;
	double scores, gpa;
	char grade;
	int place = 1;
	
	//s is student withint
	//\t
	for (Student &s : lsOfStudent){
		
		name = s.getName();
		gpa = s.getGPA();
		
		cout << setw(3) <<
                place  << "\t"   << setw(20) << 
                name   << "\t"   << 
                gpa << "\t\t" << endl;

		place++;
	}
}

int main() { 

	int num = 1'000;
	vector<string> names = getNames(num); //giving all of our names
	vector<Student> lsOfStudent = {}; //vector of students

	makeStudent( lsOfStudent,names); //populates our vector of students
	sortScore(lsOfStudent); //sorting student on grade
			
	print(lsOfStudent);
	return 0;
	
}