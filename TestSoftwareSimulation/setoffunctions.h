#ifndef SETOFFUNCTIONS_H
#define SETOFFUNCTIONS_H

#include <random>
#include <vector>

class SetOfFunctions
{
public:
    static int randomInt(int a, int b);
    static double randomDouble(double a, double b);
    static void writeResults(std::vector<std::vector<int>> list, double nbMH, std::vector<double> resultingPrice, std::vector<double> avWaitTime, double avTurnAround, double economicBalance);
};

#endif // SETOFFUNCTIONS_H
