#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H
#include <fstream>

#include <iostream>
#include <string> 
#include "student.h"
using namespace std;

// Conatins information of all the students 
class studentCollection{
	public:
	// functions to determine the students or individual student's stuff
	studentCollection();
	void addStudent(student person);
	student getStudent(int ID);
	void allStudents();
	void move(ofstream& stream);
	private: 
		int num;
		int count;
		// dynamic array to contain the student objects
		student *people;
	
};
	
#endif
