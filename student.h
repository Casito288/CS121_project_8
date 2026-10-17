#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <iostream>
#include <string>
#include <sstream>

class Date;
class Address;

class Student {

  protected: 
    std::string studentString;
    std::string firstName;
    std::string lastName;
    Date* dob;
    Date* expectedGrad;
    Address* address;
    int creditHours;
  public:
    Student(std::string studentString = " ");
    ~Student();
    void init(std::string studentString);
    void printStudent();
    void printName();
    std::string getFirstName();
    std::string getLastName();
    int getCredits();
};

#endif
