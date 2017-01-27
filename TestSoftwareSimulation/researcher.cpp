#include "researcher.h"
#include "badinput.h"

Researcher::Researcher(std::string name, DepartmentStructure department) : User(name), dpt(department), personalResource(0.00)
{

}

void Researcher::askResource(IT_Support &it, double amount, int boolean)//If not enough resource, it can asks for more
{
    if(!(boolean==0 || boolean==1))
    {
        throw BadInput(" in Researcher::askResource, see value of boolean");
    }

    if(it.giveResource(boolean))
    {
        if(amount<0)
        {
            throw BadInput(" in Researcher::askResource, see value of amount (negative)");
        }
        else this->setPersonalResource(amount);
    }
    else this->setPersonalResource(0);
}

DepartmentStructure Researcher::getDpt() const
{
    return dpt;
}

void Researcher::setPersonalResource(double amount)
{
    personalResource+=amount;
}

double Researcher::getPersonalResource() const
{
    return personalResource;
}

void Researcher::addRequestQueue(Request &req, std::vector<Request> &queue)
{
    queue.push_back(req);
}
