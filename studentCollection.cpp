#include <iostream>
#include <string> 

#include "studentCollection.h"

using namespace std;

studentCollection::studentCollection()
{
	num =1;
	count =0;
	// creates the dynamioc array with initial length
	people = new student[num]; 
	
}

void studentCollection::addStudent(student person) 
{
	// If array is full continue changing array size
	if(count == num)
	{
		//temperory arry and copy the original information
		student *people1;
		people1 = new student[num]; 
		for(int i =0; i< num; i++)
		{
			
			people1[i] = people[i];
		}		
		delete [] people;
		
		num =num*2;
		
		// double the size of the array and copy informatin in old array
		people = new student[num]; 
		for(int i =0; i< ((num/2)); i++)
		{
			people[i] = people1[i];
		}		
		delete [] people1;
	}
	people[count] = person;
	count++;
	}
	
	//get a student based on id
	student studentCollection::getStudent(int ID)
	{
			for(int i =0; i < count; i++)
			{
				if(people[i].getID() == ID){

					return people[i];
				}
			}
			cout << "No student with ID "<< ID << " exists"<<endl;
	} 
	
	//print all students
void studentCollection::allStudents()
{
	cout << "All Students:"<<endl;
	cout <<"Name	     ID"<<endl;
		for(int i =0; i < count; i++)
			{
				cout << people[i].getName() << "	"<< people[i].getID()<<endl;
			}
}

// export studenst to disk
void studentCollection::move(ofstream& stream)
{
	stream<<"StudentsList"<<endl;
	for(int i =0; i < count; i++)
	{
		stream<< people[i].getName() << " "<< people[i].getID()<< " "<<people[i].getClassification()<<endl;
	} 
}