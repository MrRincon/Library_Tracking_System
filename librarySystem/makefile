# makefile
# Author: M00774667
# Created: 28/12/2023
# Updated: 12/1/2024
CXX = g++
CXXFLAGS = -g 
all: libraryMain Catch2test

Catch2test: test.cpp person.o member.o book.o librarian.o
	$(CXX) $(CXXFLAGS) -o Catch2test test.cpp person.o member.o book.o librarian.o

libraryMain: main.cpp person.o member.o book.o librarian.o 
	$(CXX) $(CXXFLAGS) -o libraryMain main.cpp person.o member.o book.o librarian.o 

person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c person.cpp

member.o: member.cpp member.h
	$(CXX) $(CXXFLAGS) -c member.cpp	

book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) -c book.cpp	

librarian.o: librarian.cpp librarian.h
	$(CXX) $(CXXFLAGS) -c librarian.cpp	

.PHONY: clean 

clean: 
		-rm -f *.o
		-rm -f libraryMain
		-rm -f Catch2test