#include <iostream>
#include <string> 
#include "enrollment.h"

using namespace std;
			//initilizes all variables
			enrollment::enrollment(){
				gradeCount =0;
			enrollmentID=0;
			studentID=0;
			courseID=0;
			average =0;
			for(int i; i <10; i++)
			{
				grades[i] =0;
				letterGrade[i] = "";
			}
			}
			// set and get for the values of variables
			int enrollment::getEnrollmentID(){
				return enrollmentID;
			}
			
			void enrollment::setEnrollmentID(int Id){
				enrollmentID = Id;
			}
			
			int enrollment::getStudentID(){
				return studentID;
			}
			
			void enrollment::setStudentID(int Id){
				studentID = Id;
			}
			
			int enrollment::getCourseID(){
				return courseID;
			}
			
			void enrollment::setCourseID(int Id){
				courseID = Id;
			}
			
			// Add grades for a student in a course and set letter grade
			int enrollment::addGrade(int grade){
				grades[gradeCount] = grade;
				if(grade >= 90)
				{
					letterGrade[gradeCount] = "A";
				}
				else if(grade >= 80)
				{
					letterGrade[gradeCount] = "B";
				}
				else if(grade >= 70)
				{
					letterGrade[gradeCount] = "C";
				}
				else if(grade >= 60)
				{
					letterGrade[gradeCount] = "D";
				}
				else{
					letterGrade[gradeCount] = "F";
				}
				
				gradeCount++; // change the index of the grade left off at 
			}
			
			string enrollment::getLetterGrade(int index){
				if(index <  gradeCount){
				return letterGrade[index];
				}
			}
			
			int enrollment::getGrade(int index){
				if(index < gradeCount){
				return grades[index];
				}
				return -1; // indicates that end of the array
			}
			
			// computes the average
			double enrollment::getAverage(){
				for(int i =0; i< gradeCount; i++)
				{
					average +=grades[gradeCount]; 
				}
				average = average/(gradeCount+1);
				int temp = (average*100);
				average = (average/100);
				return average;
			}
			
			// gets the student enrolles
			student enrollment::getStudent()
			{
				return person;
			}
			// adds student to a class and set the studenta and class variables
			void enrollment::addEnrollment(studentCollection students, courseCollection subjects)
			{
				
				person = students.getStudent(studentID);
				subject = subjects.getCourse(courseID);
				
			}
			
			// export grades to disk
			void enrollment::moveGrades(ofstream& stream)
			{
				for(int i =0; i < gradeCount; i++)
				{
					if(i!= (gradeCount-1))
					{
					stream << grades[i] << "y ";
					}
					else{
						 stream << grades[i] << "n";
					}
				}
				stream <<" -1"<<endl;
			}