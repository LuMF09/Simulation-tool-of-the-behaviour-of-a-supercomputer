#ifndef DIVIDEZERO_H
#define DIVIDEZERO_H

#include <exception>
#include <string>

class DivideZero : public std::exception
{
private:
    std::string s;

public:

    DivideZero(std::string a);
    virtual char const* what() const;
};
#endif // DIVIDEZERO_H
