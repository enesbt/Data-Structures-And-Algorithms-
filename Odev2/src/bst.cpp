/** 
* @file bst.cpp
* @description ikili agac sinifi
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 10.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "bst.hpp"

Bst::Bst()
{
    root = NULL;
}



void Bst::postorderToArray(Doku** dokular) //disardan alinan diziye agacin verileri eklenir
{
    postOrderRecursive(this->root, dokular, 0);
}


int Bst::postOrderRecursive(Node* root, Doku** dokular, int index) //agactaki doku nesneleri doku nesnesi tutacak diziye postorder olarak eklenir
{
    if (root == NULL)
        return index;
    if (root->left != NULL)
        index = postOrderRecursive(root->left, dokular, index);
    if (root->right != NULL)
        index = postOrderRecursive(root->right, dokular, index);
    dokular[index++] = root->data;
    
    return index;
}



void Bst::applyMutation(Node* subNode) //agactaki doku nesnelerine mutasyon uygulanir 
{ 
    if (subNode != NULL)
    {           
        applyMutation(subNode->left);
        applyMutation(subNode->right);
        subNode->data->mutation();     
    }
}

void Bst::applyMutation() 
{
    applyMutation(root);
}


int Bst::height(Node* subNode) //agacta verilen dugumun yuksekligini bulur
{
    if(subNode == NULL) return -1;
	return 1+max(height(subNode->left),height(subNode->right));
}

bool Bst::checkBalance(Node* subNode) //agacin dengeli olup olmadigi kontrol edilir
{
    if (subNode == nullptr) return true;
    int checkLeft = checkBalance(subNode->left);  
    int checkRight = checkBalance(subNode->right); 
    int leftHeight = height(subNode->left);
    int rightHeight = height(subNode->right);
   
    return abs( leftHeight - rightHeight) <=1 &&checkLeft && checkRight; //sag ve sol dugumun yukseliginin farki 1e eşit veya küçük ve sag ve sol agac dengeli olmasi durumunda true doner

}


bool Bst::isBalanced()
{
    return checkBalance(root);
}

int Bst::rootOrta()  //kok dugumun tuttugu doku nesnesinin orta elemani doner
{
    return root->middle;
}


void Bst::searchAndAdd(Node*& subNode, Doku* doku) //bst ye  doku nesnesi ekler esitlik durumunda sol dugume eklenir
{
    if (subNode == NULL) subNode = new Node(doku, NULL, NULL,doku->getOrta());
    else if (doku->getOrta() <= subNode->middle)
        searchAndAdd(subNode->left, doku);
    else if (doku->getOrta() > subNode->middle)
        searchAndAdd(subNode->right, doku);

    else return;
}


void Bst::add(Doku* doku)
{
    searchAndAdd(root, doku);
}


void Bst::postOrderClear(Node*& subNode)  //agactaki dokuların serbest birakilmasi
{
    if (subNode != NULL)
    {
        postOrderClear(subNode->left);
        postOrderClear(subNode->right);
        delete subNode->data;  //doku nesnesi tuttugu icin dokuda serbest birakilir.
        subNode->data = NULL;
        delete subNode;       
        subNode = NULL;
    }
    root = NULL;
}

void Bst::clear() //tum agaci temizler
{
    Node* current = root;
    if (current != NULL) 
    {   
        postOrderClear(current);
    }
}


Bst::~Bst()
{ 
    clear();
}