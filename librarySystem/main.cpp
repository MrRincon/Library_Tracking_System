#include <iostream>
#include "person.h"
#include "librarian.h"
#include "member.h"
#include "book.h"
// #include <string>
// #include <regex>
// #include <vector>
// #include <ctime>
// Add the tester librarian details
Librarian lib0(0000, "root", "library system", "root@hotmail.com", 00000);
bool librarianCheck(){
    int librarianIDCheck;
    std::string librarianNameCheck;
    std::cout << "Enter the tester librarian ID number in numeric values: ";
    std::cin >> librarianIDCheck;
    if (librarianIDCheck == lib0.getStaffID()){
        std::cout << "Enter the librarian name: ";
        std::cin >> librarianNameCheck;
        if (librarianNameCheck == lib0.getName()){
            std::cout << "\nWelcome " << lib0.getName() << ".\n";
            return true;
        } else{
            std::cout << "This name doesn't match with the tester ID number given.\n";
            return false;
        }
    } else{
        std::cout << "This librarian doesn't exist or your input is not a numeric value.\n";
        return false;
    }
}
void options(){
        char enterChoice = '0';
        while(!(enterChoice =='1') && !(enterChoice == '2') && !(enterChoice == '3') && !(enterChoice == '4') && !(enterChoice == '5') && !(enterChoice == '9')){ 
        std::cout << "Press the right number to: \n'1' Add a member.\n"
        <<"'2' Issue a book to a member.\n'3' Return a book.\n"
        <<"'4' Display all the books borrowed by any individual member.\n"
        <<"'5' Calculate a fine for any individual member for overdue book(s).\n"
        <<"'9' Exit the program.\n";   
        std::cin >> enterChoice;
        }
        if (enterChoice == '1'){
            // addNewMember();
        } else if (enterChoice == '2'){

        } else if (enterChoice == '3'){

        } else if (enterChoice == '4'){

        } else if (enterChoice == '5'){

        } else if (enterChoice == '9'){
            exit(0);
        }
}
void systemFunctionality(){
    if (librarianCheck() == true){
        options();
    } else{
        std::cout << "Sorry.\n";
        exit(0);
    }
}
int main(){
    int counterID = 1;
    Member m0( counterID, "lnsdlnasdl", "somewhere", "lashdna");
    // std::cout << m0.getMemberID();

    std::cout << "This is a library tracking system for librarian use only.\nPlease enter the tester librarian details(Librarian ID = 0, Librarian name = root) to continue\n";
    systemFunctionality();
    return 0;
}