#include <QString>
#include <QtTest>

#include "badinput.h"
#include "unknowtypejob.h"
#include "docopen.h"
#include "dividezero.h"

#include "user.h"
#include "setoffunctions.h"
#include "student.h"
#include "curriculum.h"
#include "job.h"
#include "request.h"
#include "researcher.h"
#include "departmentstructure.h"
#include "it_support.h"
#include "machine.h"
#include "scheduler.h"

const int NB_NODES=128;

const double COST_INTERACTIVEQUEUE=200;
const double OPERATING_COST_SHORT=500;
const double OPERATING_COST_MEDIUM=600;
const double OPERATING_COST_LARGE=700;
const double OPERATING_COST_HUGE=800;

class TestSoftwareSimulationTest : public QObject
{
    Q_OBJECT

public:
    TestSoftwareSimulationTest();

private Q_SLOTS:

    //Random Tests
    void testRandomInt_data();
    void testRandomInt();
    void testRandomDouble_data();
    void testRandomDouble();

    //Setter tests on the job class
    void testSetterJob_data();
    void testSetterJob();

    //Production of request tests
    void testUserProduceRequest_data();
    void testUserProduceRequest();

    //IT give resources
    void testITGiveResource_data();
    void testITGiveResource();

    //Researcher ask Resources
    void testResearcherAskResources_data();
    void testResearcherAskResources();

    //Tests on the machine
    void testMachineIsAvailable_data();
    void testMachineIsAvailable();

    void testMachineUpdate();

    //Tests on the scheduler  
    void testSendMachine_data();
    void testSendMachine();

    void testRandomRequest_data();
    void testRandomRequest();

    //Tests on all constructors
    void testAllConstructors();

};

TestSoftwareSimulationTest::TestSoftwareSimulationTest()
{
}


void TestSoftwareSimulationTest::testRandomInt_data()
{
        QTest::addColumn<int>("low");
        QTest::addColumn<int>("high");
        QTest::addColumn<int>("nb");

        QTest::newRow("No difference") << 0 << 0 << 100;
        QTest::newRow("Little difference") << 0 << 1 << 100;
        QTest::newRow("Big difference") << 0 << 1000 << 100;
        QTest::newRow("Negative") << -50 << 50 << 100;
        QTest::newRow("High number of repetition") << 0 << 100 << 1000;
}

void TestSoftwareSimulationTest::testRandomInt()
{
    QFETCH(int, low);
    QFETCH(int, high);
    QFETCH(int, nb);

    int res(nb+1);
    for(int i=0;i<nb;i++)
    {
       res=SetOfFunctions::randomInt(low,high);
     QVERIFY2(res<=high && res>=low, "FAILURE");
    }
}

void TestSoftwareSimulationTest::testRandomDouble_data()
{
        QTest::addColumn<double>("low");
        QTest::addColumn<double>("high");
        QTest::addColumn<int>("nb");

        QTest::newRow("No difference") << 0.00 << 0.00 << 100;
        QTest::newRow("Little difference") << 0.00 << 1.00 << 100;
        QTest::newRow("Big difference") << 0.00 << 1000.00 << 100;
        QTest::newRow("Negative") << -50.00 << 50.00 << 100;
        QTest::newRow("High number of repetition") << 0.00 << 100.00 << 1000;
}

void TestSoftwareSimulationTest::testRandomDouble()
{
    QFETCH(double, low);
    QFETCH(double, high);
    QFETCH(int, nb);

    double res(nb+1.00);
    for(int i=0;i<nb;i++)
    {
     res=SetOfFunctions::randomDouble(low,high);
     QVERIFY2(res<=high && res>=low, "FAILURE");
    }
}

