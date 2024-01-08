#include <iostream>
#ifndef _PERSON_H_
#define _PERSON_H_
class Person{
    private:
        std::string name;
        std::string email;
        std::string address;
    public: 
        std::string getName();
        void setName(std::string name);
        std::string getAddress();
        void setAddress(std::string address);
        std::string getEmail();
        void setEmail(std::string email);
};
#endif