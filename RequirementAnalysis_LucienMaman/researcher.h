#ifndef RESEARCHER_H
#define RESEARCHER_H

#include "user.h"
#include "departmentstructure.h"
#include "it_support.h"

class Researcher : public User
{

private:
    DepartmentStructure dpt;
    double personalResource;

public:
    Researcher(std::string name, DepartmentStructure department);

    DepartmentStructure getDpt() const;
    double getPersonalResource() const;
    void setPersonalResource(double amount);
    void askResource(IT_Support &it, double amount, int boolean);

    void addRequestQueue(Request &req, std::vector<Request> &queue);
};

#endif // RESEARCHER_H
