#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "mainwindow.h"
#include "iostream"
#include "curriculum.h"
#include "departmentstructure.h"
#include "it_support.h"
#include "job.h"
#include "request.h"
#include "researcher.h"
#include "student.h"
#include "cstdlib"
#include "ctime"
#include <vector>
#include<string>
#include "machine.h"

class Scheduler
{
private:
   Curriculum setc,energy, aerospace;
   DepartmentStructure defense, aeroResearch, environment;

   std::vector<Student>listOfStudent;
   std::vector<Researcher>listOfResearcher;
   std::vector<IT_Support>listOfIT;

   std::vector<Request> shortQueue;
   std::vector<Request> mediumQueue;
   std::vector<Request> largeQueue;
   std::vector<Request> hugeQueue;

   std::vector<Request> shortInMachine;
   std::vector<Request> mediumInMachine;
   std::vector<Request> largeInMachine;
   std::vector<Request> hugeInMachine;
   std::vector<std::vector<Request>> listAllInMachine;
   std::vector<std::vector<Request>> listAllQueues;

   Machine machine;

   double operatingCost,nbMH,turnaroundTime, totPersonalResource,waitingShort,waitingMedium,waitingLarge,waitingHuge;
   int totalRequestShort,totalRequestMedium,totalRequestLarge,totalRequestHuge, nbSETC,nbEnergy,nbAeroStudent,nbDefense,nbAeroRes, nbEnv,randomTypeUser;

public:
    Scheduler(setOfParameter set);

    void startScheduler(int nbtime);
    void randomRequest(double time);
    void sendMachineOrStore(Job &job, Request &req, double time,int typeUser,int randomNbUser);
    Job setJobOfRequest();
    int getUser() const;
    std::vector<double>getParametersDouble();
    Machine getMachine();
};

#endif // SCHEDULER_H
