#include "departmentstructure.h"

DepartmentStructure::DepartmentStructure(): name(""), resource(0.00)
{

}

std::string DepartmentStructure::getName() const
{
    return name;
}

double DepartmentStructure::getResource() const
{
    return resource;
}

void DepartmentStructure::setName(std::string nam)
{
    name=nam;
}

void DepartmentStructure::setResource(double amount)
{
    resource=amount;
}
