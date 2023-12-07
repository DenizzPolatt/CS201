#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include "SortedSLL.h"
#include "Course.h"

class Student
{
    int student_id_{0};
    std::string first_name_{};
    std::string last_name_{};
    SortedSLL<Course> enrolled_courses_{};

public:
    Student();
    Student(const int studentId, const std::string firstName, const std::string lastName);
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    SortedSLL<Course>& getCourses();
    void addCourse(const Course& course); 
    void removeCourse(int pos);
    bool operator==(const Student& other) const;
};

#endif