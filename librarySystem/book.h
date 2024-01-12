// Student ID# M00774667
#ifndef _BOOK_H_
#define _BOOK_H_
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
// Include the member file to manage the borrowBook function without issues
#include "member.h"
class Book{
    private:
        int bookID;
        std::string bookName;
        std::string authorFirstName;
        std::string authorLastName;
        std::string bookType;
        time_t dueDate;
        class Member* borrower = nullptr;
    public:
        Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
        std::string getBookID();
        std::string getBookName();
        std::string getAuthorFirstName();
        std::string getAuthorLastName();
        time_t getDueDate();
        void setDueDate(time_t dueDate);
        void returnBook();
        void borrowBook(Member* borrower, time_t dueDate);
};
// External function to store all the books
std::vector<Book> &getBookVtr();
#endif