void TestSoftwareSimulationTest::testSetterJob_data()
{
    double duration=SetOfFunctions::randomDouble(0,1.68);

    QTest::addColumn<int>("type");
    QTest::addColumn<int>("amount");
    QTest::addColumn<double>("duration");

    QTest::newRow("Short, negative amount") << 1 << SetOfFunctions::randomInt(-2048,-1)<< duration;
    QTest::newRow("Short, null amount") << 1 << 0<< duration;
    QTest::newRow("Short, positive amount") << 1 <<SetOfFunctions::randomInt(1,2048)<< duration;

    QTest::newRow("Interactive, negative amount") << 2 << SetOfFunctions::randomInt(-2048,-1)<< duration;
    QTest::newRow("Interactive, null amount") << 2 << 0<< duration;
    QTest::newRow("Interactive, positive amount") << 2<<SetOfFunctions::randomInt(1,2048)<< duration;

    QTest::newRow("Medium, negative amount") << 3 << SetOfFunctions::randomInt(-2048,-1)<< duration;
    QTest::newRow("Medium, null amount") << 3 << 0<< duration;
    QTest::newRow("Medium, positive amount") << 3<<SetOfFunctions::randomInt(1,2048)<< duration;

    QTest::newRow("Large, negative amount") << 4 << SetOfFunctions::randomInt(-2048,-1)<< duration;
    QTest::newRow("Large, null amount") << 4 << 0<< duration;
    QTest::newRow("Large, positive amount") << 4<<SetOfFunctions::randomInt(1,2048)<< duration;

    QTest::newRow("Huge, negative amount") << 5 << SetOfFunctions::randomInt(-2048,-1)<< duration;
    QTest::newRow("Huge, null amount") << 5 << 0<< duration;
    QTest::newRow("Huge, positive amount") << 5 <<SetOfFunctions::randomInt(1,2048)<< duration;
}

void TestSoftwareSimulationTest::testSetterJob()
{
    QFETCH(int, type);
    QFETCH(int, amount);
    QFETCH(double, duration);

    Job job(typeJob::Short,0,duration);

    switch(type)
    {
    case 1:
        //nothing
        break;
    case 2:
        job.setTypeJob(typeJob::Interactive);
        break;
    case 3:
        job.setTypeJob(typeJob::Medium);
        break;
    case 4:
        job.setTypeJob(typeJob::Large);
        break;
    case 5:
        job.setTypeJob(typeJob::Huge);
        break;
    }

    int initCore=job.getNbCoreRequested(),endCore;

    if(amount<0)
    {
        QVERIFY_EXCEPTION_THROWN(job.setCore(amount),BadInput);
    }
    else if (amount==0)
    {
        job.setCore(amount);
        endCore=job.getNbCoreRequested();
        QVERIFY2(initCore==endCore, "FAILURE");//same number of core
    }
    else
    {
         job.setCore(amount);
         endCore=job.getNbCoreRequested();
         QVERIFY2((initCore!=endCore)&&(endCore==amount), "FAILURE");//amount updated
    }
}

void TestSoftwareSimulationTest::testUserProduceRequest_data()
{
    int core=SetOfFunctions::randomInt(0,100);
    double hour=SetOfFunctions::randomDouble(0,100);

    QTest::addColumn<int>("type");
    QTest::addColumn<int>("core");
    QTest::addColumn<double>("hour");
    QTest::addColumn<int>("user");


    QTest::newRow("Short request-Student") << 1 << core << hour<<1 ;
    QTest::newRow("Interactive request-Student") << 2 << core << hour<<1 ;
    QTest::newRow("Medium request-Student") << 3 << core << hour<<1 ;
    QTest::newRow("Large request-Student") << 4 << core << hour<<1 ;
    QTest::newRow("Huge request-Student") << 5 << core << hour<<1 ;

    QTest::newRow("Short request-Researcher") << 1 << core << hour<<2 ;
    QTest::newRow("Interactive request-Researcher") << 2 << core << hour<<2 ;
    QTest::newRow("Medium request-Researcher") << 3 << core << hour<<2 ;
    QTest::newRow("Large request-Researcher") << 4 << core << hour<<2 ;
    QTest::newRow("Huge request-Researcher") << 5 << core << hour<<2 ;
}

