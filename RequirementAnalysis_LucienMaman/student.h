#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "curriculum.h"
#include <string>
#include <vector>

class Student : public User
{
private:
    Curriculum curriculum;

public:
    Student(std::string name, Curriculum &curri);

    Curriculum getCurriculum() const;

    void addRequestQueue(Request &req, std::vector<Request> &queue);
};

#endif // STUDENT_H
