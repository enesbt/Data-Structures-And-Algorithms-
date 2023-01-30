#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP


#include "NodeYonetici.hpp"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>
#include <math.h>
#include<string>
#include<sstream>
using namespace std;


class YoneticiListesi
{
    private:
        NodeYonetici* head;
        int length;      
        NodeYonetici* findPrevByPosition(int position);
        void satirdelete();
        void clear();

    public:
        int seciliindex;

        YoneticiListesi();
        bool isEmpty() const;
        void insert(int index,SatirListesi* data);
        void add(SatirListesi* data);
        void remove(SatirListesi* data);
        void removeAt(int index);
        int indexOf(SatirListesi* data);      
        void yazdir(int index,NodeSatir* satir,int sekizli);
        NodeYonetici* first();
        NodeYonetici* last();
        NodeYonetici* getir(int index);
        void satirsil(NodeSatir* satir,int index,YoneticiListesi* yonet);
        void satiryazdir(int index,NodeSatir* satir);
        int satirsayisi(int index);
        int dugumsayisi();
        ~YoneticiListesi();
};

#endif