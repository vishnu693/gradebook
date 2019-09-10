#include <iostream>
#include <string> 
#include "course.h"
using namespace std;

// initilize the variables
course::course()
{
	ID =0;
	name = "none";
	location= "none";
	meetingTime= "none";
	students=0;
}

// get or set values for variables
int course::getID()
{
	return ID;
}

void course::setID(int Id)
{ID = Id;
}
string course::getName()
{
	return name;
}
void course::setName(string Name){
	name = Name;
}
string course::getLocation(){
	return location;
}
void course::setLocation(string Name){
	location = Name;
}
string course::getMeetingTime(){
	return meetingTime;
}
void course::setMeetingTime(string Name){
	meetingTime = Name;
}

// chech eligibility
bool course::check()
{
	if(students < 48 )
	{
		students++;
		return true;
	}
	return false;
}
int course::getStudents()
{
	return students;
}