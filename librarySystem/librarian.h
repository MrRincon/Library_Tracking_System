#include <iostream>
#include <ctime>
#include <string>
// Include all the .h files in order
#include "person.h"
#include "member.h"
#include "book.h"
#ifndef _LIBRARIAN_H_
#define _LIBRARIAN_H_
class Librarian: public Person{
    private:
        int staffID;
        int salary;
    public:
        Librarian(int staffID, std::string name, std::string address, std::string email, int salary);
        void addMember();
        void issueBook(int memberID, int bookID);
        void returnBook(int memberID, int bookID);
        void displayBorrowedBooks(int memberID);
        void calcFine(int memberID, int bookID);
        int getStaffID();
        void setStaffID(int staffID);
        int getSalary();
        void setSalary(int salary);
};
#endif