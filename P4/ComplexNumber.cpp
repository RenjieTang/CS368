/////////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  main.cpp
////// File:             ComplexNumber.cpp
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


#include <iostream>
#include "ComplexNumber.h"
using namespace std;

ComplexNumber::ComplexNumber() {
	real = 0;
	imag = 0;
}

ComplexNumber::ComplexNumber(double real_part, double imaginary_part) {
	real = real_part;
	imag = imaginary_part;
}


ComplexNumber::ComplexNumber(const ComplexNumber & rhs) {
	*this = rhs;	

}

void ComplexNumber::print(ostream & out) const{
	if(imag < 0){
                out << real << " - " << imag*(-1) << "i";
        }
        else{
                out << real << " + " << imag << "i";
        }

}

bool ComplexNumber::equals(const ComplexNumber & rhs) const{
	return (this->real==rhs.real)&&(this->imag==rhs.imag);	
} 


const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs){
	if(this != &rhs){
	this->real = rhs.real;
	this->imag = rhs.imag;
	}
	return *this;
}


const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs){
	this->real += rhs.real;
	this->imag += rhs.imag;
	return *this; 
}

const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs){
	this->real -= rhs.real;
	this->imag -= rhs.imag;
	return *this;
}


const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs){
	double temp = this->real;
	this->real = (this->real*rhs.real) - (this->imag*rhs.imag);
	this->imag = (temp*rhs.imag) + (this->imag*rhs.real);
	return *this;
}


ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber *retval = new ComplexNumber();
	*retval += lhs;
	*retval += rhs;
	return *retval;
}

ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber *retval = new ComplexNumber();
	*retval += lhs;
	*retval -= rhs;
	return *retval;
}

ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber *retval = new ComplexNumber();
	*retval += lhs;
	*retval *= rhs;
	return *retval;
}

bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
	return lhs.equals(rhs);	
}

bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
	return !(lhs == rhs);
}

ostream & operator<<(ostream & out, const ComplexNumber & n){
	n.print(out);	
	return out;
}

istream & operator>>(istream & in, ComplexNumber & n){
	double r;
	double i;
	string s;
	string t;
	in>>r>>s>>i>>t;
	if(s =="+"){
		ComplexNumber c(r,i);
		n=c;
	}
	else{
		ComplexNumber c(r,-i);
		n=c;
	}
	return in;
}
	

