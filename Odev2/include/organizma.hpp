#ifndef ORGANIZMA_HPP
#define ORGANIZMA_HPP

#include "sistem.hpp"

class Organizma
{
private:
    int capacity;
    int length;
    void reserve(int);

public:   
    Sistem** organizma;
    Organizma();
    void add(Sistem*);
    int size();
    ~Organizma();
};

#endif
