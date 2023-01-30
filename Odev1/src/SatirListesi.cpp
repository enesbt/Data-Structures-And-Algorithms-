/** 
* @file      SatirListesi.cpp
* @description  satir listesi sınıfı
* @course  2-A
* @assignment 1.odev
* @date  10.11.2022
* @author Enes Buğra Turğut bugra.turgut@ogr.sakarya.edu.tr
*/


#include "SatirListesi.hpp"

SatirListesi::SatirListesi()
{
    head = NULL;
    length = 0;
};


NodeSatir* SatirListesi::findPrevByPosition(int position) //onceki dugumu getir
{
   if(position<0 || position>length) throw "index out of range";
    NodeSatir* prev = head;
    int index = 1;
   
    for(NodeSatir* itr=head;itr->next!=NULL && index!=position;itr=itr->next,index++)
    {
        prev = prev->next;
    }
    return prev;

}
NodeSatir* SatirListesi::first() //ilk dugumu getir
{
    return head;
}
bool SatirListesi::isEmpty() const //liste boş mu kontrol edilir
{
    return length == 0;
}

void SatirListesi::insert(int index,const int& data) //araya eleman ekleme
{
    if(index<0  || index>length) throw "index out of range";

    if(index == 0)
    {
        head = new NodeSatir(data,head,0);
        if(head->next!=NULL) head->next->prev = head;
    }
    else
    {
        NodeSatir* prev = findPrevByPosition(index);
        prev->next = new NodeSatir(data,prev->next,prev);
        if(prev->next->next!=NULL) prev->next->next->prev = prev->next;
    }
    length++;
}

void SatirListesi::add(const int& data) //sona eleman ekleme
{
    insert(length,data);
}

void SatirListesi::removeAt(int index) //secili indexi sil
{
    if(index<0 || index>= length) throw "index out of range";
    NodeSatir* del;

    if(index == 0)
    {
        del = head;
        head = head->next;
        if(head!=NULL) head->prev = NULL;
    }
    else if(index==length-1)
    {
        
        NodeSatir* prev = findPrevByPosition(index);
        del = prev->next;
        prev->next=NULL;
    }
    else
    {
        NodeSatir* prev = findPrevByPosition(index);
        del = prev->next;
        prev->next = prev->next->next;
        if(prev->next->next!=NULL)
            prev->next->next->prev = prev;
    }
    length--;
    delete &del;
}

NodeSatir* SatirListesi::getir(int index)  //verilen indexe göre düğüm getir
{
    if(index<0 || index>=length) throw "index out of range";
    int i=0;
    NodeSatir* itr = head;
    for(;itr!=0;itr=itr->next,i++)
    {
        if(i == index )
        {
            return itr;
        }

    }
    throw "item not found";
}

void SatirListesi::remove(const int& data)  //verilen elemanı sil
{
    int index = indexOf(data);
    removeAt(index);
}

NodeSatir* SatirListesi::rastgelegetir() //rastgele düğüm getir
{
    srand(time(NULL));
    int random = 0;
    random = rand() % dugumSayisi();  //0 ile düğüm sayısı arasında sayı üretir
    
    return getir(random);  //rastgele üretilen sayı getir fonksiyonuna verilerek rastgele düğüm getirilmiş olur.
}

int SatirListesi::indexOfadress(NodeSatir* satir)
{
    int index = 0 ;
    for (NodeSatir* itr = head; itr!=0; itr=itr->next)
    {
        if(itr==satir) return index;
        index++;
    }
    throw "index out of range";
}

int SatirListesi::indexOf(const int& data) // verilen elemanın indedxini döndürür.
{
    int index = 0 ;
    for (NodeSatir* itr = head; itr!=0; itr=itr->next)
    {
        if(itr->data==data) return index;
        index++;
    }
    throw "index out of range";
}



double SatirListesi::ortalamaBul()  //satir listesindeki düğümlerin içindeki sayıların ortalamasını döndürür.
{
    double ortalama = 0.0f;
    double toplam=0.0f;
    int index=0;
    for(NodeSatir* itr = head;itr!=0;itr=itr->next,index++)
    {
        toplam+= itr->data;
    }
    ortalama = toplam/index;
    return ortalama;
}

int SatirListesi::dugumSayisi()
{
    return length;
}


void SatirListesi::clear()
{
    while(!isEmpty())
    {
        removeAt(0);
    }
        
}

SatirListesi::~SatirListesi()
{  
    clear();
    delete head;
}