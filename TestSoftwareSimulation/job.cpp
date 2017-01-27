#include "job.h"
#include "iostream"
#include "unknowtypejob.h"
#include "badinput.h"

const int NB_CORES=2048;
const int NB_CORE_SHORTJOB=32;
const double COST_HUGEQUEUE=500;
const double COST_LARGEQUEUE=450;
const double COST_MEDIUMQUEUE=350;
const double COST_SHORTQUEUE=250;
const double COST_INTERACTIVEQUEUE=200;

Job::Job()
{

}

Job::Job(typeJob type, int nbCore, double duration): typeOfJob(type), nbCoreRequested(nbCore),durationRequested(duration)
{
if (typeOfJob == typeJob::Short || typeOfJob == typeJob::Interactive)
{
        nbCoreMax=NB_CORE_SHORTJOB;
        maxDuration=1.00*0.01;
        typeQueue=0;
        costResource=durationRequested*COST_SHORTQUEUE;
}
else if(typeOfJob == typeJob::Medium)
{
    nbCoreMax=(int)(NB_CORES/10);
    maxDuration=8.00*0.01;
    typeQueue=1;
    costResource=durationRequested*COST_MEDIUMQUEUE;
}
else if(typeOfJob == typeJob::Large)
{
    nbCoreMax=(int)(NB_CORES/2);
    maxDuration=16.00*0.01;
    typeQueue=2;
    costResource=durationRequested*COST_LARGEQUEUE;
}
else if (typeOfJob == typeJob::Huge)
{
     nbCoreMax=(int)NB_CORES;
     maxDuration=64*0.01;
    typeQueue=3;
    costResource=durationRequested*COST_HUGEQUEUE;
}
else throw unknowTypeJob("Check type in job constructor.");
}

typeJob Job::getTypeJob() const
{
       return typeOfJob;
}

int Job::getTypeQueue() const
{
    return typeQueue;
}

double Job::getCostResource() const
{
    return costResource;
}

double Job::getMaxDuration() const
{
    return maxDuration;
}

double Job::getDurationRequested() const
{
    return durationRequested;
}

int Job::getNbCoreRequested() const
{
    return this->nbCoreRequested;
}

void Job::setTypeJob(typeJob type)
{
    this->typeOfJob=type;
}

void Job::setCore(int amount)
{
    if(amount<0)
    {
        throw BadInput("in Job function: setCore");
    }
    else this->nbCoreRequested=amount;
}

void Job::setDuration(double time)
{
    if(time<0)
    {
        throw BadInput("in Job function: setDuration");
    }
    this->durationRequested=time;
}

void Job::setCostResource(int cost)
{
    this->costResource=this->getDurationRequested()*cost;
}

int Job::getNbCoreMax() const
{
    return nbCoreMax;
}
