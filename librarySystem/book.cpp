/*
book.cpp
author: M00774667
Created: 27/12/2023
Updated: 14/1/2024
*/
#include "book.h"
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName){
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
}
std::string Book::getBookID(){
    return std::to_string(bookID);
}
std::string Book::getBookName(){
    return bookName;
} 
std::string Book::getAuthorFirstName(){
    return authorFirstName;
}
std::string Book::getAuthorLastName(){
    return authorLastName;
}
Member* Book::getBorrower(){
    return borrower;
}
time_t Book::getDueDate(){
    return dueDate;
}
void Book::setDueDate(time_t dueDate){
    this->dueDate = dueDate;
}
void Book::returnBook(){
    // Assign the borrower pointer of the book to 0 or nullptr
    borrower = nullptr;
}
void Book::borrowBook(Member* borrower, time_t dueDate){
    // Add the pointer of the borrower to the book borrower
    this->borrower = borrower;
    // Set the due date of this book
    setDueDate(dueDate);
    borrower->setBooksBorrowed(this);
}
std::vector<Book> &getBookVtr(){
    static std::vector<Book> bookVtr;
    return bookVtr;
}