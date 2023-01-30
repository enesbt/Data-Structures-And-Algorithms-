/** 
* @file organizma.cpp
* @description sistem nesnelerini tutan sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 14.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "organizma.hpp"


Organizma::Organizma() //kurucu
{
    length = 0;
    capacity = 0;
    organizma = new Sistem *[capacity];
}

void Organizma::reserve(int newCapacity) //arraylist genisletme
{
    if (capacity >= newCapacity) return;
    Sistem** tmp = new Sistem*[newCapacity];
    for (int i = 0; i < length; i++)
    {
        tmp[i] = organizma[i];
    }
   
    delete[] organizma;
    organizma = tmp;
    capacity = newCapacity;
}

void Organizma::add(Sistem* sistem)
{
    if (length >= capacity) reserve(capacity + 1);
    organizma[length++] = sistem;
}


int Organizma::size()
{
    return length;
}

Organizma::~Organizma()  //yikici sistemler serbest birakilir
{
    for (int i = 0; i < length; i++)
    {
        delete organizma[i];
    }
    delete[] organizma;
}