void TestSoftwareSimulationTest::testUserProduceRequest()
{
    QFETCH(int, type);
    QFETCH(int, core);
    QFETCH(double, hour);
    QFETCH(int, user);

    Job job(typeJob::Short,core,hour);
    switch(type)
    {
    case 1:
        //nothing
        break;
    case 2:
        job.setTypeJob(typeJob::Interactive);
        break;
    case 3:
        job.setTypeJob(typeJob::Medium);
        break;
    case 4:
        job.setTypeJob(typeJob::Large);
        break;
    case 5:
        job.setTypeJob(typeJob::Huge);
        break;
    }
    if(user==1)
    {
        Curriculum setc;
        Student lucien_Maman("Lucien Maman", setc);
        Request req=lucien_Maman.produceRequest(job);

        //Test if all parameters of the job included in the request are the same
        QVERIFY(req.getJob().getTypeJob()==job.getTypeJob());
        QVERIFY(req.getJob().getNbCoreRequested()==job.getNbCoreRequested());
        QVERIFY(req.getJob().getDurationRequested()==job.getDurationRequested());
    }
    else if(user==2)
    {
        DepartmentStructure aerospace;
        Researcher lucienMaman("Lucien Maman Fringand", aerospace);
        Request req2=lucienMaman.produceRequest(job);

        //Test if all parameters of the job included in the request are the same
        QVERIFY(req2.getJob().getTypeJob()==job.getTypeJob());
        QVERIFY(req2.getJob().getNbCoreRequested()==job.getNbCoreRequested());
        QVERIFY(req2.getJob().getDurationRequested()==job.getDurationRequested());
    }
}

void TestSoftwareSimulationTest::testITGiveResource_data()
{
    QTest::addColumn<int>("boolean");

    QTest::newRow("False") << 0 ;
    QTest::newRow("True") << 1 ;
    QTest::newRow("Other") << SetOfFunctions::randomInt(2,100) ;
}

void TestSoftwareSimulationTest::testITGiveResource()
{
    QFETCH(int, boolean);

    IT_Support it("Lucien Maman");
    bool res;
    if(boolean==0)
    {
        res=it.giveResource(boolean);
        QVERIFY2(!res, "FAILURE");//check if the output is the same
    }
    else if(boolean==1)
    {
        res=it.giveResource(boolean);
        QVERIFY2(res, "FAILURE");//check if the output is the same
    }
    else
    {
        //Test if the exception is thrown
        QVERIFY_EXCEPTION_THROWN(it.giveResource(boolean),BadInput);//check if the exception is thrown
    }
}

void TestSoftwareSimulationTest::testResearcherAskResources_data()
{
    QTest::addColumn<double>("amount");
    QTest::addColumn<int>("boolean");

    double amount=SetOfFunctions::randomDouble(0.1,100);

    QTest::newRow("False") << amount << 0;
    QTest::newRow("True") << amount << 1 ;
    QTest::newRow("Other") << amount << SetOfFunctions::randomInt(2,100) ;

    QTest::newRow("Negative amount - True") << - amount << 1 ;
    QTest::newRow("High positive amount - True") << 1250.00 << 1 ;
    QTest::newRow("Null amount - True") << 0.00 << 1 ;
}

void TestSoftwareSimulationTest::testResearcherAskResources()
{
    QFETCH(double, amount);
    QFETCH(int, boolean);

    IT_Support it("Salvatore");
    DepartmentStructure dpt;
    Researcher researcher("Lucien",dpt);
    researcher.setPersonalResource(10.00);
    double resBegin=researcher.getPersonalResource();

    if(amount<0 || (!(boolean==0 || boolean==1)))
    {
        QVERIFY_EXCEPTION_THROWN(researcher.askResource(it,amount,boolean),BadInput);//check if the exception is thrown
    }

    else if(boolean==0)
    {
        researcher.askResource(it,amount,boolean);
        double resEnd=researcher.getPersonalResource();
        QVERIFY2(resEnd==resBegin, "FAILURE");
    }
    else
    {
        researcher.askResource(it,amount,boolean);
        double resEnd=researcher.getPersonalResource();

        QVERIFY2(resEnd==resBegin+amount, "FAILURE");
    }
}

