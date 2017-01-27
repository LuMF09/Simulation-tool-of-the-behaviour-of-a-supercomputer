#ifndef IT_SUPPORT_H
#define IT_SUPPORT_H

#include "user.h"

class IT_Support : public User
{
public:
    IT_Support(std::string name);

    bool giveResource(int boolean);

    void addRequestQueue(Request &req, std::vector<Request> &queue);
};

#endif // IT_SUPPORT_H
