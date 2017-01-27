#include "scheduler.h"
#include "setoffunctions.h"
#include "dividezero.h"
#include "unknowtypejob.h"
#include "badinput.h"
#include <windows.h>
#include <random>


//Parameters of the machine

const int NB_NODES=128;
const int NB_CORES=16*NB_NODES;

const int NB_CORE_SHORTJOB=2;
const double COST_HUGEQUEUE=500;
const double COST_LARGEQUEUE=450;
const double COST_MEDIUMQUEUE=350;
const double COST_SHORTQUEUE=250;
const double COST_INTERACTIVEQUEUE=200;

const double OPERATING_COST_SHORT=500;
const double OPERATING_COST_MEDIUM=600;
const double OPERATING_COST_LARGE=700;
const double OPERATING_COST_HUGE=800;

Scheduler::Scheduler(setOfParameter set):operatingCost(OPERATING_COST_SHORT+OPERATING_COST_MEDIUM+OPERATING_COST_LARGE+OPERATING_COST_HUGE),turnaroundTime(0.00),totPersonalResource(0.00),totalRequestShort(0),totalRequestMedium(0),totalRequestLarge(0),totalRequestHuge(0), machine(NB_NODES),listAllInMachine(4), listAllQueues(4), nbMH(0.00)
{
    //Creation of all the objects

    //CURRICULUM AND STUCTURES
    setc.setName("Msc SETC");
    setc.setResource(set.amountSETC);

    energy.setName("Msc Energy");
    energy.setResource(set.amountEnergy);

    aerospace.setName("Phd Aerospace");
    aerospace.setResource(set.amountPhdAero);

    defense.setName("Defense and security");
    defense.setResource(set.amountDefense);

    aeroResearch.setName("Aerospace");
    aeroResearch.setResource(set.amountAeroResearch);

    environment.setName("Environment");
    environment.setResource(set.amountEnv);

    //PROFILES
    nbSETC=set.nbStudentSETC;
    nbEnergy=set.nbStudentEnergy;
    nbAeroStudent=set.nbStudentPhdAero;

    //STUDENT
    for(int i=0;i<(set.nbStudentSETC+set.nbStudentEnergy+set.nbStudentPhdAero); i++)
    {
       std::string nbS = std::to_string(i);
        if (i<set.nbStudentSETC)
        {
            Student student("s"+nbS, setc);
            listOfStudent.push_back(student);

        }else if (set.nbStudentSETC+set.nbStudentEnergy)
            {
                Student student("s"+nbS, energy);
                listOfStudent.push_back(student);
            }
        else
        {
            Student student("s"+nbS, aerospace);
            listOfStudent.push_back(student);
        }


    }
    nbDefense=set.nbResearcherDefense;
    nbAeroRes=set.nbResearcherAero;
    nbEnv=set.nbResearcherEnv;

    //RESEARCHER

    for(int i=0;i<(set.nbResearcherDefense+set.nbResearcherAero+set.nbResearcherEnv); i++)
    {
       std::string nbR = std::to_string(i);
        if (i<set.nbResearcherDefense)
        {
            Researcher researcher("r"+nbR, defense);
            listOfResearcher.push_back(researcher);
        }else if (set.nbResearcherDefense+set.nbResearcherAero)
            {
            Researcher researcher("r"+nbR, aeroResearch);
            listOfResearcher.push_back(researcher);
            }
        else
        {
            Researcher researcher("r"+nbR, environment);
            listOfResearcher.push_back(researcher);
        }

    }

    //IT

    for(int i=0; i<set.nbIT;i++)
    {
        std::string nbI = std::to_string(i);
        IT_Support itProfile("i"+nbI);
        listOfIT.push_back(itProfile);
    }

}

