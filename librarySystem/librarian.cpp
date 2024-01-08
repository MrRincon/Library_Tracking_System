#include "librarian.h"
Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary){
    this->staffID = staffID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
    this->salary = salary;
}
int Librarian::getStaffID(){
    return staffID;
}
int Librarian::getSalary(){
    return salary;
}
void Librarian::setStaffID(int staffID){
    this->staffID = staffID;
}
void Librarian::setSalary(int salary){
    this->salary = salary;
}
void Librarian::addMember(){
        std::cout << "Please enter the name of the new member ID: ";    
    
}
void Librarian::issueBook(int memberID, int bookID){
    // this->memberID;
    // this->bookID;
}
void Librarian::returnBook(int memberID, int bookID){
    // this->memberID;
    // this->bookID;
}
void Librarian::displayBorrowedBooks(int memberID){
    // this->memberID;
}
void Librarian::calcFine(int memberID){
    // this->memberID;
}
