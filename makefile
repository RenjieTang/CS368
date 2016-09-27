a: Student.h Student.cpp SortedList.h SortedList.cpp studentDB.o
	g++ -c Student.cpp
	g++ -c SortedList.cpp
	g++ Student.o SortedList.o studentDB.o -o runDB
