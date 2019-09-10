#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string> 
using namespace std;

//conatins information about a course and its functions
class course{
public:
			course();
			int getID();
			void setID(int Id);
			string getName();
			void setName(string Name);
			string getLocation();
			void setLocation(string Name);
			string getMeetingTime();
			void setMeetingTime(string Name);
			bool check();
			int getStudents();
	private:
			int ID;
			string name;
			string location;
			string meetingTime;
			int students;
	
};
	
#endif
