#include "user.h"

User::User(std::string name): id(name)
{

}

Request User::produceRequest(Job &job)
{
    Request req(job, this->getID());
    return req;
}

std::string User::getID() const
{
    return id;
}
