#ifndef SISTEM_HPP
#define SISTEM_HPP

#include "organ.hpp"

class Sistem
{

private:
    int length;
public:    
    Organ** sistem;
    Sistem();
    void add(Organ*);
    ~Sistem();
};
#endif