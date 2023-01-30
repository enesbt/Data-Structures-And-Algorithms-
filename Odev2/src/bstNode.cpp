/** 
* @file bstNode.cpp
* @description agac sinifinda kullanilan dugum sinifi
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 10.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "bstNode.hpp"

Node::Node(Doku* data, Node* left = NULL, Node* right = NULL,int middle=0) 
{
    this->data = data;
    this->left = left;
    this->right = right;
    this->middle = middle;
}

Node::~Node()
{    
    delete left;
    delete right;
    delete data;
}
