#ifndef DEPARTMENTSTRUCTURE_H
#define DEPARTMENTSTRUCTURE_H
#include <string>

class DepartmentStructure
{
private:
    std::string name;
    double resource;
public:
    DepartmentStructure();

    std::string getName() const;
    double getResource() const;

    void setName(std::string nam);
    void setResource(double amount);
};

#endif // DEPARTMENTSTRUCTURE_H
