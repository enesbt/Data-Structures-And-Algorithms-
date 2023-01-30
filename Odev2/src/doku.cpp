/** 
* @file doku.cpp
* @description hucre nesnelerini tutan sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 09.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/


#include "doku.hpp"

Doku::Doku(int hucreSay)  //kurucu hucre nesnelerini tutmak icin dizi olusturulur. 
{
    length = 0;
    dokular = new Hucre*[hucreSay];
    orta= 0;
}

Doku::Doku(Doku& doku)  // kopya kurucu
{
    length = doku.length;
    dokular = new Hucre*[doku.length];  
    orta = doku.orta;
    for (int i = 0; i < doku.length; i++)  //hucre kopyalari olusturulup dokular dizisine eklenir
    {
        dokular[i] = new Hucre(*doku.dokular[i]);
    }
}

int Doku::size()  
{
    return length;
}

void Doku::add(Hucre* hucre) //hucre ekle
{
    dokular[length++] = hucre;
}

int Doku::getOrta() 
{
    return orta;
}

void Doku::setOrta(int orta)
{
    this->orta = orta;
}


int* Doku::dokuHucreleri()  //hucre nesnelerinin tuttuğu uzunlukları int dizisine çevirir
{
    int* dokuHucreleri = new int[length];
    for (int i = 0; i <length; i++)
    {
        dokuHucreleri[i] = dokular[i]->getDnaUzunluk();
    }
    return dokuHucreleri;
}


void Doku::mutation() //hucre dna uzunluklari ciftse mutasyon fonksiyonu cagrilir.
{
    for (int i = 0; i < length; i++)
    {
        if (dokular[i]->getDnaUzunluk() % 2 == 0)
        {
            dokular[i]->mutation(*dokular[i]);
        }
    }
}


Doku::~Doku() //yikici
{
    for (int i = 0; i < length; i++) //hucre nesneleri serbest birakilir
    {
        delete dokular[i];
    }
    delete[] dokular;
}