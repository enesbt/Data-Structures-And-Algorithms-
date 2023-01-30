#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include "NodeSatir.hpp"
#include<iostream>
#include<time.h>
#include<string>
#include<sstream>
#include <iomanip>
using namespace std;

class SatirListesi
{
    private:      
        int length;
        NodeSatir* head;
        NodeSatir* findPrevByPosition(int position);
    public:
        SatirListesi();
        bool isEmpty() const;
        void insert(int index,const int& data);
        void add(const int& data);
        void removeAt(int index);
        void remove(const int& data);
        int indexOf(const int& data);
        int indexOfadress(NodeSatir* satir);
        NodeSatir* first();
        double ortalamaBul();
        int dugumSayisi();
        NodeSatir* getir(int index);
        NodeSatir* rastgelegetir();
        void clear();
        ~SatirListesi();
};

#endif