#include "it_support.h"
#include"badinput.h"

IT_Support::IT_Support(std::string name) : User(name)
{

}

bool IT_Support::giveResource(int boolean)// if a researcher ask for more resources
{
    if (boolean==0)
    {
        return false;
    }
    else if (boolean==1)
    {
        return true;
    }
    else throw BadInput(" in IT_Support::giveResource, see value of boolean");

}

void IT_Support::addRequestQueue(Request &req, std::vector<Request> &queue)
{
    queue.push_back(req);
}
