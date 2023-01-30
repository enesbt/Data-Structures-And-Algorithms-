#ifndef BST_HPP
#define BST_HPP

#include "bstNode.hpp"
#include<iostream>

class Bst
{
private:     
    Node* root;
    void searchAndAdd(Node*&, Doku*);
    void applyMutation(Node*);
    void postOrderClear(Node*&);
    bool checkBalance(Node*);
    int postOrderRecursive(Node*, Doku**, int);
    int height(Node*);
    void clear();

public:   
    Bst();
    void add(Doku*);
    void applyMutation();
    void postorderToArray(Doku**);
    bool isBalanced();   
    int rootOrta();
    ~Bst();
};

#endif
