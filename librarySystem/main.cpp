#include <iostream>
#include <fstream>
#include <sstream>
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
void addLibrary(){
    // Check if the file name exist, if not, shut the program
    std::string filename = "";
    std::cout << "Enter ONLY the .csv file name with the books stored (e.g. 'filename').\n";
    std::cin >> filename;
    std::ifstream csvFile(filename+".csv");
    if(csvFile.is_open()){
        std::string line;
        int csvLineCount = 0; 
        std::string bookID;
        std::string bookName;
        std::string pageCount;
        std::string authorFirstName;
        std::string authorLastName;
        std::string bookType;
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
            csvLineCount++;  
        }
        std::cout << "All books added";
        csvFile.close();
    } else{
        std::cout << "Failed to open the file, might not exist.\nPlease check your folders and start again.\n";
        exit(0);
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
            // lib0.addNewMember();
        } else if (enterChoice == '2'){

        } else if (enterChoice == '3'){

        } else if (enterChoice == '4'){

        } else if (enterChoice == '5'){

        } else if (enterChoice == '9'){
            exit(0);
        }
}
void checkForTesterLibrarian(){
    // Small input check for the tester librarian
    std::cout << "Please enter the tester librarian details(Librarian ID = 0, Librarian name = root) to continue or 9 to exit\n";
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
int main(){
    // Initialise the program 
    std::cout << "This is a library tracking system for librarian use only.\n";
    // Read csv file and count the amount of lines
    addLibrary(); 
    // Confirm is the librarian tester
    checkForTesterLibrarian();
    std::cout << "\nWelcome " << lib0.getName() << ".\n";
    // Display the management options
    options();
    // Member m0( counterID, "lnsdlnasdl", "somewhere", "lashdna");
    // std::cout << m0.getMemberID();
    return 0;
}