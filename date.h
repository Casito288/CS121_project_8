#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <iostream>
#include <string>

class Date{

  protected:
    int month, day, year;
  public:
    Date();
    void init(std::string dateString);
    void printDate();
}; // end Date

#endif
