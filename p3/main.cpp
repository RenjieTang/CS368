///////////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  studentDB.cpp
////// File:             main.cpp
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
#include "Student.h"
#include "SortedList.h"
/**
 * Student class update doesn't matter. There will be no memory leak for old Student class
 * becuase there is no memory allocation. However, SortedList update does matter becuase we
 * dynamically allocate some data in heap.
 *
 */ 
int main(){
	Student* s1 = new Student(200000);
	s1->update(302, 3, 2014, Spring, 'A');
	s1->update(303, 3, 2014, Spring, 'B');
	s1->update(304, 3, 2014, Spring, 'A');
	s1->update(305, 3, 2014, Spring, 'B');
	s1->update(306, 3, 2014, Spring, 'C');


	Student* s2 = new Student(*s1);
	Student* s3 = new Student(*s1);
	Student* s4 = new Student(*s1);
	Student* s5 = new Student(*s1);

	Student* s6 = new Student(666666);
	s6->update(602, 3, 2014, Spring, 'A');
	s6->update(603, 3, 2014, Spring, 'B');
	s6->update(604, 3, 2014, Spring, 'A');
	s6->update(605, 3, 2014, Spring, 'B');
	s6->update(606, 3, 2014, Spring, 'C');

	


	delete s2;
	delete s3;
	delete s4;
	delete s5;

	Student* s7 = new Student(777777);
	s6->update(702, 3, 2014, Spring, 'A');
	s6->update(703, 3, 2014, Spring, 'B');
	s6->update(704, 3, 2014, Spring, 'A');
	s6->update(605, 3, 2014, Spring, 'B');
	s6->update(606, 3, 2014, Spring, 'C');

	Student* s8 = new Student(888888);
	s6->update(602, 3, 2014, Spring, 'A');
	s6->update(603, 3, 2014, Spring, 'B');
	s6->update(604, 3, 2014, Spring, 'A');
	s6->update(605, 3, 2014, Spring, 'B');
	s6->update(606, 3, 2014, Spring, 'C');



	SortedList* l1 = new SortedList();
	l1->insert(s1);
	l1->insert(s6);
	l1->insert(s7);
	l1->insert(s8);

		
	SortedList* l2 = new SortedList(*l1);
	SortedList l3;
	
	l3 = *l1;
	
	delete l1->remove(200000);
	delete l1->remove(666666);
	delete l1->remove(777777);
	delete l1->remove(888888);
	delete l2->remove(200000);
	delete l2->remove(666666);
	delete l2->remove(777777);
	delete l2->remove(888888);
	delete l3.remove(200000);
	delete l3.remove(666666);
	delete l3.remove(777777);
	delete l3.remove(888888);

	delete l1;
	delete l2;

		

}