void TestSoftwareSimulationTest::testMachineIsAvailable_data()
{
    QTest::addColumn<int>("nbJob");
    QTest::addColumn<int>("type");

    QTest::newRow("Short-Not available") << 33 << 1 ;
    QTest::newRow("Short-Available") << SetOfFunctions::randomInt(1,31) << 1 ;
    QTest::newRow("Short-Equal") << 32 << 1 ;

    QTest::newRow("Interactive-Not available") << 33 << 2 ;
    QTest::newRow("Interactive-Available") << SetOfFunctions::randomInt(1,31) << 2 ;
    QTest::newRow("Interactive-Equal") << 32 << 2 ;

    QTest::newRow("Medium-Not available") << 204 << 3 ;
    QTest::newRow("Medium-Available") << SetOfFunctions::randomInt(1,203) << 3 ;
    QTest::newRow("Medium-Equal") << 203 << 3;

    QTest::newRow("Large-Not available") << 1025 << 4;
    QTest::newRow("Large-Available") << SetOfFunctions::randomInt(1,1023) << 4 ;
    QTest::newRow("Large-Equal") << 1024 << 4 ;

    QTest::newRow("Huge-Not available") << 2049 << 5 ;
    QTest::newRow("Huge-Available") << SetOfFunctions::randomInt(1,2047) << 5 ;
    QTest::newRow("Huge-Equal") << 2048 << 5 ;

}

void TestSoftwareSimulationTest::testMachineIsAvailable()
{
    QFETCH(int, nbJob);
    QFETCH(int, type);

    Machine machine(128);

    switch(type)
    {
    case 1:
       if(machine.getNbCoreAvailable(typeJob::Short)<nbJob)//machine not available
       {
            QVERIFY2(!(machine.isAvailable(nbJob,typeJob::Short)), "FAILURE");
       }
       else  QVERIFY2(machine.isAvailable(nbJob,typeJob::Short), "FAILURE");

        break;

    case 2:
        if(machine.getNbCoreAvailable(typeJob::Interactive)<nbJob)
        {
             QVERIFY2(!(machine.isAvailable(nbJob,typeJob::Interactive)), "FAILURE");//machine not available
        }
        else  QVERIFY2(machine.isAvailable(nbJob,typeJob::Interactive), "FAILURE");
        break;

    case 3:
        if(machine.getNbCoreAvailable(typeJob::Medium)<nbJob)
        {
             QVERIFY2(!(machine.isAvailable(nbJob,typeJob::Medium)), "FAILURE");//machine not available
        }
        else  QVERIFY2(machine.isAvailable(nbJob,typeJob::Medium), "FAILURE");
        break;

    case 4:
        if(machine.getNbCoreAvailable(typeJob::Large)<nbJob)
        {
             QVERIFY2(!(machine.isAvailable(nbJob,typeJob::Large)), "FAILURE");//machine not available
        }
        else  QVERIFY2(machine.isAvailable(nbJob,typeJob::Large), "FAILURE");
        break;

    case 5:
        if(machine.getNbCoreAvailable(typeJob::Huge)<nbJob)
        {
             QVERIFY2(!(machine.isAvailable(nbJob,typeJob::Huge)), "FAILURE");//machine not available
        }
        else  QVERIFY2(machine.isAvailable(nbJob,typeJob::Huge), "FAILURE");
        break;
    }
}

