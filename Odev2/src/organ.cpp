/** 
* @file organ.cpp
* @description doku nesneleri tutan sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 11.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "organ.hpp"

Organ::Organ() // kurucu dokulari tutacak agac olusturulur
{
    bst = new Bst();
    mutas = false;
}


bool Organ::getMutas()  //organ mutasyona ugrayip ugramadigi kontrol etmek icin 
{
    return mutas;
}

void Organ::setMutas(bool tru) //organın mutasyona ugradigini belirlermek icin 
{
    mutas = tru;
}

void Organ::add(Doku* doku)
{
    bst->add(doku);
}

int Organ::rootOrta() //kok dugumun siralandiginda ortada kalan elemaninin degeri
{
    return bst->rootOrta();
}

void Organ::mutasyonUygula()
{
    bst->applyMutation();
}

void Organ::postOrderArray(Doku** doku) //agactaki dokuları postorder olarak dokuya ekler
{
    this->bst->postorderToArray(doku);
}


bool Organ::dengeliMi()
{
    return this->bst->isBalanced();
}

Organ::~Organ()
{
    delete bst;
}