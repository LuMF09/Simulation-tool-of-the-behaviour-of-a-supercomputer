#ifndef CURRICULUM_H
#define CURRICULUM_H

#include <string>

class Curriculum
{
private:
    std::string name;
    double resource;
public:
    Curriculum();

    std::string getName() const;
    double getResource() const;

    void setResource(double amount);
    void setName(std::string nameUser);
};
#endif // CURRICULUM_H
