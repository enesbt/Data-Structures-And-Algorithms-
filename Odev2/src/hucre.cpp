/** 
* @file hucre.cpp
* @description dna uzunluklarını tutan sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 08.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/


#include "hucre.hpp"

Hucre::Hucre(int dnaUzunluk) //hucre dna uzunluk atamasi yapilir.
{   
    this->dnaUzunluk = dnaUzunluk;
}

Hucre::Hucre(Hucre& hucre)  //hucre sinifi kopyalama kurucusu
{
    dnaUzunluk = hucre.dnaUzunluk;
}

int Hucre::getDnaUzunluk() const //dna uzunluk degeri
{
    return dnaUzunluk;
}


void Hucre::mutation(Hucre& hucre) //dna uzunluk yariya düser
{
    hucre.dnaUzunluk /= 2;
}


Hucre::~Hucre()
{}