void TestSoftwareSimulationTest::testMachineUpdate()
{
    //TEST for each type of request the process when the machine is available and when a request is finished
    Machine machine(128);
    double time=0.5;
    std::vector<std::vector<Request>> listMachine(4),listQueue(4);
    std::vector<int> res(4);
    res={0,0,0,0};
    Job job(typeJob::Short,1,0.2);

    for(int i=0;i<4;i++)
    {
        if(i==0)
        {
            Request req(job,"Lucien");
            req.setStart(0.4);

            listMachine[i].push_back(req);
            listMachine[i+1].resize(0);
            listMachine[i+2].resize(0);
            listMachine[i+3].resize(0);

            listQueue[i].push_back(req);
            listQueue[i+1].resize(0);
            listQueue[i+2].resize(0);
            listQueue[i+3].resize(0);
        }
        else if(i==1)
        {
            job.setTypeJob(typeJob::Medium);
            Request req(job,"Lucien");
            req.setStart(0.4);

            listMachine[i].push_back(req);
            listMachine[i-1].resize(0);
            listMachine[i+1].resize(0);
            listMachine[i+2].resize(0);

            listQueue[i].push_back(req);
            listQueue[i-1].resize(0);
            listQueue[i+1].resize(0);
            listQueue[i+2].resize(0);
        }
        else if(i==2)
        {
            job.setTypeJob(typeJob::Large);
            Request req(job,"Lucien");
            req.setStart(0.4);

            listMachine[i].push_back(req);
            listMachine[i-2].resize(0);
            listMachine[i-1].resize(0);
            listMachine[i+1].resize(0);

            listQueue[i].push_back(req);
            listQueue[i-2].resize(0);
            listQueue[i-1].resize(0);
            listQueue[i+1].resize(0);
        }
        else if(i==3)
        {
            job.setTypeJob(typeJob::Huge);
            Request req(job,"Lucien");
            req.setStart(0.4);

            listMachine[i].push_back(req);
            listMachine[i-3].resize(0);
            listMachine[i-2].resize(0);
            listMachine[i-1].resize(0);

            listQueue[i].push_back(req);
            listQueue[i-3].resize(0);
            listQueue[i-2].resize(0);
            listQueue[i-1].resize(0);
        }

        int sizeInitM=(int)listMachine[i].size();
        int sizeInitQ=(int)listQueue[i].size();

        res=machine.update(time,listMachine,listQueue);

        int sizeEndM=(int)listMachine[i].size();
        int sizeEndQ=sizeInitQ+res[i];

        QVERIFY2((sizeEndM==sizeInitM-1)&&(sizeInitQ==sizeEndQ-1),"FAILURE");
    }

    //TEST is machine is not available and if the job in the machine is not finished
   Job jobToHeavy(typeJob::Short,500,1.5);
   Job jobNotFinished(typeJob::Short,1,0.2);
   Request reqToHeavy(jobToHeavy,"Lucien");
   Request reqNotFinished(jobNotFinished,"Lucien2");
   reqNotFinished.setStart(0.00);
   res={0,0,0,0};

   listQueue[0].push_back(reqToHeavy);
   listMachine[0].push_back(reqNotFinished);
   listQueue[1].resize(0);
   listQueue[2].resize(0);
   listQueue[3].resize(0);

   int sizeInit=(int)listMachine[0].size();
   int sizeInit2=(int)listQueue[0].size();

   res=machine.update(time,listMachine,listQueue);

   int sizeEnd=(int)listMachine[0].size();
   int sizeEnd2=sizeInit2+res[0];

   QVERIFY2((sizeEnd==sizeInit)&&(sizeInit2==sizeEnd2),"FAILURE");
}

void TestSoftwareSimulationTest::testSendMachine_data()
{

    QTest::addColumn<bool>("boolean");
    QTest::addColumn<int>("typeofJob");
    QTest::addColumn<int>("typeUser");

    QTest::newRow("Short- Available - Student") << true << 1 << 1;
    QTest::newRow("Short- Available - Researcher") << true << 1 << 2;
    QTest::newRow("Short- Not available - Student") << false << 1 << 1;
    QTest::newRow("Short- Not available - Researcher") << false << 1 << 2;

    QTest::newRow("Medium- Available - Student") << true << 2 << 1;
    QTest::newRow("Medium- Available - Researcher") << true << 2 << 2;
    QTest::newRow("Medium- Not available - Student") << false << 2 << 1;
    QTest::newRow("Medium- Not available - Researcher") << false << 2 << 2;

    QTest::newRow("Large- Available - Student") << true << 3 << 1;
    QTest::newRow("Large- Available - Researcher") << true << 3 << 2;
    QTest::newRow("Large- Not available - Student") << false << 3 << 1;
    QTest::newRow("Large- Not available - Researcher") << false << 3 << 2;

    QTest::newRow("Huge- Available - Student") << true << 4 << 1;
    QTest::newRow("Huge- Available - Researcher") << true << 4 << 2;
    QTest::newRow("Huge- Not available - Student") << false << 4 << 1;
    QTest::newRow("Huge- Not available - Researcher") << false << 4 << 2;
}

