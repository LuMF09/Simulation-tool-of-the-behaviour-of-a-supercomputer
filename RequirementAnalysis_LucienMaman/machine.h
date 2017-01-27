#ifndef MACHINE_H
#define MACHINE_H
#include "job.h"
#include<vector>
#include "request.h"

class Machine
{
private:
    int nbTotalNode, nbTotalCore, nbCoreAvailableShort, nbCoreAvailableMedium, nbCoreAvailableLarge, nbCoreAvailableHuge;

public:
    Machine(int node);
    int getNbNode() const;
    int getNbCoreAvailable(typeJob type) const;
    void setNbCoreAvailable(int nb, typeJob type);
    bool isAvailable(int nbMax, typeJob type);
    std::vector<int> update(double time, std::vector<std::vector<Request> > &listMachine, std::vector<std::vector<Request> > &listQueue);
};

#endif // MACHINE_H
