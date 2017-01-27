#include "machine.h"
#include "iostream"
#include"unknowtypejob.h"

Machine::Machine(int node): nbTotalNode(node)
{
    nbTotalCore=node*16;
    nbCoreAvailableShort=(int)(nbTotalCore*0.1);
    nbCoreAvailableMedium=(int)(nbTotalCore*0.3);
    nbCoreAvailableLarge=(int)(nbTotalCore*0.5);
    nbCoreAvailableHuge=(nbTotalCore);
}

int Machine::getNbNode() const
{
    return nbTotalNode;
}

int Machine::getNbCoreAvailable(typeJob type) const
{
    if (type == typeJob::Short || type == typeJob::Interactive)
    {
        return nbCoreAvailableShort;
    }
    else if(type == typeJob::Medium)
    {
        return nbCoreAvailableMedium;
    }
    else if(type == typeJob::Large)
    {
        return nbCoreAvailableLarge;
    }
    else if (type == typeJob::Huge)
    {
        return nbCoreAvailableHuge;
    }
   else throw unknowTypeJob("Check type in Machine function: getNbCoreAvailable.");
}

void Machine::setNbCoreAvailable(int nb,typeJob type)
{
    if (type == typeJob::Short || type == typeJob::Interactive)
    {
      nbCoreAvailableShort+=nb;
    }
    else if(type == typeJob::Medium)
    {
    nbCoreAvailableMedium+=nb;
    }
    else if(type == typeJob::Large)
    {
    nbCoreAvailableLarge+=nb;
    }
    else if (type == typeJob::Huge)
    {
     nbCoreAvailableHuge+=nb;
    }
    else throw unknowTypeJob("Check type in Machine function: setNbCoreAvailable.");

}

bool Machine::isAvailable(int nbMax,typeJob type)//test if the machine has enough cores available for the job
{
        if(this->getNbCoreAvailable(type)>=nbMax)
        {
            return true;
        }
        else return false;
}

//Update the state of the machine at each production of request and take the first request in the queue
std::vector<int> Machine::update(double time,std::vector<std::vector<Request>> & listMachine,std::vector<std::vector<Request>> & listQueue)
{
    std::vector<int> cpt(4);
    cpt={0,0,0,0};

    for(int i=0;i<listMachine.size();i++)
    {
        for(int j=0;j<listMachine[i].size();j++)
        {
            if(listMachine[i][j].getStart()+listMachine[i][j].getJob().getDurationRequested()>=time)
            {
                this->setNbCoreAvailable(listMachine[i][j].getJob().getNbCoreRequested(),listMachine[i][j].getJob().getTypeJob());//update the nb of core available
                listMachine[i].erase(listMachine[i].begin()+j);//delete the finished request
            }
        }

    }

    for(int i=0; i<listQueue.size();i++)
    {
            for(int j=0; j<listQueue[i].size();j++)
            {

                if(this->isAvailable(listQueue[i][0].getJob().getNbCoreRequested(),listQueue[i][0].getJob().getTypeJob()))//if resources available> resources needed by the first job of the queue
                {
                    listQueue[i][0].setStart(time);
                    this->setNbCoreAvailable(-listQueue[i][0].getJob().getNbCoreRequested(),listQueue[i][0].getJob().getTypeJob());

                    listQueue[i].erase(listQueue[i].begin());

                    if(i==0)
                    {
                       cpt[0]++;
                    }
                    else if(i==1)
                    {
                       cpt[1]++;
                    }
                    else if(i==2)
                    {
                        cpt[2]++;
                    }
                    else cpt[3]++;
                }
            }

    }
    return cpt;//represent the jobs treated
}
