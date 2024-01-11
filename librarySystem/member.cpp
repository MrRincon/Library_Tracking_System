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
std::vector<Book*>& Member::getBooksBorrowed(){
    return booksLoaned;
}
void Member::setBooksBorrowed(Book* book){
    booksLoaned.push_back(book);
}
std::vector<Member> &getMemberVtr(){
    static std::vector<Member> memberVtr;
    return memberVtr;
}