//When we push the run button
void Scheduler::startScheduler(int nbtime)
{
    double elapsed(0.00),lambda(0.00);
    clock_t start(0), end(0);
    std::vector<int> cpt(4);
    std::vector<std::vector<int>> res(nbtime);
    std::vector<double> resPrice(6), avWaitingTimeQueue(4);

    double initBudgetSETC=setc.getResource();
    double initBudgetENERGY=energy.getResource();
    double initBudgetPHD=aerospace.getResource();
    double initBudgetDEF=defense.getResource();
    double initBudgetAERO=aeroResearch.getResource();
    double initBudgetENV=environment.getResource();


    for(int i=0; i<nbtime;i++)
    {
        elapsed=0.00;
        start=0;
        end=0;
        totalRequestShort=0;
        totalRequestMedium=0;
        totalRequestLarge=0;
        totalRequestHuge=0;

        while(elapsed <1.68)
        {
            start += clock();

            // update state of the machine
            listAllInMachine[0]=shortInMachine;
            listAllInMachine[1]=mediumInMachine;
            listAllInMachine[2]=largeInMachine;
            listAllInMachine[3]=hugeInMachine;

            listAllQueues[0]=shortQueue;
            listAllQueues[1]=mediumQueue;
            listAllQueues[2]=largeQueue;
            listAllQueues[3]=hugeQueue;

            cpt=machine.update(elapsed,listAllInMachine, listAllQueues);

            //recover state of the machine after the update

            totalRequestShort+=cpt[0];
            totalRequestMedium+=cpt[1];
            totalRequestLarge+=cpt[2];
            totalRequestHuge+=cpt[3];

            shortInMachine=listAllInMachine[0];
            mediumInMachine=listAllInMachine[1];
            largeInMachine=listAllInMachine[2];
            hugeInMachine=listAllInMachine[3];

            shortQueue=listAllQueues[0];
            mediumQueue=listAllQueues[1];
            largeQueue=listAllQueues[2];
            hugeQueue=listAllQueues[3];

            //Creation of the request
            this->randomRequest(elapsed);

            //Know which kind of user
            if(this->getUser()==1)//student
            {
              lambda=1;
            }
            else if(this->getUser()==2)//researcher
            {
              lambda=2;
            }

            else throw BadInput(" in Scheduler::startScheduler, see value of type->getUser()");

            if(lambda==0)
            {
              throw DivideZero("Check lambda in scheduler function : startScheduler");
            }

            Sleep((1/lambda)*50);

            end += clock();

            elapsed = ((double)end - start) / CLOCKS_PER_SEC;
        }

        res[i].push_back(totalRequestShort);
        res[i].push_back(totalRequestMedium);
        res[i].push_back(totalRequestLarge);
        res[i].push_back(totalRequestHuge);
        std::cout<<"Week "<<i+1<<" is finished."<<std::endl;
    }

    resPrice[0]=(initBudgetSETC-setc.getResource());//student SETC
    resPrice[1]=initBudgetENERGY-energy.getResource();//student ENERGY
    resPrice[2]=initBudgetPHD-aerospace.getResource();//student AERO

    resPrice[3]=initBudgetDEF-defense.getResource()+totPersonalResource;//researcher DEFENSE
    resPrice[4]=initBudgetAERO-aeroResearch.getResource()+totPersonalResource;//researcher AERO
    resPrice[5]=initBudgetENV-environment.getResource()+totPersonalResource;//researcher ENVIRONMENT

    if(totalRequestShort==0)
    {
        avWaitingTimeQueue[0]=0;
    } else avWaitingTimeQueue[0]= (waitingShort/totalRequestShort)*100;

    if(totalRequestMedium==0)
    {
        avWaitingTimeQueue[1]=0;
    }else avWaitingTimeQueue[1]= (waitingMedium/totalRequestMedium)*100;

    if(totalRequestLarge==0)
    {
        avWaitingTimeQueue[2]=0;
    }else avWaitingTimeQueue[2]= (waitingLarge/totalRequestLarge)*100;

    if(totalRequestHuge==0)
    {
        avWaitingTimeQueue[3]=0;
    }else avWaitingTimeQueue[3]= (waitingHuge/totalRequestHuge)*100;

    int total=totalRequestShort+totalRequestMedium+totalRequestLarge+totalRequestHuge;

    if(total==0)
    {
        throw DivideZero("You must credit amount to users! Check total value in Scheduler function: startScheduler");
    }

    double avturnaroundTime=turnaroundTime/total;
    double resPriceTot(0);

    for(int i=0; i<resPrice.size();i++)
    {
        resPriceTot+=resPrice[i];
    }
    resPriceTot-=operatingCost;

    SetOfFunctions::writeResults(res,nbMH*100,resPrice,avWaitingTimeQueue,avturnaroundTime,resPriceTot);

    std::cout<<"Simulation is finished, you can find all statistics in the Results.csv file located in the project folder"<<std::endl;

}

