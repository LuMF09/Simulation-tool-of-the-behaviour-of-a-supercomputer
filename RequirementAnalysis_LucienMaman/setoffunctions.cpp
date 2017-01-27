#include "setoffunctions.h"
#include"docopen.h"
#include <iostream>
#include <fstream>

int SetOfFunctions::randomInt(int a, int b)
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(a,b);

    return distr(eng);
}

double SetOfFunctions::randomDouble(double a, double b)
{

       std::uniform_real_distribution<double> unif(a,b);
       std::default_random_engine re;

       return unif(re);
}

void SetOfFunctions::writeResults(std::vector<std::vector<int> > nbJobPerWeek, double nbMH, std::vector<double> resultingPrice, std::vector<double> avWaitTime, double avTurnAround, double economicBalance)
{
    std::ofstream file("Results.csv", std::ios::out | std::ios::app);  // write at the end of the file
    if(file)
    {

        for(int i=0; i<nbJobPerWeek.size();i++)
        {

            file<<"Week number:"<<";"<<"Short Jobs"<<";"<<"Medium Jobs"<<";"<<"Large Jobs"<<";"<<"Huge Jobs"<<std::endl;
            file<<i+1<<";";
            for(int j=0; j<nbJobPerWeek[i].size();j++)
            {
                file<<nbJobPerWeek[i][j]<<";";
            }
            file <<std::endl;
        }
        file <<std::endl;

        file<<";"<<"Student SETC"<<";"<<"Student Energy"<<";"<< "Student Aerospace"<<";"<<"Researcher Defense"<<";"<<"Researcher Aerospace"<<";"<<"Researcher Environment"<<std::endl;
        file<<"Resulting price"<<";";
        for(int i=0; i<resultingPrice.size();i++)
        {
            file<<resultingPrice[i]<<";";
        }

        file<<std::endl<<std::endl;

        file<<";"<<"Short queue"<<";"<<"Medium queue"<<";"<<"Large queue"<<";"<<"Huge queue"<<std::endl;
        file<<"Average waiting time (hour):"<<";";

        for(int i=0;i<avWaitTime.size();i++)
        {
            file<<avWaitTime[i]<<";";
        }

        file<<std::endl<<std::endl;

        file<<"Number of machine-hours consumed by user jobs(hour):"<<";"<<nbMH<<std::endl;
        file<<"Average turnaround time ratio:"<<";"<<avTurnAround<<std::endl;
        file<<"Economic balance of the centre"<<";"<<economicBalance<<std::endl;
        file<<std::endl;
        file.close();
    }
    else throw DocOpen("Results.csv");
}
