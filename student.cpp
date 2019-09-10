#include <iostream>
#include <string> 
#include "student.h"
using namespace std;

// Initilizes the private variables
student::student()
{
	ID =0;
	name = "none";
}
// following programs gets or sets the value of teh private variables
int student::getID()
{
	return ID;
}

string student::getName()
{
	return name;
}

void student::setID(int Id)
{
	ID = Id;
	num =0;
}

void student::setName(string Name)
{
	name = Name;
}

void student::setClassification(string Classification)
{
	classification = Classification;
}

string student::getClassification(){
	
	return classification;
}

int student::getClasses()
{
		return num;
}


