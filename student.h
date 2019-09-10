#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string> 

using namespace std;
 
 
 // The student class which is used to store each student's information and different activities
class student{
	public:
			student();
			int getID();
			string getName();
			void setID(int Id);
			void setName(string Name);
			void setClassification(string Classification);
			string getClassification();
			int getClasses();
	private:
			// Student's information
			int ID;
			int num;
			string name;
			string classification;
			
	
};
#endif
