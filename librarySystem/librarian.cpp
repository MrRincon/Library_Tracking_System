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
    std::cout << "Your member ID is: " << memberID << '\n';
    // Add the member to an existing vector to store all the members
    getMemberVtr().push_back(member);
}
void Librarian::issueBook(int memberID, int bookID){
    // Display the user and the book issued
    std::cout << "\nMember ID: " << (getMemberVtr()[memberID]).getMemberID() << "\n"
    << "Member name: " << (getMemberVtr()[memberID]).getName() << "\n"
    << "Book ID: " << (getBookVtr()[bookID-1]).getBookID() << "\n" 
    << "Book Title: " << (getBookVtr()[bookID-1]).getBookName() << "\n";
    // Adjusting the borrower in the book class
    (getBookVtr()[bookID-1]).borrowBook(&(getMemberVtr()[memberID]), (time(nullptr)+(3*24*60*60)));
}
void Librarian::returnBook(int memberID, int bookID){
    // Check if the books borrowed by the member is empty
    if ((getMemberVtr()[memberID]).getBooksBorrowed().empty()){
        std::cout << "The member can't return any books as he hasn't borrowed any\n";
    } else{
        bool x = true;
        // Loop through all the pointers of books in the books borrowed vector of the member selected
        for (int i = 0; i < (getMemberVtr()[memberID]).getBooksBorrowed().size(); i++){
            if (bookID == stoi((getMemberVtr()[memberID]).getBooksBorrowed()[i]->getBookID())){
                x = false;
                // Reasign the book borrowed by the user pointer to 0 or nullptr
                ((getMemberVtr()[memberID]).getBooksBorrowed()[i]) = nullptr;
                // Calculate fine
                calcFine(memberID, bookID);
                // Fix the values in the book class
                getBookVtr()[bookID-1].returnBook();
            } 
        }
        if(x){
            std::cout << "Book hasn't been requested\n";
        }
    }
}
void Librarian::displayBorrowedBooks(int memberID){
    // Check if there is any book borrowed by the member
    if((getMemberVtr()[memberID]).getBooksBorrowed().empty()){
        std::cout << "This member has not borrowed any books yet\n\n";
    } else{
        std::cout << "This member has borrowed the following books: \n";
        for (int i = 0; i < (getMemberVtr()[memberID]).getBooksBorrowed().size(); i++){
            std::cout << (getMemberVtr()[memberID]).getBooksBorrowed()[i]->getBookID() << " -- "
            << (getMemberVtr()[memberID]).getBooksBorrowed()[i]->getBookName() << '\n';
        }
    }
}
void Librarian::calcFine(int memberID, int bookID){
    time_t currentT = time(nullptr);
    if (currentT > getBookVtr()[bookID-1].getDueDate()){
        int dlate = difftime(currentT, getBookVtr()[bookID-1].getDueDate())/(60*60*24);
        int fine = dlate * 1;
        std::cout << "Due to your lateness of " << dlate << "in returning the book " << bookID
        << ". You will be fined £" << fine;
    }
}
