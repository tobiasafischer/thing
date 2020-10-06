//Student Graduation Implementation Tobias Fischer
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

		name = names[i];
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


void top(vector<Student> &student){
	int size = student.size();
	int sizeChoice;

	cout << "How many students: ";
	cin >> sizeChoice;
	
	if (sizeChoice > size){
		for(int i = 0; i < size; i++){
			cout << i+1 << "\t" <<student[i].getName() << "\t\t" <<  student[i].getGPA() << "\n";
		}
	}
	else{
		for(int i = 0; i < sizeChoice; i++){
			cout << i+1 << "\t" <<student[i].getName() << "\t\t" <<  student[i].getGPA() << "\n";
		}
	}
}

void bottom(vector<Student> &student){
	int size = student.size();
	int sizeChoice;

	cout << "How many students: ";
	cin >> sizeChoice;
	
	if (sizeChoice > size){
		for(int i = size-1; i >= 0; i--){
			cout << i+1 << "\t" <<student[i].getName() << "\t\t" <<  student[i].getGPA() << "\n";
		}
	}
	else{
		for(int i = size-1; i >= size-sizeChoice; i--){
			cout << i+1 << "\t" <<student[i].getName() << "\t\t" <<  student[i].getGPA() << "\n";
		}
	}

}

void average(vector<Student> &student){
	double total = 0;
	int count = 0;
	for(int i = 0; i < student.size(); i++){
		total+= student[i].getGPA();
		count++;
	}
	cout << "The average GPA of " << student.size() << " students is: " << total/count << endl;
}

void by_name(vector<Student> &student){
	string name;
	double total;
	int count = 0;
	bool isPresent = false;
	cout << "What is the name: ";
	cin >> name;

	for(int i = 0; i < student.size(); i++){
		if(student[i].getName() == name){
			isPresent = true;
			total += student[i].getGPA();
			cout << i+1 << "\t" <<student[i].getName() << "\t\t" <<  student[i].getGPA() << "\n";
			count ++;
		}
	}
	if( isPresent )
		cout << "The average GPA of students with the name of " << name << " is " << total / count << endl;
	else
		cout << "There is no student by the name of " << name;
	

}

void failing(vector<Student> &student){
	bool pass = true;
	int count = 0;
	double gpa = 0;
	for(int i = 0; i < student.size(); i++){
		
		if(student[i].getGPA() < 2.0 ){
			gpa += student[i].getGPA();
			count++;
			pass = false;
			cout << i+1 << "\t" <<student[i].getName() << "\t\t" <<  student[i].getGPA() << "\n";
			}
	}
	if (pass)
		cout << "There are no students failing." << endl;
	else
		cout << "The average failing grade is " <<  gpa/count <<".\n";		


}

int howManyStudents(){
	int num;
	cout << "How many students would you like to create: ";
	cin >> num;
	return num;
}

int check(string s){
	if (s == "top")
		return 1;
	else if(s == "bottom")
		return 2;
	else if(s == "average")
		return 3;
	else if(s == "by_name")
		return 4;
	else if(s == "failing")
		return 5;
	else if(s == "exit")
		return 6;
	return 0;
}

int main() { 

	int num = howManyStudents();
	vector<string> names = getNames(num); //giving all of our names
	vector<Student> lsOfStudent = {}; //vector of students
	cout << "\n\n Calculating " << num << " students...\n\n";

	makeStudent( lsOfStudent,names); //populates our vector of students
	sortScore(lsOfStudent); //sorting student on grade
	

	bool b = true;
	while(b){
		string s;
		cout << "\ntop \t bottom \t average \t by_name \t failing\n\n";
		cout << "What choice: ";
		cin >> s;

		int c = check(s);

		switch(c){
			case 1:
				top(lsOfStudent);
				break;
			case 2:
				bottom(lsOfStudent);
				break;
			case 3:
				average(lsOfStudent);
				break;
			case 4:
				by_name(lsOfStudent);
				break;
			case 5:
				failing(lsOfStudent);
				break;
			case 6:
				b = false;
				break;
			

		}
		
	}
	return 0;	
}