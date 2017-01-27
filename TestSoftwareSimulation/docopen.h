#ifndef DOCOPEN_H
#define DOCOPEN_H

#include <string>
#include <iostream>

class DocOpen: public std::exception
{
private:
    std::string s;

public:

    DocOpen(std::string a);
    virtual char const* what() const;
};
#endif // DOCOPEN_H
