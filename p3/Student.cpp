///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Main Class File:  studentDB.cpp
//// File:             Student.cpp
//// Semester:         cs368 Fall 2015
////
//// Author:           Renjie Tang
//// CS Login:         renjie
//// Lecturer's Name:  Okan Akalin
//// 
////
////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
////
//// Pair Partner:     Zheda Lu
//// Email:            zlu65@wisc.edu
//// CS Login:         zhenda
//// Lecturer's Name:  Okan Akalin
//// 
////
/////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include "Student.h"
#include <cstring>


Student::Student(){
	//initialize the student id to be 0
	studentID = 0;
	//initialize the number of courses to be 0
	nCoursesTaken = 0;

}

Student::Student(int ID){
	//initialize with the given ID
	studentID = ID;	
	nCoursesTaken = 0;
}

Student::Student(int ID, CourseInfo ** courses){
	studentID = ID;	
	//dereference CourseInfo pointer one by one and assign it to the field
	int i = 0;
	while(courses[i] != NULL){
		coursesTaken[i] = *(courses[i]);
		i++;
	}
	nCoursesTaken = i;
}

Student::Student(const Student &stu) {
	studentID = stu.getID();
	int i = 0;
	CourseInfo const ** copy = stu.getCourses();
	while(copy[i] != NULL){
		coursesTaken[i] = *(copy[i]);
		i++;
	}
	delete []copy;
	nCoursesTaken = i;
}

Student& Student::operator=(const Student &stu) {
	if(this != &stu) {
		studentID = stu.getID();
		int i = 0;
		CourseInfo const ** copy = stu.getCourses();
		while(copy[i] != NULL){
			coursesTaken[i] = *(copy[i]);
			i++;
		}
		delete[] copy;
		nCoursesTaken = i;
	}
return *this;
}


Student::~Student()
{
}

int Student::getID() const{
	return studentID;

}

int Student::getCredits() const{
	int numOfCredits = 0;
	//tranverse through all the courses taken and sum the number of credits up
	for(int i = 0; i < nCoursesTaken; i++){
		numOfCredits += coursesTaken[i].credits;
	}
	return numOfCredits;
}

double Student::getGPA() const{
	double GPA = 0;
	int numOfCredits = this->getCredits();
	double grade = 0;
	//get the result of total credit*grade
	for(int i = 0; i < nCoursesTaken; i++){
		char g = coursesTaken[i].studentGrade;
		int credits = coursesTaken[i].credits;
		if(g=='a' || g=='A') grade += 4*credits;
		else if(g=='b' || g=='B') grade += 3*credits;
		else if(g=='c' || g=='C') grade += 2*credits;
		else if(g=='d' || g=='D') grade += credits;

	}
	//divide it by the number of credits
	if(numOfCredits == 0) {
		GPA = 0;
	}
	else{
		GPA = grade/numOfCredits;
	}
	return GPA;
}

CourseInfo const ** Student::getCourses() const{
	int i;
	//create an array of courseinfo pointer for return use
	CourseInfo const ** retArr = new CourseInfo const *[100];
	//iteratively assign objects to the pointers
	for(i = 0; i < nCoursesTaken; i++){
		//the array might end in the middle, indicated by 0 credits
		if(coursesTaken[i].credits == 0) break;
		retArr[i] = &coursesTaken[i];	
	}
	//if the array is full, just return it
	if(i == 100) return retArr;
	//if not, assign the last pointer to be NULL to indicate the ending
	retArr[i] = NULL;
	return retArr;
}

void Student::update(int courseNumber, int credits, int year, Semester cSemester, char grade){	
	//update the course taken
	coursesTaken[nCoursesTaken].courseNumber = courseNumber;
	coursesTaken[nCoursesTaken].credits = credits;
	coursesTaken[nCoursesTaken].year = year;
	coursesTaken[nCoursesTaken].studentGrade = grade;
	coursesTaken[nCoursesTaken].cSemester = cSemester;
	nCoursesTaken++;

}

void Student::print() const{
	//print in  the format
	std::cout<<studentID<<","<<this->getCredits()<<","<<this->getGPA();	

}

bool Student::tookCourse(int courseNumber, int year, Semester cSemester){
	//tranverse through the courses taken to find the match
	for(int i = 0; i<nCoursesTaken; i++){
		if(coursesTaken[i].courseNumber == courseNumber && coursesTaken[i].year == year && coursesTaken[i].cSemester == cSemester){
			return true;
		}
	}
	return false;

}


