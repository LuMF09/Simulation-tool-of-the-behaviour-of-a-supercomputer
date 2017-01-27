#include "curriculum.h"

Curriculum::Curriculum() : name(""), resource(0.00)
{

}

std::string Curriculum::getName() const
{
    return name;
}

void Curriculum::setResource(double amount)
{
    resource=amount;
}

void Curriculum::setName(std::string nameUser)
{
    name=nameUser;
}

double Curriculum::getResource() const
{
    return resource;
}
