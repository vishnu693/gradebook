#include <iostream>
#include <string> 
#include "enrollmentCollection.h"
#include <stdio.h>
using namespace std;


enrollmentCollection::enrollmentCollection()
{
	num =1;
	count =0;
	// creates the dynamioc array with initial length
	enrolled = new enrollment[num]; 
	
	
}

void enrollmentCollection::addEnrollment(enrollment enroll)
{
	if(count == num)
	{
		//temperory arry and copy the original information
		enrollment *enrollment1;
		enrollment1 = new enrollment[num]; 
		for(int i =0; i< num; i++)
		{
			
			enrollment1[i]=enrolled[i];
		}		
		delete [] enrolled;
		num =num*2;
		
		// double the size of the array and copy informatin in old array
		enrolled = new enrollment[num]; 
		for(int i =0; i< num/2; i++)
		{
			enrolled[i]=enrollment1[i];
		}	
		delete [] enrollment1;
	}
	enrolled[count] = enroll;
	count++;
	
	
}
	// gets enrollment object based on student and enrollment id
	enrollment enrollmentCollection::getEnrollment(int studentId, int courseId)
	{
			for(int i =0; i < count; i++)
			{
				if(enrolled[i].getStudentID() == studentId && enrolled[i].getCourseID() == courseId)
				{
					return enrolled[i];
				}
			}
			
	} 
	
	// add grades for a student in a class
	void enrollmentCollection::addGrade(int studentId, int courseId, double grade)
	{
		for(int i =0; i < count; i++)
			{
				if(enrolled[i].getStudentID() == studentId && enrolled[i].getCourseID() == courseId)
				{
					enrolled[i].addGrade(grade);
					break;
				}
			}
			
	}
	
	//Gets students enrolled in the course
	void enrollmentCollection::studentsInCourse(int courseId)
	{
			for(int i =0; i < count; i++)
			{
				if(enrolled[i].getCourseID() == courseId)
				{
					student temp;
					temp = enrolled[i].getStudent();
					cout << temp.getID() << "	" << temp.getName()<<endl;
				}
			}
	}
	
	// gets the average of a course 
	void enrollmentCollection::getAverage(int courseId)
	{
		double average;
		int studentCount =0;
			for(int i =0; i < count; i++)
			{
				if(enrolled[i].getCourseID() == courseId)
				{
					student temp;
					temp  = enrolled[i].getStudent();
					cout << temp.getName() <<"	"<<enrolled[i].getAverage()<<endl;
					average =+ enrolled[i].getAverage();
					studentCount++;
					
				}
			}
			
			average = average/studentCount;
			printf("The average is %.2f", average);
	}
	
	// exports enrollment to the disk
	void enrollmentCollection::move(ofstream& stream)
	{
		stream << "enrollmentList"<<endl;
		for(int i =0; i< count; i++)
		{
			
			stream << enrolled[i].getEnrollmentID() << " " << enrolled[i].getStudentID() << " " << enrolled[i].getCourseID() << " ";
			enrolled[i].moveGrades(stream);
		}
	}
	
	bool enrollmentCollection::check(int studentId, int courseId)
	{
		for(int i =0; i < count; i++)
		{
				if(enrolled[i].getStudentID() == studentId && enrolled[i].getCourseID() == courseId)
				{
					cout <<"Already enrolled in this class"<<endl;
					return false;
				}
		}
		int studCount;
		for(int i =0; i < count; i++)
		{
				if(enrolled[i].getStudentID() == studentId )
				{
					studCount++;
				}
				if(studCount == 5)
				{
					cout <<"Student is already enrolled in 5 classes"<<endl;
					return false;
				}
		}
		int clasCount;
		for(int i =0; i < count; i++)
		{
				if( enrolled[i].getCourseID() == courseId)
				{
					clasCount++;
					
				}
				if(clasCount ==48)
				{
					cout <<"This class already has 48 students"<<endl;
					return false;
				}
		}
		return true;
	}