#ifndef BADINPUT_H
#define BADINPUT_H
#include <exception>
#include <string>

class BadInput : public std::exception
{
private:
    std::string s;

public:

    BadInput(std::string a);
    virtual char const* what() const;
};

#endif // BADINPUT_H
