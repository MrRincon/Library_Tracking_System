/*
member.cpp
author: M00774667
Created: 26/12/2023
Updated: 14/1/2024
*/
#include "member.h"
Member::Member(int memberID, std::string name, std::string address, std::string email){
    this->memberID = memberID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
}
std::string Member::getMemberID(){
    return std::to_string(memberID);
}
std::vector<Book*> Member::getBooksBorrowed(){
    return booksLoaned;
}
void Member::setBooksBorrowed(Book* book){
    // Add the book borrowed to the vector of books borrowed by this member
    booksLoaned.push_back(book);
}
std::vector<Member> &getMemberVtr(){
    static std::vector<Member> memberVtr;
    return memberVtr;
}