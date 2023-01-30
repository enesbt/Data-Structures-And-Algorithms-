#ifndef NODEYONETICI_HPP
#define NODEYONETICI_HPP



#include "SatirListesi.hpp"
#include<iostream>
using namespace std;

struct NodeYonetici
{
    SatirListesi* adress;
    NodeYonetici* next;
    NodeYonetici* prev;
    double ortalama;
   
    NodeYonetici(SatirListesi *adress,NodeYonetici* next,NodeYonetici* prev,double ortalama);
    ~NodeYonetici();

};

#endif