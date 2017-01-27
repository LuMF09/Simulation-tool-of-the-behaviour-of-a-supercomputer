#ifndef JOB_H
#define JOB_H

enum class typeJob { Short, Interactive, Medium, Large, Huge };

class Job
{
private:
    int nbCoreMax, nbCoreRequested, typeQueue;
    typeJob typeOfJob;
    double maxDuration, durationRequested;
    double costResource;

public:
    Job();
    Job(typeJob type, int nbCore, double duration);

    typeJob getTypeJob() const;
    int getTypeQueue() const;
    double getCostResource() const;
    int getNbCoreMax() const;
    double getMaxDuration() const;
    double getDurationRequested() const;
    int getNbCoreRequested() const;

    void setTypeJob(typeJob type);
    void setCore(int amount);
    void setDuration(double time);
    void setCostResource(int cost);
};

#endif // JOB_H
