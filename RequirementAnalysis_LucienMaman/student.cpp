#include "student.h"
#include "iostream"

Student::Student(std::string name, Curriculum &curri): User(name)
{
curriculum=curri;
}

void Student::addRequestQueue(Request &req, std::vector<Request> &queue)
{
queue.push_back(req);
}

Curriculum Student::getCurriculum() const
{
    return curriculum;
}
