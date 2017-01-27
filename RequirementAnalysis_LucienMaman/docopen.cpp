#include "docopen.h"
#include <string>
#include <iostream>

//DocOpen to signal if the document in which we write results is already open

//CONSTRUCTOR
DocOpen::DocOpen(std::string a) : s("ERROR! The document " + a + " is open. Please close it"){}

//FUNCTION WHAT()
char const* DocOpen::what() const // display a personalized message
{
    return s.c_str();
}
