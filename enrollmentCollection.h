#ifndef ENROLLMENTCOLLECTION_H
#define ENROLLMENTCOLLECTION_H
#include <fstream>

#include <iostream>
#include <string> 
#include "enrollment.h"


using namespace std;

// contains list of all enrollments
class enrollmentCollection{
	public:
	enrollmentCollection();
	void addEnrollment(enrollment enroll);
	enrollment getEnrollment(int studentId, int courseId);
	void addGrade(int studentId, int courseId, double grade);
	void studentsInCourse(int courseId);
	void getAverage(int id);
	void move(ofstream& stream);
	bool check(int studentId, int courseId);
	
	private:
		int num;
		int count;
		// dynamic array or enrollments
		enrollment *enrolled;
		
	
};
	
#endif