void TestSoftwareSimulationTest::testSendMachine()
{
    QFETCH(bool, boolean);
    QFETCH(int, typeofJob);
    QFETCH(int, typeUser);

    setOfParameter set;
    set.nbStudentSETC=1000;
    set.nbStudentEnergy=1000;
    set.nbStudentPhdAero=1000;

    set.nbResearcherDefense=1000;
    set.nbResearcherAero=1000;
    set.nbResearcherEnv=1000;

    set.nbIT=1;

    set.nbWeek=1;

    set.amountSETC=1000;
    set.amountEnergy=1000;
    set.amountPhdAero=1000;

    set.amountDefense=1000;
    set.amountAeroResearch=1000;
    set.amountEnv=1000;

    Scheduler scheduler(set);

    Job job(typeJob::Short,1,0.1);
    typeJob type;
    double time=0.0;
    int randomNbUser=SetOfFunctions::randomInt(0,999);
    int indice=0;
    int nb(0);

    switch(typeofJob)
    {
    case 1:
        nb=-32;
        type=typeJob::Short;
        break;
    case 2:
        nb=-204;
        type=typeJob::Medium;
        job.setTypeJob(typeJob::Medium);
        indice=1;
        break;
    case 3:
        nb=-1024;
        type=typeJob::Large;
        job.setTypeJob(typeJob::Large);
        indice=2;
        break;
    case 4:
        nb=-2048;
        type=typeJob::Huge;
        job.setTypeJob(typeJob::Huge);
        indice=3;
        break;
    }
    Request req(job,"Lucien Maman");
    if(boolean)
    {
        scheduler.getMachine().setNbCoreAvailable(nb, typeJob::Short);
        scheduler.sendMachineOrStore(job,req,time,typeUser,randomNbUser);
        QVERIFY2(req.getStart()== time,"FAILURE");
        QVERIFY2(req.getWaitingTime()== req.getStart()-req.getStartWait(),"FAILURE");
    }
    else if (!boolean)
    {
        scheduler.getMachine().setNbCoreAvailable(nb,type);

        if(typeUser==1 || typeUser==2)
        {
            QVERIFY2(req.getStartWait()== time,"FAILURE");
        }
    }
}

void TestSoftwareSimulationTest::testRandomRequest_data()
{
    QTest::addColumn<int>("nbS");
    QTest::addColumn<int>("nbR");

    QTest::newRow("Only students") << 1000 << 0;
    QTest::newRow("Only researchers") << 0 << 1000;
}

void TestSoftwareSimulationTest::testRandomRequest()
{
    QFETCH(int, nbS);
    QFETCH(int, nbR);

    setOfParameter set;
    set.nbStudentSETC=nbS;
    set.nbStudentEnergy=nbS;
    set.nbStudentPhdAero=nbS;

    set.nbResearcherDefense=nbR;
    set.nbResearcherAero=nbR;
    set.nbResearcherEnv=nbR;

    set.nbIT=1;

    set.nbWeek=1;

    set.amountSETC=nbS;
    set.amountEnergy=nbS;
    set.amountPhdAero=nbS;

    set.amountDefense=nbR;
    set.amountAeroResearch=nbR;
    set.amountEnv=nbR;

    Scheduler scheduler(set);
    double time(0.5);
    scheduler.randomRequest(time);
    if(nbS==0)
    {
        QVERIFY2(scheduler.getUser()==2,"FAILURE");
    }else if(nbR==0)
    {
        QVERIFY2(scheduler.getUser()==1,"FAILURE");
    }
}

