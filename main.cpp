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



vector<string> getNames(int num){
	string str;
	bool status;
	int randn;
	vector<string> name = {};
	vector<string> bigNames = {};

	ifstream filein("Names.txt");

    for (string line; getline(filein, line); )
    {
        bigNames.push_back(line);
    }

	srand(time(NULL));
	for (int i = 0; i < num; i++){
		randn = rand() % 1000 ;
		name.push_back(bigNames.at(randn));
	}
	filein.close();
	return name;

}

void makeStudent(vector<string> names, int num, vector<GradedActivity> &students){
	double randn  = rand() % 100 + 1;
	string name = "";
	for(int i = 0; i < num; i++){
		randn = rand() % 100 + 1;
		name = names.at(i);
		students.push_back(GradedActivity(name, randn));		
		
    }
	
}





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


int main() { 
	double numericScore;  // To hold the numeric score
	double percentage;    // To hold curve percentage
    GradedActivity exam;  // Define a GradedActivity object.
	double score;
	int num = 10;
	vector<string> names = getNames(num);
	
	vector<GradedActivity> student = {};
	
	
	makeStudent(names, num, student);

	sortScore(student,num);
		

	string name;
	double scores;
	char grade;
	int place = 1;
	for (GradedActivity &s : student){
		
		name = s.getName().c_str();
		scores = s.getScore();
		grade = s.getLetterGrade();
		
		cout << place << setw(7) << "" << setw(6) << 
				name << "" << setw(9) << 
				scores << "" << setw(6) << 
				grade << endl;





		place++;
	}


	return 0;
}
