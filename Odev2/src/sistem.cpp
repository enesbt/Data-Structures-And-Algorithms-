/** 
* @file sistem.cpp
* @description organ nesnelerini tutan sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 15.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "sistem.hpp"

Sistem::Sistem() //sistem kurucusu organlari tutmasi icin dizi newlenir
{
    length = 0;
    sistem = new Organ*[100];
}


void Sistem::add(Organ* organ) //organ ekle
{
    sistem[length++] = organ;
}



Sistem::~Sistem() //yikici
{
    for (int i = 0; i < 100; i++) //sistem icerisindeki organlari serbest birakir
    {
        delete sistem[i];
    }
    delete[] sistem;

}
