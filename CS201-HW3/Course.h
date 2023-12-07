#ifndef COURSE_H_
#define COURSE_H_

#include <string>
#include <iostream>

class Course
{
    int course_id_ = 0;
    std::string title_{};

public:
    Course();
    Course(int id, const std::string title);
    int getCourseId() const;
    std::string getCourseTitle() const;
    bool operator==(const Course& other) const;
};

#endif