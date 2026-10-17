#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "student.h"

void loadStudents(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
std::string menu();

int main(){

  std::vector<Student*> students;
  std::string choice;
  loadStudents(students);
  
  do {
    choice = menu();

    if (choice == "1") {
      showStudentNames(students);
    } else if (choice == "2") {
        printStudents(students);
    } else if (choice == "3") {
        findStudent(students);
    } else if (choice == "0") {
	std::cout << "Thank you for your time.\n";
	return 0;
    }
  } while (choice != "0"); // end do while

  delStudents(students);

  return 0;
} // end main

void loadStudents(std::vector<Student*>& students){
  std::ifstream inFile("students.csv"); // opening the file
  std::string studentString;

  // looping the file to read each line as a string
  while (getline(inFile, studentString)){
    // if the string is not empty
    if (!studentString.empty()){
      students.push_back(new Student(studentString));
    } // end if
  } // end while
  inFile.close(); // closing the file
} // end loadStudents

void printStudents(std::vector<Student*>& students){
  for (Student* student : students){
    student->printStudent();
    std::cout << "__________________________________\n\n";
  } // end for
} // end printStudents

void showStudentNames(std::vector<Student*>& students){
  Student s;
  for (Student* student : students) {
    student->printName();
  } // end for
} // end showStudentNames

void findStudent(std::vector<Student*>& students){
  std::string searchName;
  std::cout << "Last name of student: ";
  //getline(std::cin >> std::ws, searchName);
  std::cin >> searchName;

  bool found = false;

  for (Student* student : students) {
    if (student->getLastName().find(searchName) == std::string::npos){
      student->printStudent();
      std::cout << "___________________________________\n\n";
      found = true;
    } // end if
  } // end for
  if (!found) {
    std::cout << "No matching students found.\n";
    std::cout << "___________________________________\n\n";
  } // end if
} // end findStudent

void delStudents(std::vector<Student*>& students){
  for (Student* student : students) {
    delete student; // removing allocated heap memory
  } // end for
} // end delStudents

std::string menu(){
  std::cout << "0) quit\n" 
	  << "1) print all student names\n" 
	  << "2) print all student data\n" 
	  << "3) find a student\n" 
	  << "\nPlease choose 0-3: ";
  std::string input;
  std::cin >> input;
  return input;
} // end menu
