// Student ID# M00774667
#include <iostream>
#include <sstream>
#include "librarian.h"
// Add the tester librarian details
Librarian lib0(0000, "root", "library system", "root@hotmail.com", 00000);
void addLibrary(){
    // Check if the file name exist, if not, shut the program
    std::string filename = "";
    std::cout << "Enter ONLY the .csv file name with the books stored (DON'T ADD '.csv')(e.g. 'filename').\n";
    std::cin >> filename;
    std::ifstream csvFile(filename+".csv");
    if(csvFile.is_open()){
        std::string bookID, bookName, pageCount, authorFirstName, authorLastName, bookType, line;
        std::getline(csvFile, line);
        // Once file is open, loop through each line and create a Book object
        while (std::getline(csvFile, line)){
            std::stringstream inputString(line);
            getline(inputString, bookID, ',');
            getline(inputString, bookName, ',');
            getline(inputString, pageCount, ',');
            getline(inputString, authorFirstName, ',');
            getline(inputString, authorLastName, ',');
            getline(inputString, bookType, ' ');
            std::cout << stoi(bookID) << " - " << bookName << " - " << authorFirstName << " - " << authorLastName << "\n";
            Book book(stoi(bookID), bookName, authorFirstName, authorLastName);
            // Add the book to an existing vector to store all the books
            getBookVtr().push_back(book); 
        }
        std::cout << "\nAll books added\n";
        csvFile.close();
    } else{
        // Exit the program if the file can't be found for the user to check the folders
        std::cout << "Failed to open the file, might not exist.\nPlease check your folders and start again.\n";
        exit(0);
    }
}
std::string options(){
    // Get, input check and return the option of the option menu
    std::string enterChoice = "0";
    while(!(enterChoice =="1") && !(enterChoice == "2") && !(enterChoice == "3") && !(enterChoice == "4") && !(enterChoice == "9")){ 
    std::cout << "\nPress the right number to: \n'1' Add a member.\n"
            <<"'2' Issue a book to a member.\n'3' Return a book and calculate fine if overdue.\n"
            <<"'4' Display all the books borrowed by any individual member.\n"
            <<"'9' Exit the program.\n";   
    std::cin >> enterChoice;
    };
    return enterChoice;
}
void checkForTesterLibrarian(){
    // Input check for the tester librarian
    std::cout << "\nPlease enter the tester librarian details\n"
            << "(Librarian ID = 0, Librarian name = root)to continue or 9 to exit\n";
    std::string librarianIDCheck = "";
    while ((librarianIDCheck != "0") || (librarianIDCheck != "9")){
        std::cout << "Enter the tester librarian ID number in numeric values: ";
        std::cin >> librarianIDCheck;
        if (librarianIDCheck == "0"){
            std::string librarianNameCheck = "";
            while ((librarianNameCheck != "root") || (librarianNameCheck != "9")){
                std::cout << "Enter the librarian name: ";
                std::cin >> librarianNameCheck;
                if(librarianNameCheck == "root"){
                    break;
                } else if(librarianNameCheck == "9"){
                    exit(0);
                } else{
                    std::cout << "This name doesn't match with the tester ID number given.\n";
                }
            }
            break;
        } else if(librarianIDCheck == "9"){
            exit(0);
        } else {
            std::cout << "This librarian doesn't exist or your input is not a numeric value.\n";
        }
    }
}
int getTheMemberID(){
    // Get, input check and return the member ID
    std::regex IDRegexCheck("^[0-9]+$");
    std::string memberIDToCheck;
    std::cout << "Please enter the member ID you would like to manage: ";
    std::cin >> memberIDToCheck;
    bool x = true;
    while (x){
        if(std::regex_match(memberIDToCheck,IDRegexCheck)){
            if(stoi(memberIDToCheck) < getMemberVtr().size()){
                x = false;
            } else{
                std::cout << "Input is not a number or member ID doesn't exist, Enter member ID again: \n";
                std::cin >> memberIDToCheck;
            }
        } else{
            std::cout << "Input is not a number or member ID doesn't exist, Enter member ID again: \n";
            std::cin >> memberIDToCheck;
        }
    }
    return stoi(memberIDToCheck);
}
int getTheBookID(){
    // Get, input check and return the book ID
    std::regex IDRegexCheck("^[0-9]+$");
    std::string bookIDToCheck = "";
    std::cout << "Enter the ID of the book you are going to manage: ";
    std::cin >> bookIDToCheck;
    bool x = true;
    while (x){
        if(std::regex_match(bookIDToCheck,IDRegexCheck)){
            if((stoi(bookIDToCheck) < getBookVtr().size())&&(stoi(bookIDToCheck) > 0)){
                x = false;
            } else{
                std::cout << "Input is not a number or book ID doesn't exist, Enter book ID again: \n";
                std::cin >> bookIDToCheck;
            }
        } else{
            std::cout << "Input is not a number or book ID doesn't exist, Enter book ID again: \n";
            std::cin >> bookIDToCheck;
        }
    }
    return stoi(bookIDToCheck);
}
int main(){
    // Initialise the program 
    std::cout << "This is a library tracking system for librarian use only.\n";
    // Read csv file and store all the books in a vector to access them later
    addLibrary(); 
    // Confirm is the librarian tester
    checkForTesterLibrarian();
    std::cout << "\nWelcome " << lib0.getName() << ".\n";
    // Display the management options
    std::string enterChoice = options();
    while (enterChoice != "9"){
        int memberID, bookID;
        if (enterChoice == "1"){
            // Add a member
            lib0.addMember();
        } else if (enterChoice == "2"){
            // Issue the book to the member specified
            memberID = getTheMemberID();
            bookID = getTheBookID();
            lib0.issueBook(memberID, bookID);
        } else if (enterChoice == "3"){
            // Return a book borrowed by the member and calculate the fine
            memberID = getTheMemberID();
            bookID = getTheBookID();
            lib0.returnBook(memberID, bookID);
        } else if (enterChoice == "4"){
            // Display all the books borrowed by the member
            memberID = getTheMemberID();
            lib0.displayBorrowedBooks(memberID);
        }
        enterChoice = options();
    }
    return 0;
}