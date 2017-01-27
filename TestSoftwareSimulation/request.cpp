#include "request.h"

Request::Request()
{

}

Request::Request(Job &job, std::string idUs): job(job),idUser(idUs), id(0), start(0.00), startWait(0.00), waitingTime(0.00)
{

}

int Request::getId() const
{
    return id;
}

Job Request::getJob() const
{
    return job;
}

std::string Request::getIdUser() const
{
    return idUser;
}

void Request::setIdRequest(int idReq)
{
    id=idReq;
}

double Request::getStart() const
{
    return start;
}

void Request::setStart(double time)
{
    start=time;
}

double Request::getStartWait() const
{
    return startWait;
}

void Request::setStartWait(double time)
{
    startWait=time;
}

double Request::getWaitingTime() const
{
    return waitingTime;
}

void Request::setWaitingTime(double res)
{
    waitingTime=res;
}
