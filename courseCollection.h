#ifndef COURSECOLLECTION_H
#define COURSECOLLECTION_H

#include <fstream>
#include <iostream>
#include <string> 
#include "course.h"
using namespace std;

//conatisn the collection of the courses
class courseCollection{
	public: 
	courseCollection();
	void addCourse(course subject);
	course getCourse(int ID);
	void allCourses();
	void move(ofstream& stream);
	private:
		int num;
		int count;
		// dynamic array to contain the class objects
		course *courses;
	
};
	
#endif
