#ifndef REQUEST_H
#define REQUEST_H

#include "job.h"
#include <string>

class Request
{
private:
    int id;
    double start, startWait, waitingTime;
    Job job;
    std::string idUser;

public:
    Request();
    Request(Job &job, std::string idUs);

    int getId() const;
    Job getJob() const;
    std::string getIdUser() const;
    double getStart() const;
    double getStartWait() const;
    double getWaitingTime() const;

    void setIdRequest(int idReq);    
    void setStart(double time);   
    void setStartWait(double time);  
    void setWaitingTime(double res);
};

#endif // REQUEST_H
