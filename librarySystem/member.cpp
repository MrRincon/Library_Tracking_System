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
    booksLoaned.push_back(book);
    // int valueBookID;
    // std::cout << "Enter the book ID of the book you would like to borrow: ";
    // std::cin >> valueBookID;
    // valueBookID
    
}