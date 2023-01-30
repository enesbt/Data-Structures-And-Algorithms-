#ifndef ORGAN_HPP
#define ORGAN_HPP

#include "doku.hpp"
#include "bst.hpp"


class Organ
{
  private:
    Bst* bst;
    bool mutas;

  public:  
    Organ();
    void add(Doku*);
    bool dengeliMi();
    void mutasyonUygula();
    void postOrderArray(Doku**);
    int  rootOrta();
    bool getMutas();
    void setMutas(bool);

    ~Organ();
};




#endif
