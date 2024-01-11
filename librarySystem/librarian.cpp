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
    int memberID = getMemberVtr().size();
    std::string name, address, email;
    std::regex emailRegexCheck("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    std::cout << "Enter the name of the new member ID: ";
    std::cin >> name;
    std::cout << "Enter the member's address: ";
    std::cin >> address;
    std::cout << "Enter the member's email address: ";
    std::cin >> email;
    // Regex check for email address
    while (!std::regex_match(email, emailRegexCheck)){
        std::cout << "Invalid email";
        std::cin >> email;
    }
    Member member(memberID, name, address, email);
    // Add the member to an existing vector to store all the members
    getMemberVtr().push_back(member);
}
void Librarian::issueBook(int memberID, int bookID){
    // Display the user and the book issued
    std::cout << "Member ID: " << (getMemberVtr()[memberID]).getMemberID() << "\n"
    << "Member name: " << (getMemberVtr()[memberID]).getName() << "\n"
    << "Book ID: " << (getBookVtr()[bookID-1]).getBookID() << "\n" 
    << "Book Title: " << (getBookVtr()[bookID-1]).getBookName() << "\n";
    // Set the due date
    (getBookVtr()[bookID-1]).setDueDate(time(nullptr)+(3*24*60*60));
    std::cout << (getBookVtr()[bookID-1]).getDueDate() << "\n";
    std::cout << &(getMemberVtr()[memberID]);
    (getBookVtr()[bookID-1]).borrowBook(&(getMemberVtr()[memberID]), (getBookVtr()[bookID-1]).getDueDate());
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
