/** 
* @file      NodeSatir.cpp
* @description  satir listesinin düğüm sınıfı
* @course  2-A
* @assignment 1.odev
* @date  08.11.2022
* @author Enes Buğra Turğut bugra.turgut@ogr.sakarya.edu.tr
*/


#include "NodeSatir.hpp"

NodeSatir::NodeSatir(const int& data,NodeSatir *next =NULL,NodeSatir *prev=NULL)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}
NodeSatir::NodeSatir()
{
    this->data = 0;
    this->next = 0;
    this->prev = 0;
}
NodeSatir::~NodeSatir()
{
    delete next;
    delete prev;
}