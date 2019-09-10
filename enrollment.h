#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <iostream>
#include <string> 
#include <fstream>
#include "studentCollection.h"
#include "courseCollection.h"
using namespace std;

// conatins information of all enrollments(i.e students that joined a class)
class enrollment{
	public:
			enrollment();
			int getEnrollmentID();
			void setEnrollmentID(int Id);
			int getStudentID();
			void setStudentID(int Id);
			int getCourseID();
			void setCourseID(int Id);
			int addGrade(int grade);
			string getLetterGrade(int index);
			int getGrade(int index);
			double getAverage();
			void addEnrollment(studentCollection students, courseCollection subjects);
			student getStudent();
			void moveGrades(ofstream& stream);
			
	private:
			int gradeCount; // remembers where the last index of the grade was
			double average;
			int enrollmentID;
			int studentID;
			int courseID;
			int grades[10]; // stores number grades
			string letterGrade[10]; // stores letter grades
			student person;
			course subject;
			
			
	
};
#endif