void TestSoftwareSimulationTest::testAllConstructors()
{
    //Test all initialisations

    //Curriculum
    Curriculum test;
    QVERIFY2((test.getName()=="") && (test.getResource()==0.00), "FAILURE");

    //DepartmentStructure
    DepartmentStructure test2;
    QVERIFY2((test2.getName()=="") && (test2.getResource()==0.00), "FAILURE");

    //IT_Support
    IT_Support test3("Lucien Maman");
    QVERIFY2(test3.getID()=="Lucien Maman", "FAILURE");

    //Job
    Job test4S(typeJob::Short,1,1.2);
    Job test4I(typeJob::Interactive,1,1.2);
    Job test4M(typeJob::Medium,1,1.2);
    Job test4L(typeJob::Large,1,1.2);
    Job test4H(typeJob::Huge,1,1.2);

    QVERIFY2((test4S.getTypeJob()==typeJob::Short) && (test4S.getNbCoreRequested()==1) && (test4S.getDurationRequested()==1.2) && (test4S.getNbCoreMax()==32) && (test4S.getMaxDuration()==0.01) && (test4S.getTypeQueue()==0) && (test4S.getCostResource()==(test4S.getDurationRequested()*250)), "FAILURE");
    QVERIFY2((test4I.getTypeJob()==typeJob::Interactive) && (test4I.getNbCoreRequested()==1) && (test4I.getDurationRequested()==1.2) && (test4I.getNbCoreMax()==32) && (test4I.getMaxDuration()==0.01) && (test4I.getTypeQueue()==0) && (test4I.getCostResource()==(test4I.getDurationRequested()*250)), "FAILURE");
    QVERIFY2((test4M.getTypeJob()==typeJob::Medium) && (test4M.getNbCoreRequested()==1) && (test4M.getDurationRequested()==1.2) && (test4M.getNbCoreMax()==204) && (test4M.getMaxDuration()==0.08) && (test4M.getTypeQueue()==1) && (test4M.getCostResource()==(test4M.getDurationRequested()*350)), "FAILURE");
    QVERIFY2((test4L.getTypeJob()==typeJob::Large) && (test4L.getNbCoreRequested()==1) && (test4L.getDurationRequested()==1.2) && (test4L.getNbCoreMax()==1024) && (test4L.getMaxDuration()==0.16) && (test4L.getTypeQueue()==2) && (test4L.getCostResource()==(test4L.getDurationRequested()*450)), "FAILURE");
    QVERIFY2((test4H.getTypeJob()==typeJob::Huge) && (test4H.getNbCoreRequested()==1) && (test4H.getDurationRequested()==1.2) && (test4H.getNbCoreMax()==2048) && (test4H.getMaxDuration()==0.64) && (test4H.getTypeQueue()==3) && (test4H.getCostResource()==(test4H.getDurationRequested()*500)), "FAILURE");

    //Machine
    Machine test5(128);
    QVERIFY2((test5.getNbNode()==128) && (test5.getNbCoreAvailable(typeJob::Short)==204) && (test5.getNbCoreAvailable(typeJob::Medium)==614) && (test5.getNbCoreAvailable(typeJob::Large)==1024) && (test5.getNbCoreAvailable(typeJob::Huge)==2048),"FAILURE");

    // Request
    Request test6(test4S,"Lucien Maman");
    QVERIFY2((test6.getIdUser()=="Lucien Maman") && (test6.getId()==0) && (test6.getStart()==0.00) && (test6.getStartWait()==0.00) && (test6.getWaitingTime()==0.00),"FAILURE");

    //Researcher
    Researcher test7("Lucien Maman",test2);
    QVERIFY2((test7.getID()=="Lucien Maman") && (test7.getDpt().getName()==test2.getName()) && (test7.getPersonalResource()==0.00),"FAILURE");

    //Student
    Student test8("Lucien Maman",test);
    QVERIFY2((test8.getID()=="Lucien Maman") && (test8.getCurriculum().getName()==test.getName()),"FAILURE");

    //Scheduler
 //Creation of the set of parameters corresponding to the default simulation
    setOfParameter set;
    set.nbStudentSETC=1000;
    set.nbStudentEnergy=1000;
    set.nbStudentPhdAero=1000;

    set.nbResearcherDefense=1000;
    set.nbResearcherAero=1000;
    set.nbResearcherEnv=1000;

    set.nbIT=1;

    set.nbWeek=1;

    set.amountSETC=1000;
    set.amountEnergy=1000;
    set.amountPhdAero=1000;

    set.amountDefense=1000;
    set.amountAeroResearch=1000;
    set.amountEnv=1000;

    Scheduler test9(set);
    std::vector<double> res=test9.getParametersDouble();

    QVERIFY2(res[0]==OPERATING_COST_SHORT+OPERATING_COST_MEDIUM+OPERATING_COST_LARGE+OPERATING_COST_HUGE,"FAILURE");
    QVERIFY2(res[1]==0.00,"FAILURE");
    QVERIFY2(res[2]==0.00,"FAILURE");
    QVERIFY2(res[3]==0.00,"FAILURE");
    QVERIFY2(res[4]==0.00,"FAILURE");
    QVERIFY2(res[4]==0.00,"FAILURE");
    QVERIFY2(res[4]==0.00,"FAILURE");
    QVERIFY2(test9.getMachine().getNbNode()==128,"FAILURE");
}

QTEST_APPLESS_MAIN(TestSoftwareSimulationTest)

#include "tst_testsoftwaresimulationtest.moc"
