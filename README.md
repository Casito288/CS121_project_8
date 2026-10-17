# CS121 PROJECT 8

## Mermaid Live Diagram
```
classDiagram

class Student {
    # String studentString
    # String firstName
    # String lastName
    # Date* dob
    # Date* expectedGrad
    # Address* Address
    # int creditHours
    + Student()
    + -Student()
    + void init(studentString)
    + void printStudent()
    + string getFirstName()
    + string getLastName()
    + int getCredits()
}

class Address {
    # String street
    # String zip
    # String city
    # String state
    + Address()
    + void init(street, zip, city, state)
    + void printAddress()
}

class Date {
    # String dateString
    # int month
    # int day
    # int year
    + Date ()
    + void init(dateString)
    + void printDate()
}
```

## Student::Student()
```
#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

class Student {
  protected 
    string studentString
    string firstName
    string lastName
    Date* dob
    Date* expectedGrad
    Address* address
    int creditHours
  public 
    Student()
    -Student()
    void init(studentString)
    void printStudent()
    string getFirstName()
    string getLastName()
    int getCredits()
}

#endif
```

## void Student::init(string studentString)
```
initialize: 
student first and last names
address (street, city, state, zip)
  pass to the instanced Address class on the heap
dates (dob, expectedGrad)
  pass to the instanced Date class on the heap
and creditHours
```

## void Student::printStudent()
```
print firstName, lastName
print address from from instance address class on the heap
print the dob and expectedGrad dates from the instanced date class on the heap
print everything in the desired format
```

## Address::Address()
```
class Address {
  protected string street
  protected string zip
  protected string city
  protected string state
  public Address()
  public void init(street, zip, city, state)
  public void printAddress()
}
```

## void Address::init(street, city, state, zip)
```
initialize the street, city, state, and zip
```

## void Address::printDate()
```
print the address in the desired format
```

## Date::Date()
```
#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

class Date{
  protected string dateString
  protected int month
  protected int day
  protected int year
  Date()
  void init(dateString)
  void printDate()
}

#endif
```

## void Date::init(dateString)
```
  initialize integers month, day, year;
  parse the dateString into seperate strings
  convert the seperate strings into the new integers
```

## void Date::printDate()
```
print the month day and year of the initialized values

```

## Main
```
create an empty vector of Student pointers
load students from the file
repeat unitl the user chooses to quit
  display menu
  read users choice
  go through user choices
delete all students
exit
```

## Main::menu()
```
display the menu options
ask the user to choose an option
read the choice as a string
return choice
```

## Main::findStudent(students)
```
ask the user to enter a last name
loop through each student in the vector
get students last name
check if the last name is the users string
if no match print the the all of student data
```

## Main::showStudentNames(students)
```
loop throgh every student pointer in the vector
print student name
```

## Main::printStudents(students)
```
loop through every student pointer in vector
call all students data function
```

## Main::loadStudents(students)
```
open and read the csv file
while not the end of the file
  create a new student on the heap
  append the student pointer to the vector
close file
```
