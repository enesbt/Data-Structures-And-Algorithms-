/** 
* @file      NodeYonetici.cpp
* @description  yonetici listesinin düğüm sınıfı
* @course  2-A
* @assignment 1.odev
* @date  08.11.2022
* @author Enes Buğra Turğut bugra.turgut@ogr.sakarya.edu.tr
*/


#include "NodeYonetici.hpp"

NodeYonetici::NodeYonetici(SatirListesi *adress,NodeYonetici *next=NULL,NodeYonetici *prev=NULL,double ortalama=0)
{
    this->adress = adress;
    this->next = next;
    this->prev= prev;
    this->ortalama = ortalama;
};


NodeYonetici::~NodeYonetici()
{
    delete adress;
    delete next;
    delete prev;
};