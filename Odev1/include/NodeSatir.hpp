#ifndef NODESATIR_HPP
#define NODESATIR_HPP


#include<iostream>
using namespace std;

struct NodeSatir
{
    NodeSatir* next;
    NodeSatir* prev;
    int data;

    NodeSatir(const int& data,NodeSatir *next,NodeSatir *prev);
    ~NodeSatir();
    NodeSatir();

};
#endif
