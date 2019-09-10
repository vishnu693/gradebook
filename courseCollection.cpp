#include <iostream>
#include <string> 
#include "courseCollection.h"
using namespace std;


courseCollection::courseCollection()
{
	num =1;
	count =0;
	courses = new course[num]; 
	
}

void courseCollection::addCourse(course subject)
{
	if(count == num)
	{
		course *courses1;
		courses1 = new course[num]; 
		for(int i =0; i< num; i++)
		{
			
			courses1[i].setID(courses[i].getID());
			courses1[i].setName(courses[i].getName());
			// add the other fields later 
		}		
		delete [] courses;
		num =num*2;
		
		// double the size of the array and copy informatin in old array
		courses = new course[num]; 
		for(int i =0; i< num/2; i++)
		{
			courses[i].setID(courses1[i].getID());
			courses[i].setName(courses1[i].getName());
		}		
		delete [] courses1;
	}
	courses[count] = subject;
	count++;
	
	
}
	//get course based on id
	course courseCollection::getCourse(int ID)
	{
			for(int i =0; i < count; i++)
			{
				if(courses[i].getID() == ID)
				{
					return courses[i];
				}
			}
			cout << "No course with ID "<< ID << " exists"<<endl;
	} 
	
	// all courses
	void courseCollection::allCourses()
	{
		cout << "All Courses:"<<endl;
		for(int i =0; i < count; i++)
			{
				cout << courses[i].getName() << "	"<< courses[i].getID()<<endl;
			}
	}
	
	// export all courses to a file
	void courseCollection::move(ofstream& stream)
	{
		stream << "CourseList"<<endl;
		for(int i =0; i < count; i++)
			{
				stream << courses[i].getName() << " "<< courses[i].getID() << " "<< courses[i].getLocation() <<" "<< courses[i].getMeetingTime()<<endl;
			}
	}
	
	