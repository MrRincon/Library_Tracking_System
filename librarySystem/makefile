CXX = g++
CXXFLAGS = -g
libraryMain: main.cpp person.o librarian.o book.o member.o 
	$(CXX) $(CXXFLAGS) -o libraryMain main.cpp person.o librarian.o book.o member.o 
person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c person.cpp
librarian.o: librarian.cpp librarian.h
	$(CXX) $(CXXFLAGS) -c librarian.cpp
book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) -c book.cpp	
member.o: member.cpp member.h
	$(CXX) $(CXXFLAGS) -c member.cpp