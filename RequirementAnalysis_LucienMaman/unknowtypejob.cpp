#include "unknowtypejob.h"
#include <string>
#include <iostream>

// To signal an unknow type of job

//CONSTRUCTOR
unknowTypeJob::unknowTypeJob(std::string a) : s("ERROR! This type of job is not defined." + a){}

//FUNCTION WHAT()
char const* unknowTypeJob::what() const // display a personalized message
{
    return s.c_str();
}
