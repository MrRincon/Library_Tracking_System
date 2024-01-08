#include <iostream>
#include <vector>
#include "person.h"
#include "book.h"
#ifndef _MEMBER_H_
#define _MEMBER_H_
class Member: public Person{
    private:
        int memberID;
        std::vector<Book*> booksLoaned;
    public:
        Member(int memberID, std::string name, std::string address, std::string email);
        std::string getMemberID();
        std::vector<Book*> getBooksBorrowed();
        void setBooksBorrowed(Book* book);
};
#endif