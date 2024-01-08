#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#ifndef _BOOK_H_
#define _BOOK_H_
class Book{
    private:
        int bookID;
        std::string bookName;
        std::string authorFirstName;
        std::string authorLastName;
        std::string bookType;
        time_t dueDate;
        class Member *borrower;
    public:
        Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
        std::string getBookID();
        std::string getBookName();
        std::string getAuthorFirstName();
        std::string getAuthorLastName();
        time_t getDueDate();
        void setDueDate(time_t dueDate);
        void returnBook();
        void borrowBook(Member *borrower, time_t dueDate);
};
#endif