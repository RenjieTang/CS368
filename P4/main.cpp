///////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  main.cpp
////// File:             main.cpp
////// Semester:         cs368 Fall 2015
//////
////// Author:           Renjie Tang
////// CS Login:         renjie
////// Lecturer's Name:  Okan Akalin
////// 
////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
//////
////// Pair Partner:     Zheda Lu
////// Email:            zlu65@wisc.edu
////// CS Login:         zhenda
////// Lecturer's Name:  Okan Akalin
////// 
//////
//////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include"ComplexNumber.h"

using namespace std;

int main() {
	cout << "Enter a complex number C1:" << endl;
	ComplexNumber c1;
	cin >> c1;
	cout<< "Enter a complex number C2:" << endl;
	ComplexNumber c2;
	cin >> c2;
	cout << "For C1 = " << c1 << " and C2 = " << c2 << " :"<<endl;
	cout << "C1 + C2 = " << c1+c2 << endl;
	cout << "C1 - C2 = " << c1-c2 << endl;
	cout << "C1 * C2 = " << c1*c2 << endl;
	cout << "C1 == C2 is " << (c1==c2?"true":"false") << endl;
	cout << "C1 != C2 is " << (c1!=c2?"true":"false") << endl;
	ComplexNumber c3;
	c3= c1;
	cout << "After C1 += C2, C1 = " << (c3+=c2) << endl;
	c3 = c1;
	cout << "After C1 -= C2, C1 = " << (c3-=c2) << endl;
	cout << "After C1 *= C2, C1 = " << (c1*=c2) << endl;


}
