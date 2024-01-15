/*
person.cpp
author: M00774667
Created: 26/12/2023
Updated: 30/12/2023
*/
#include "person.h"
std::string Person::getName(){
    return name;
}
std::string Person::getAddress(){
    return address;
}
std::string Person::getEmail(){
    return email;
}
void Person::setName(std::string name){
    this->name = name;
}
void Person::setAddress(std::string address){
    this->address = address;
}
void Person::setEmail(std::string email){
    this->email = email;
}