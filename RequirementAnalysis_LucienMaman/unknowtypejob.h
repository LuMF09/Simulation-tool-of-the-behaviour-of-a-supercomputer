#ifndef UNKNOWTYPEJOB_H
#define UNKNOWTYPEJOB_H

#include <exception>
#include <string>

class unknowTypeJob : public std::exception
{
private:
    std::string s;

public:

    unknowTypeJob(std::string a);
    virtual char const* what() const;
};

#endif // UNKNOWTYPEJOB_H