//To create a random request
void Scheduler::randomRequest(double time)
{
    if(listOfStudent.size()==0)
    {
        randomTypeUser=2; //researcher
    }
    else if(listOfResearcher.size()==0)
    {
        randomTypeUser=1; // student
    }
    else randomTypeUser=SetOfFunctions::randomInt(1,2); //student or researcher

    int randomNbUser;

    //Create the random job stored in the request
    Job job=this->setJobOfRequest();

    bool enoughResource= false;

    if(randomTypeUser==1)//if student
    {
        randomNbUser=SetOfFunctions::randomInt(0,(int)listOfStudent.size()-1);// to know wich student will produce the request
        Request req= listOfStudent[randomNbUser].produceRequest(job);//request with the job

        //To know wich kind of student it is and to update the global amount related to the cursus

        if(randomNbUser<nbSETC)
        {
            enoughResource=setc.getResource()>job.getCostResource();

            if(enoughResource)
            {
                setc.setResource(setc.getResource()-job.getCostResource());
            }
        }
        else if(randomNbUser>nbEnergy+nbSETC)//phdAero
        {
            enoughResource=aerospace.getResource()>job.getCostResource();

            if(enoughResource)
            {
                aerospace.setResource(aerospace.getResource()-job.getCostResource());
            }
        }
        else
        {
            enoughResource=energy.getResource()>job.getCostResource();

            if(enoughResource)
            {
                energy.setResource(energy.getResource()-job.getCostResource());
            }
        }

        if(enoughResource)//if the resource requested by the job is under or equal to the amount available for the student
        {
            this->sendMachineOrStore(job,req,time,1,randomNbUser);
        }
    }

    else if(randomTypeUser==2)//if researcher
    {
        randomNbUser=SetOfFunctions::randomInt(0,(int)listOfResearcher.size()-1);
        Request req= listOfResearcher[randomNbUser].produceRequest(job);

        //To see which kind of researcher it is and to update the amount available

        if(randomNbUser<nbDefense)
        {
             listOfResearcher[randomNbUser].setPersonalResource(defense.getResource());
             enoughResource=listOfResearcher[randomNbUser].getPersonalResource()>job.getCostResource();

             if(enoughResource)
             {
                 //update resource
                listOfResearcher[randomNbUser].setPersonalResource(-job.getCostResource());
                defense.setResource(defense.getResource()-job.getCostResource());
             }

             else //if not enough resource
             {
                 //random values to ask ressources to a random IT
                 int randomIT=SetOfFunctions::randomInt(0,(int)listOfIT.size()-1);
                 int randomBool=SetOfFunctions::randomInt(0,1);
                 double newAmount=job.getCostResource();

                 listOfResearcher[randomNbUser].askResource(listOfIT[randomIT],newAmount,randomBool);
                 enoughResource=listOfResearcher[randomNbUser].getPersonalResource()>=job.getCostResource();
                 totPersonalResource+=newAmount;
             }
        }
        else if(randomNbUser>nbAeroRes+nbDefense)//Environment
        {
             listOfResearcher[randomNbUser].setPersonalResource(environment.getResource());
             enoughResource=listOfResearcher[randomNbUser].getPersonalResource()>job.getCostResource();

             if(enoughResource)
             {
                 //update resource
                 listOfResearcher[randomNbUser].setPersonalResource(-job.getCostResource());
                 environment.setResource(environment.getResource()-job.getCostResource());
             }
             else //if not enough resource
             {
                 //random values for ask ressources to the IT
                 int randomIT=SetOfFunctions::randomInt(0,(int)listOfIT.size()-1);
                 int randomBool=SetOfFunctions::randomInt(0,1);
                 double newAmount=job.getCostResource();

                 listOfResearcher[randomNbUser].askResource(listOfIT[randomIT],newAmount,randomBool);
                 enoughResource=listOfResearcher[randomNbUser].getPersonalResource()>=job.getCostResource();
                 totPersonalResource+=newAmount;
             }
        }

        else //Aero
        {
             listOfResearcher[randomNbUser].setPersonalResource(aeroResearch.getResource());
             enoughResource=listOfResearcher[randomNbUser].getPersonalResource()>job.getCostResource();

             if(enoughResource)
             {
                 //update resource
                 listOfResearcher[randomNbUser].setPersonalResource(-job.getCostResource());
                 aeroResearch.setResource(aeroResearch.getResource()-job.getCostResource());
             }
             else //if not enough resource
             {
                 //random values for ask ressources to the IT
                 int randomIT=SetOfFunctions::randomInt(0,(int)listOfIT.size()-1);
                 int randomBool=SetOfFunctions::randomInt(0,1);
                 double newAmount=job.getCostResource();

                 listOfResearcher[randomNbUser].askResource(listOfIT[randomIT],newAmount,randomBool);
                 enoughResource=listOfResearcher[randomNbUser].getPersonalResource()>=job.getCostResource();
                 totPersonalResource+=newAmount;
             }
        }

//Amounts are updated, now we will test if request goes into the machine or it is stored in the queue
        if(enoughResource)
        {
            this->sendMachineOrStore(job,req,time,2,randomNbUser);
        }
    }
    else throw BadInput(" in Scheduler::randomRequest, see value of the user choosen");
}

