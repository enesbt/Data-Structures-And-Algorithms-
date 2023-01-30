#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include<iostream>
#include "doku.hpp"

struct Node
{
    Doku* data;
    Node* left;
    Node* right;
    int middle;
    Node(Doku*, Node*, Node*,int);
    ~Node();
};

#endif
