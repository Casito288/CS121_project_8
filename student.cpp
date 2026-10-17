#include <iostream>
#include "student.h"
#include "address.h"
#include "date.h"
#include <sstream>
#include <fstream>

//void address();
//void date();
void printStudent();

Student::Student(std::string studentString){
  std::string firstName = " ";
  std::string lastName = " ";
  address = new Address();
  dob = new Date();
  expectedGrad = new Date();
  int creditHours = 0;
} // end constructor

Student::~Student(){
  // deleting the memory on the heap
  delete address;
  delete dob;
  delete expectedGrad;
} // end destructor

void Student::init(std::string studentString){
  std::stringstream ss;

  ss.clear();
  ss.str("");

  ss.str(studentString);

  std::string street, city, state, zip, stringDOB, stringGrad, credits;

  getline(ss, firstName, ',');
  getline(ss, lastName, ',');

  getline(ss, street, ',');
  getline(ss, city, ',');
  getline(ss, state, ',');
  getline(ss, zip, ',');
  address->init(street, city, state, zip);

  getline(ss, stringDOB , ',');
  dob->init(stringDOB);

  getline(ss, stringGrad, ',');
  dob->init(stringGrad);

  getline(ss, credits, ',');
  ss << credits;
  ss >> creditHours;
} // end init

void Student::printStudent(){
  std::cout << firstName << ", " << lastName << ", ";
  address->printAddress();
  std::cout << "DOB: ";
  dob->printDate();

  std::cout << "\nGrad: ";
  expectedGrad->printDate();
  std::cout << "\nCredits: " << creditHours << std::endl;
} // end printStudent

void Student::printName(){
  std::cout << lastName << ", " << firstName << std::endl;
} // end printName

std::string Student::getFirstName(){
  return firstName;
} // end getFirstName

std::string Student::getLastName(){
  return lastName;
} // end getLastName

int Student::getCredits(){
  return creditHours;
} // end getCredits
