/*
	Name: Vishnu Kommineni
	Email: VishnuKommineni@my.unt.edu
	About: This program is the coding part of an example grade book. This program has several functions such as enrolling students into course and getting their information like their grades and averages.
*/


#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>


#include "enrollmentCollection.h"
using namespace std;

int main ()
{
	
		cout <<"+------------------------------------------------------------+"<<endl; // printing out my info
        cout <<"|              Computer Science and Engineering              |"<<endl;
        cout <<"|               CSCE 1040 - Computer Science II               |"<<endl;
        cout <<"|      Vishnu Kommineni vk0175  VishnuKommineni@my.unt.edu   |"<<endl;
        cout <<"+------------------------------------------------------------+"<<endl;


	
	courseCollection subjects;
	studentCollection students;
	enrollmentCollection enroll;
	
	bool endProgram = false;
	
	while (endProgram == false)
	{
		// intro
		cout <<"1. Add a new course\n2. Add a new student\n3. Add a student to a course (add enrollment)\n4. Add grades for a student in a course\n5. Print a list of all grades for a student in a course\n6. Print a list of all students in a course\n7. Compute the average for a student in a course\n8. Print a list of all courses\n9. Print a list of all students\n10. Compute the average for a course\n11. Store Grade book (to a disk file)\n12. Load Grade book (from a disk file)\n13. Close Program"<<endl;
		cout<<"Choose one of the options (enter the option number)"<<endl;
		int option;
		cin >> option;
		
		// option choices
		if(option == 1)
		{
			int id;
			string name;
			string location;
			string meetTime;
			course temp; // temp object to later be added in actual collection
			
			//getting data and saving it in the objects
			cout<<"Enter the course ID"<<endl;
			cin >> id;
			cout<<"Enter the course name"<<endl;
			cin >> name;
			cout<<"Enter the course's meet location"<<endl;
			cin >> location;
			cout<<"Enter the course's meet time "<<endl;
			cin >> meetTime;
			temp.setID(id);
			temp.setName(name);
			temp.setLocation(location);
			temp.setMeetingTime(meetTime);
			
			//adding object to collection
			subjects.addCourse(temp); 
			
		}
		else if(option == 2)
		{
			int id;
			string name;
			string classification;
			student temp; // temp object to later be added in actual collection
			
			cout<<"Enter the student's ID"<<endl;
			cin >> id;
			cout<<"Enter the student's name"<<endl;
			cin >> name;
			cout<<"Enter the student's classification"<<endl;
			cin >> classification;
			temp.setID(id);
			temp.setName(name);
			temp.setClassification(classification);
			//adding object to collection
			students.addStudent(temp); 
		}
		else if(option== 3)
		{
			int courseId;
			int studentId;
			int enrollmentId;
			enrollment enroller; // temp object to later be added in actual collection
			
			//getting data and saving it in the objects
			cout<<"Enter the enrollment ID"<<endl;
			cin >> enrollmentId;
			cout<<"Enter the student's ID"<<endl;
			cin >> studentId;
			cout<<"Enter the course ID"<<endl;
			cin >> courseId;
			enroller.setStudentID(studentId);
			enroller.setCourseID(courseId);
			enroller.setEnrollmentID(enrollmentId);
			enroller.addEnrollment(students, subjects);
			bool temp =enroll.check(studentId,courseId);
			// adding object only if it is eligibile 
			if(temp == true){
			//adding object to collection
			enroll.addEnrollment(enroller);	
			}
			
		}
		else if(option== 4)
		{
			int studentId;
			int courseId;
			double grade;
			bool quit = false;
			int num =0;
			
			//getting data and saving it in the objects
			cout<<"Enter the student's ID"<<endl;
			cin >> studentId;
			cout<<"Enter the course ID"<<endl;
			cin >> courseId;
			
			while(quit == false && num !=10){
			cout<<"Enter the grade"<<endl;
			cin >> grade;
			enroll.addGrade(studentId, courseId, grade);
			char c;
			cout <<"Do you want to enter another grade (y or n)"<<endl;
			cin >> c;
			// adding grades 
			if(c == 'n')
			{
				quit = true;
			}
			num++;
			}
			
		}
		else if(option== 5)
		{
			int studentId;
			int courseId;
			enrollment temp; // temp object to later be added in actual collection
			
			//getting data and saving it in the objects
			cout<<"Enter the student's ID"<<endl;
			cin >> studentId;
			cout<<"Enter the course ID"<<endl;
			cin >> courseId;
			temp = enroll.getEnrollment(studentId,courseId);
			cout <<"Grades :"<<endl; 
			for(int i =0; i < 10; i++)
			{
				double num = temp.getGrade(i);
				string let = temp.getLetterGrade(i);
				
				if(num != -1)
				{
					printf( "%.2f", num);
					cout <<"	"<<let<<endl;
					
					
				}
				else{
					break;
				}
			}
			
		}
		else if(option== 6)
		{
			int courseId;
			cout<<"Enter the course ID"<<endl;
			cin >> courseId;
			enroll.studentsInCourse(courseId);
		}
		else if(option== 7)
		{
			int studentId;
			int courseId;
			
			//getting data and saving it in the objects
			cout<<"Enter the student's ID"<<endl;
			cin >> studentId;
			cout<<"Enter the course ID"<<endl;
			cin >> courseId;
			
			enrollment temp = enroll.getEnrollment(studentId,courseId);
			cout <<"Stduent average: " <<temp.getAverage()<<endl;
		}
		else if(option== 8)
		{
			//getting all courses
			subjects.allCourses();
		}
		else if(option== 9)
		{
			//getting all students
			students.allStudents();
		}
		else if(option== 10)
		{
			int courseId;
			//getting data and saving it in the variable
			cout<<"Enter the course ID"<<endl;
			cin >> courseId;
			enroll.getAverage(courseId);
		}
		else if(option== 11)
		{	
			//creating output stream to write to a file
			ofstream out_s;
			char fileName[30];
			cout << "Enter the name of the file that you would like the export the data to"<<endl;
			cin >> fileName;
			// open and checking connection
			out_s.open(fileName);
			
			if(out_s.fail())
			{
				cout << "Output file opening failed. \n";
				exit(EXIT_FAILURE);
			}
			// writing to the file								
			students.move(out_s);
			subjects.move(out_s);
			enroll.move(out_s);
			out_s << "-1"<<endl;
		}
		else if(option== 12)
		{
			//creating input stream
			ifstream in_s;
			
			cout << "Enter the file name that you would like to export the data from"<<endl;
			char input_file[25];
			cin >> input_file;
			
			
			in_s.open(input_file);
			//  checking if the connection failed or not
			if(in_s.fail())
			{
				cout << "Input file opening failed. \n";
				exit(EXIT_FAILURE);
			}
			
			// getting 
			string s;
			in_s >> s;
			// reading information for students
			while(s != "CourseList"){
				int id;
				string name;
				string classification;
				student temp;
			
					in_s >> name;
				if(name == "CourseList")
				{
					break;
				}
				in_s >> id;
				in_s >> classification;
				temp.setID(id);
				temp.setName(name);
				temp.setClassification(classification);
				students.addStudent(temp); 
			}
			

			// reading information for courses
			while(s != "enrollmentList"){
				int id;
				string name;
				string location;
				string meetTime;
				course temp;		
				in_s >> name;
				if(name == "enrollmentList")
				{
					break;
				}
				in_s >> id;
				in_s >> location;
				in_s >> meetTime;
				temp.setID(id);
				temp.setName(name);
				temp.setLocation(location);
				temp.setMeetingTime(meetTime);
				subjects.addCourse(temp); 
				}
			cout << "<<<<here>>>>>>"<<endl;
			// reading in information for enrollment
			while(!in_s.eof())
			{
				int courseId;
				int studentId;
				int enrollmentId;
				enrollment enroller;
			
				in_s >> enrollmentId;
				if(enrollmentId == -1)
				{
					break;
				}
				in_s >> studentId;
				in_s >> courseId;
				
				cout <<enrollmentId<<endl;
				cout << studentId<<endl;
				cout <<courseId<<endl;
				
				enroller.setStudentID(studentId);
				enroller.setCourseID(courseId);
				enroller.setEnrollmentID(enrollmentId);
				enroller.addEnrollment(students, subjects);
				bool temp =enroll.check(studentId,courseId);
				
				if(temp == true){
			
					enroll.addEnrollment(enroller);
				}
				
				int grade;
				bool quit = false;
			
				while(quit == false){
					in_s >> grade;
					enroll.addGrade(studentId, courseId, grade);
					char c;
					in_s>> c;
					
					if(c == 'n' || grade == -1)
					{
						quit = true;
					}
			
				}
				
			}
			
		}
		else if(option== 13)
		{
			break;
		}
		
	
	}
}