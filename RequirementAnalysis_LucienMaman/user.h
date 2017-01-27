#ifndef USER_H
#define USER_H

#include "job.h"
#include "request.h"
#include <string>
#include <vector>

class User
{
protected:
    std::string id;

public:
    User(std::string name);

    Request produceRequest(Job &job);
    std::string getID() const;

    virtual void addRequestQueue(Request &req, std::vector<Request> &queue)=0;
};

#endif // USER_H
