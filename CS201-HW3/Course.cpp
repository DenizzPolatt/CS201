#include "Course.h"
#include <string>

Course::Course() = default;
Course::Course(const int id, const std::string title) : course_id_(id), title_(title) {}

int Course::getCourseId() const
{
    return course_id_;
}

std::string Course::getCourseTitle() const 
{
    return title_;
}

bool Course::operator==(const Course& other) const
{
    return course_id_ == other.course_id_;
}

