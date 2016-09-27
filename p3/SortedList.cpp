///////////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  studentDB.cpp
////// File:             Student.cpp
////// Semester:         cs368 Fall 2015
//////
////// Author:           Renjie Tang
////// CS Login:         renjie
////// Lecturer's Name:  Okan Akalin
////// 
//////
//////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
//////
////// Pair Partner:     Zheda Lu
////// Email:            zlu65@wisc.edu
////// CS Login:         zhenda
////// Lecturer's Name:  Okan Akalin
////// 
//////
///////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <algorithm>
#include <vector>
#include "SortedList.h"
#include "Student.h"


SortedList::SortedList() {
	//create a dummy header node for the sorted list
	head = new Listnode;
	head->student = NULL;
	head->next=NULL;
}

SortedList::SortedList(const SortedList::SortedList &list) {
	this->head = copyList(list.head->next);

}

SortedList::~SortedList(){
	freeList(head);
}

SortedList& SortedList::operator=(const SortedList &list){
	if(this == &list) return *this; 
	freeList(this->head);
	this->head = copyList(list.head->next);
	return *this;
}

//pair struct for classmate pair
struct pair{
	int low;
	int high;
};

bool SortedList::insert(Student* s) {
	//create a new node and assign the data field to the function argument
	Listnode* curr = new Listnode;
	curr->student = s;
	//when the list is empty,simply put the node as the next of header node	
	if(head->next == NULL) {
		head->next = curr;
		curr->next = NULL;

	}
	//when not empty, find the right place to put it in
	else{
		Listnode* now = head;
		//tranverse through the list until we get to the right position
		while(now->next != NULL && now->next->student->getID() < s->getID()){ 
			now = now->next;
		}
		//if we get to the end of the list, we put the node to the tail
		if(now->next == NULL){
			now->next = curr;
			curr->next = NULL;
			return true;
		}
		//if the node already exists, return false
		if(now->next->student->getID() == s->getID()) {
			return false;
		}
		//else we insert the node
		else{
			curr->next = now->next;
			now->next = curr;
		}
	}
	return true;
}

Student* SortedList::find(int studentID) {
	//this is like an iterator
	Listnode* curr = head->next;
	//tranverse through the list to find match
	while(curr!=NULL && curr->student->getID() != studentID) {
		curr = curr->next;
	}
	//if we get the end of the list, it means we find no match, return NULL
	if(curr == NULL) {
		return NULL;
	}
	//return the pointer of the object we find
	else{
		return curr->student;
	}

}

Student* SortedList::remove(int studentID) {
	//this is like an iterator
	Listnode* curr = head;
	//tanverse through the list to find the match
	while(curr->next!= NULL && curr->next->student->getID() != studentID){
		curr = curr->next;
	}
	//we don't find any match, then return NULL
	if(curr->next == NULL) {
		return NULL;
	}
	//create a pointer for the student object in the node, delete the node and return student
	else{
		Listnode* ret = curr->next;
		curr->next = ret->next;
		Student* re = ret->student;
		delete ret;
		return re;
	}
}

int SortedList::getNStudents(int courseNumber, int inYear, Semester inSemester) {
	int counter = 0;
	//iterator
	Listnode* curr = head->next;
	//tranverse until the end of the list
	while(curr != NULL){
		//if this student has taken the course, increment the counter
		if(curr->student->tookCourse(courseNumber,inYear,inSemester)){
			counter++;
		}
	}
	return counter;
}

Student ** SortedList::getClassRoster(int courseNumber, int inYear, Semester inSemester) {
	//iterator
	Listnode* curr = head->next;
	//create a dynamic array of student pointers for return use
	Student ** ret = new Student *[100];
	int i = 0;
	//iteratively add students who took the course to the list for return use
	while(curr != NULL){
		if(curr->student->tookCourse(courseNumber,inYear,inSemester)){
			ret[i] = curr->student;
			i++;
		}
		curr = curr->next;
	}
	//set the NULL poniter to indicate the end of the list
	if(i < 100) ret[i] = NULL;
	return ret;	


}
void SortedList::printClassRoster(int courseNumber, int inYear, Semester inSemester){
	//get the roster list first
	Student ** list = this->getClassRoster(courseNumber, inYear, inSemester);
	int i = 0;
	//if nobody has taken the course, the course is not offered
	if(list[0] == NULL) std::cout<<"Course " << courseNumber << " was not offered in " << inSemester << " of " << inYear << "." << std::endl;
	//tranverse through the list and print them out one by one
	while(list[i] != NULL){
		std::cout<<list[i]->getID()<<std::endl;		
		i++;
	}

}

void SortedList::printClassmates(int * studentGroup, int nStudents) {
	//sort the group of students
	std::sort(studentGroup, studentGroup + nStudents);
	//create a vector for pairs
	std::vector<pair> stuPair;
	//for every student in the group, first get the course he took, then tranverse through
	//every student that have larger id number to
	//see if he took either of the courses  
	for(int i = 0; i < nStudents; i++) {
		Student* lowi = this->find(studentGroup[i]);
		CourseInfo const** clist = lowi->getCourses();
		for(int j = i+1; j < nStudents;j++) {
			Student* highj = this->find(studentGroup[j]);
			for(int k=0; k< sizeof(clist)/sizeof(CourseInfo const*); k++) {
				if(highj->tookCourse(clist[k]->courseNumber, clist[k]->year, clist[k]->cSemester)){
					pair p;
					p.low = lowi->getID();
					p.high = highj->getID();
					stuPair.push_back(p);
					break;
				}
			}

		} 
	}
	//print each element of the vector	
	for(int i = 0;i< stuPair.size();i++){
		std::cout<<stuPair[i].low<<", "<<stuPair[i].high<<std::endl;
	}

}

void SortedList::print() const{
	//iterator
	Listnode* curr = head->next;
	//message when the list is empty
	if(curr == NULL) std::cout<<"Empty student list."<<std::endl;
	//print all the students in the format
	while(curr != NULL){
		std::cout<<curr->student->getID()<<std::endl;
		curr = curr->next;	
	}

}

void SortedList::freeList (Listnode *L){
	if(L==NULL) return;
	Listnode* curr = L;
	Listnode* temp;
	while(curr != NULL){
		temp = curr->next;
		delete curr;
		curr = temp;
	}

}

SortedList::Listnode* SortedList::copyList (Listnode *L){

	Listnode* header = new Listnode;
	header->student =NULL;
	Listnode* cur = header;
	Listnode* old = L;
	Listnode* temp = NULL;
	while(old != NULL){
		temp = new Listnode;
		temp->student = new Student(*(old->student));
		cur->next = temp;
		cur = cur->next;
		old = old->next;
	}
	cur->next =NULL;
	return header;
} 