void Scheduler::sendMachineOrStore(Job &job, Request &req, double time,int typeUser,int randomNbUser)
{
     switch(job.getTypeQueue())
     {
     case 0:
         if(machine.isAvailable(job.getNbCoreRequested(), job.getTypeJob()))
         {
             req.setStart(time);
             machine.setNbCoreAvailable(-job.getNbCoreRequested(), job.getTypeJob());
             shortInMachine.push_back(req);
             totalRequestShort++;
             req.setWaitingTime(req.getStart()-req.getStartWait());
             waitingShort+=req.getWaitingTime();
             turnaroundTime+= req.getWaitingTime()/job.getDurationRequested();
             nbMH+=job.getDurationRequested();
         }
         else
         {
             if(typeUser==1)
             {
                 listOfStudent[randomNbUser].addRequestQueue(req,shortQueue);
                 req.setStartWait(time);
             }
             else if(typeUser==2)
                  {
                     listOfResearcher[randomNbUser].addRequestQueue(req,shortQueue);
                     req.setStartWait(time);
                  }
             else throw BadInput("Check typeUser in Scheduler function: sendMachineOrStore");
         }

         break;

     case 1:
         if(machine.isAvailable(job.getNbCoreRequested(), job.getTypeJob()))
         {
             req.setStart(time);
             machine.setNbCoreAvailable(-job.getNbCoreRequested(), job.getTypeJob());
             mediumInMachine.push_back(req);
             totalRequestMedium++;
             req.setWaitingTime(req.getStart()-req.getStartWait());
             waitingMedium+=req.getWaitingTime();
             nbMH+=job.getDurationRequested();
             turnaroundTime+= req.getWaitingTime()/job.getDurationRequested();
         }
         else
         {
             if(typeUser==1)
             {
                 listOfStudent[randomNbUser].addRequestQueue(req,shortQueue);
                 req.setStartWait(time);
             }
             else if(typeUser==2)
                   {
                     listOfResearcher[randomNbUser].addRequestQueue(req,shortQueue);
                     req.setStartWait(time);
                   }
             else throw BadInput("Check typeUser in Scheduler function: sendMachineOrStore");
         }
         break;

     case 2:
         if(machine.isAvailable(job.getNbCoreRequested(), job.getTypeJob()))
         {
             req.setStart(time);
             machine.setNbCoreAvailable(-job.getNbCoreRequested(), job.getTypeJob());
             largeInMachine.push_back(req);
             totalRequestLarge++;
             req.setWaitingTime(req.getStart()-req.getStartWait());
             waitingLarge+=req.getWaitingTime();
             nbMH+=job.getDurationRequested();
             turnaroundTime+= req.getWaitingTime()/job.getDurationRequested();
         }
         else
         {
             if(typeUser==1)
             {
                 listOfStudent[randomNbUser].addRequestQueue(req,shortQueue);
                 req.setStartWait(time);
             }
             else if(typeUser==2)
                   {
                     listOfResearcher[randomNbUser].addRequestQueue(req,shortQueue);
                     req.setStartWait(time);
                   }
             else throw BadInput("Check typeUser in Scheduler function: sendMachineOrStore");
         }
         break;

     case 3:
         if(machine.isAvailable(job.getNbCoreRequested(), job.getTypeJob()))
         {
             req.setStart(time);
             machine.setNbCoreAvailable(-job.getNbCoreRequested(), job.getTypeJob());
             hugeInMachine.push_back(req);
             totalRequestHuge++;
             req.setWaitingTime(req.getStart()-req.getStartWait());
             waitingHuge+=req.getWaitingTime();
             nbMH+=job.getDurationRequested();
             turnaroundTime+= req.getWaitingTime()/job.getDurationRequested();
         }
         else
         {
             if(typeUser==1)
             {
                 listOfStudent[randomNbUser].addRequestQueue(req,shortQueue);
                 req.setStartWait(time);
             }
             else if(typeUser==2)
                   {
                       listOfResearcher[randomNbUser].addRequestQueue(req,shortQueue);
                       req.setStartWait(time);
                   }
             else throw BadInput("Check typeUser in Scheduler function: sendMachineOrStore");

         }
         break;

         default:
           throw BadInput(" in Scheduler::randomRequest, see value of job.getTypeQueue");
     }
}

