#include "RegistrationSystem.h"

RegistrationSystem::RegistrationSystem() = default;
RegistrationSystem::~RegistrationSystem() = default;

void RegistrationSystem::addStudent(const int studentId, const std::string firstName, const std::string lastName)
{
    int pos = 1;
    while (pos <= students_.getLength() && students_.getEntry(pos).getId() < studentId)
    {
        ++pos;
    }

    for (int i = 1; i <= students_.getLength(); ++i)
    {
        if (students_.getEntry(i).getId() == studentId)
        {
            std::cout << "Student " << studentId << " already exists" << std::endl;
            return;
        }
    }

    students_.insert(pos, Student(studentId, firstName, lastName));
    std::cout << "Student " << studentId << " has been added" << std::endl;
}

void RegistrationSystem::deleteStudent(const int studentId) 
{
    for(int i = 1; i <= students_.getLength(); ++i)
    {
        if(students_.getEntry(i).getId() == studentId)
        {
            students_.getEntry(i).getCourses().clear();
            students_.remove(i);
            std::cout << "Student " << studentId << " has been deleted" << std::endl;
            return;
        }
    }

    std::cout << "Student " << studentId << " does not exists" << std::endl;
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const std::string courseName)
{
    for (int i = 1; i <= students_.getLength(); ++i)
    {
        if (students_.getEntryRef(i).getId() == studentId)
        {
            
            for (int j = 1; j <= students_.getEntryRef(i).getCourses().getLength(); ++j)
            {
                if (students_.getEntryRef(i).getCourses().getEntry(j).getCourseId() == courseId)
                {
                    std::cout << "Course " << courseId << " already exists for student " << studentId << std::endl;
                    return;
                }
            }
            students_.getEntryRef(i).addCourse(Course(courseId, courseName));
            std::cout << "Course " << courseId << " has been added to student " << studentId << std::endl;
            return;
        }
    }

    std::cout << "Student " << studentId << " does not exist" << std::endl;
}

void RegistrationSystem::withdrawCourse(const int studentId , const int courseId)
{
    for(int i = 1; i <= students_.getLength(); ++i)
    {
        if(students_.getEntryRef(i).getId() == studentId)
        {
            for(int j = 1; j < students_.getEntryRef(i).getCourses().getLength(); j++)
            {
                if(students_.getEntryRef(i).getCourses().getEntry(j).getCourseId() == courseId)
                {
                    students_.getEntryRef(i).removeCourse(j);
                    std::cout << "Student " << studentId << " has been withdrawn from the course " << courseId << std::endl;
                    return;
                }
            }
            std::cout << "Student " << studentId << " is not enrolled in course " << courseId << std::endl;
            return;
        }
    }


    std::cout << "Student " << studentId << " does not exist" << std::endl;
}

void RegistrationSystem::cancelCourse(const int courseId) 
{
    bool found = false;
    for(int i = 1; i <= students_.getLength(); ++i)
    {
        for(int j = 1; j < students_.getEntryRef(i).getCourses().getLength(); j++)
        {
            if(students_.getEntryRef(i).getCourses().getEntry(j).getCourseId() == courseId)
            {
                students_.getEntryRef(i).getCourses().remove(j);
                found = true;
            }
        }
        
    }

    if(found)
    {
        std::cout << "Course " << courseId << " has been cancelled" << std::endl;
    }
    if(!found)
    {
        std::cout << "Course " << courseId << " does not exist" << std::endl;
    }
}

void RegistrationSystem::showStudent(const int studentId)
{
    bool found = false;
    for (int i = 1; i <= students_.getLength(); ++i)
    {
        if (students_.getEntry(i).getId() == studentId)
        {
            found = true;
            std::cout << "Student id First name Last name" << std::endl;
            std::cout << students_.getEntryRef(i).getId() << " " << students_.getEntryRef(i).getFirstName() << " " << students_.getEntryRef(i).getLastName() << std::endl;
            if(students_.getEntryRef(i).getCourses().getLength() != 0)
            {
                std::cout << "Course id Course name" << std::endl;
                for (int j = 1; j <= students_.getEntryRef(i).getCourses().getLength(); ++j)
                {
                    std::cout << students_.getEntryRef(i).getCourses().getEntry(j).getCourseId() << " " << students_.getEntryRef(i).getCourses().getEntry(j).getCourseTitle() << std::endl;       
                }
            }
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student " << studentId << " does not exist" << std::endl;
    }
}

void RegistrationSystem::showCourse(const int courseId)
{
    bool found = false;

    for (int i = 1; i <= students_.getLength(); ++i)
    {
        for (int j = 1; j <= students_.getEntryRef(i).getCourses().getLength(); j++)
        {
            if (students_.getEntryRef(i).getCourses().getEntry(j).getCourseId() == courseId)
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (found)
    {
        std::cout << "Course id Course name" << std::endl;

        for (int i = 1; i <= students_.getLength(); ++i)
        {
            for (int j = 1; j <= students_.getEntryRef(i).getCourses().getLength(); j++)
            {
                if (students_.getEntryRef(i).getCourses().getEntry(j).getCourseId() == courseId)
                {
                    std::cout << courseId << " " << students_.getEntryRef(i).getCourses().getEntry(j).getCourseTitle() << std::endl;
                    std::cout << "Student id First name Last name" << std::endl;
                    for (int k = 1; k <= students_.getLength(); ++k)
                    {
                        for (int l = 1; l <= students_.getEntryRef(k).getCourses().getLength(); ++l)
                        {
                            if (students_.getEntryRef(k).getCourses().getEntry(l).getCourseId() == courseId)
                            {
                                std::cout << students_.getEntryRef(k).getId() << " " << students_.getEntryRef(k).getFirstName() << " " << students_.getEntryRef(k).getLastName() << std::endl;
                            }
                        }
                    }
                    return;
                }
            }
        }
    }

    std::cout << "Course " << courseId << " does not exist" << std::endl;
}


void RegistrationSystem::showAllStudents()
{
    if(students_.getLength() == 0)
    {
        std::cout << "There are no students in the system" << std::endl;
        return;
    }

    std::cout << "Student id First name Last name" << std::endl;
    
    for(int i = 1; i <= students_.getLength(); ++i)
    {
        std::cout << students_.getEntryRef(i).getId() << " " << students_.getEntryRef(i).getFirstName() << " " << students_.getEntryRef(i).getLastName() << std::endl;
        if(students_.getEntryRef(i).getCourses().getLength() != 0) 
        {
            std::cout << "Course id Course name" << std::endl;
            for(int j = 1; j <= students_.getEntryRef(i).getCourses().getLength(); j++)
            {
                std::cout << students_.getEntryRef(i).getCourses().getEntry(j).getCourseId() << " " << students_.getEntryRef(i).getCourses().getEntry(j).getCourseTitle() << std::endl;
            }
        }
    }
}
