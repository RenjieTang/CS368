///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Title:            Program 5
//// Files:            findWord.cpp
//// Semester:         (368) Fall 2015
////
//// Author:           Renjie Tang
//// Email:            rtang37@wisc.edu
//// CS Login:         renjie
//// Lecturer's Name:  Okan Akalin
//// Lab Section:      
////
////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
////
//// Pair Partner:     Zhenda Lu
//// Email:            zlu65@wisc.edu
//// CS Login:         zhenda
//// Lecturer's Name:  Okan Akalin
//// Lab Section:      
////
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 3){
		cout<<"Proper usage: findWord <word> <file>"<<endl;
		cout<<"where\n  <word> is a sequence of non-whitespace characters\n  <file> is the file in which to search for the word"<<endl;
		cout<<"example: findWord the test.txt"<<endl;		
		return 0;
	}	
	else{	
		//the line we are gonna read
		string line;
		//line number
		int nLine = 0;
		//count of occurence
		int nFound = 0;
		
		cout<<"Searching for \'"<<argv[1]<<"' in file \'"<<argv[2]<<"\'"<<endl;
		//the file object
		ifstream myfile(argv[2]);
		//the word
		string wanted = argv[1];
		if(!myfile.is_open()){
			cout<<"File \'"<<argv[2]<<"\' could not be opened"<<endl;
		}
		else{
			//iterate all lines
			while(getline(myfile,line)){
				//next line
				nLine++;
				//whether print or not
				bool found = false;
				for(int i = 0; i < strlen(line.c_str()); i++){
					//compare strings
					if(strncmp(&line[i], wanted.c_str(), strlen(wanted.c_str())) == 0){
						nFound++;
						found = true;
					}
				
				}
				if(found){
					cout<<nLine<<" : "<<line<<endl;
				}	
			
			}	
				cout<<"# occurrences of \'"<<wanted<<"\' = "<<nFound<<endl;
		}
		myfile.close();
	}
	return 0;
}
