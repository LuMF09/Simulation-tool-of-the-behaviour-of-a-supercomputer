#include "badinput.h"
#include <string>
#include <iostream>

//BadInput to signal if the input expected does not exist

//CONSTRUCTOR
BadInput::BadInput(std::string a) : s("ERROR! Bad input "+ a){}

//FUNCTION WHAT()
char const* BadInput::what() const // display a personalized message
{
    return s.c_str();
}