Job Scheduler::setJobOfRequest()
{
    int randomJobType=SetOfFunctions::randomInt(0,4);//Type of job: short, interactive, medium, large, huge
    typeJob type;
    int cost;

     switch (randomJobType) {

       case 0 :

          type= typeJob::Short;
          cost=COST_SHORTQUEUE;

         break;

       case 1 :
         type= typeJob::Interactive;
         cost=COST_INTERACTIVEQUEUE;

          break;

       case 2 :

         type= typeJob::Medium;
         cost=COST_MEDIUMQUEUE;

         break;

        case 3 :
         type= typeJob::Large;
         cost=COST_LARGEQUEUE;

         break;

        case 4 :

         type= typeJob::Huge;
         cost=COST_HUGEQUEUE;

         break;

     default:
        throw unknowTypeJob("Check type in Scheduler function: randomRequest.");
     }

     Job job(type,0,0);//Creation of the job with the right type
     int randomNbCore=SetOfFunctions::randomInt(1,(int)job.getNbCoreMax());//nb of Core requested
     double randomNbHour=SetOfFunctions::randomDouble(0.01,(double)job.getMaxDuration()); //nb of hour requested

     //Set the job with all random parameters
     job.setCore(randomNbCore);
     job.setDuration(randomNbHour);
     job.setCostResource(cost);

     return job;
}

int Scheduler::getUser() const
{
  return randomTypeUser;
}
