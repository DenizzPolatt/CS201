#include "Student.h"

Student::Student() = default;
Student::Student(const int studentId, const std::string firstName, const std::string lastName) : student_id_(studentId), first_name_(firstName), last_name_(lastName), enrolled_courses_() {}

int Student::getId() const { return student_id_; }
std::string Student::getFirstName() const 
{
    return first_name_;
}

std::string Student::getLastName() const
{
    return last_name_;
}

SortedSLL<Course>& Student::getCourses() 
{
    return enrolled_courses_; 
}

void Student::addCourse(const Course& course) {
    int pos = 1;
    while (pos <= enrolled_courses_.getLength() && enrolled_courses_.getEntry(pos).getCourseId() < course.getCourseId())
    {
        ++pos;
    }
    enrolled_courses_.insert(pos, course);
}

void Student::removeCourse(int position) {
    enrolled_courses_.remove(position);
}
bool Student::operator==(const Student& other) const
{
    return student_id_ == other.student_id_;
}
