#ifndef DOKU_HPP
#define DOKU_HPP

#include "hucre.hpp"

class Doku
{
private:
  
    int length;
    int orta;
    Hucre** dokular;
public: 
    Doku(int);
    Doku(Doku&);
    void mutation();
    void add(Hucre*);
    int getOrta();
    void setOrta(int);
    int ortagetir();
    int* dokuHucreleri();
    int size();
    ~Doku();
};

#endif