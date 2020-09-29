#include <iostream>
#include <iomanip>
#include "CurvedActivity.h"
#include "GradedActivity.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <Windows.h>

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

	
	for (int i = 0; i < num; i++){
		randn = (rand() % 1000);
		name.push_back(bigNames.at(randn));
	}
	return name;

}
GradedActivity* makeStudent(vector<string> names, int num, GradedActivity *students){
	

	double randn = (rand() % 100) + 1;
	string name = "";
	for(int i = 0; i < num; i++){
    
		name = names.at(i);
		students[i] = GradedActivity(name, randn);		
		
    }
	delete[] students;
	return students;
}


GradedActivity* sortScore(GradedActivity *student, int num){

	GradedActivity temp;
	int i, j, min;
	for (i = 0; i < num - 1; i++) {
		min = i;
		for (j = i + 1; j < num; j++)
		if (student[j].getScore() < student[min].getScore())
		min = j;
		temp = student[i];
		student[i] = student[min];
		student[min] = temp;
	}
	
	return student;

}




int main() { 
	double numericScore;  // To hold the numeric score
	double percentage;    // To hold curve percentage
    CurvedActivity exam;  // Define a CurvedActivity object.
	double score;
	int num = 10;
	vector<string> names = getNames(num);
	
	
	GradedActivity *student = new GradedActivity[num];
	
	makeStudent(names, num, student);
	
	
	student = sortScore(student,num);
	GradedActivity *obj;

	for (int i = 0; i < num; i++){
		
		cout << i + 1 << " " << student[i].getName() << "   " << student[i].getScore() << endl;
		Sleep(1);
		//obj = NULL;
	}


	return 0;
}
