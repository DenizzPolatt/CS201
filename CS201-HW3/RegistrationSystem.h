#ifndef REGISTRATIONSYSTEM_H_
#define REGISTRATIONSYSTEM_H_

#include "SortedDLL.h"
#include "Student.h"
#include <string>
#include <iostream>

class RegistrationSystem
{
    SortedDLL<Student> students_;
public :
    RegistrationSystem();
    ~RegistrationSystem();
    void addStudent ( const int studentId , const std::string firstName , const std::string lastName ) ;
    void deleteStudent ( const int studentId ) ;
    void addCourse ( const int studentId , const int courseId , const std::string courseName ) ;
    void withdrawCourse ( const int studentId , const int courseId ) ;
    void cancelCourse ( const int courseId ) ;
    void showStudent ( const int studentId ) ;
    void showCourse ( const int courseId ) ;
    void showAllStudents () ;
};

#endif

