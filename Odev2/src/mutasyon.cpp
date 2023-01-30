/** 
* @file mutasyon.cpp
* @description mutasyona uğrayacak hücreleri mutasyana uğramasını sağlayan sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 14.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/


#include "mutasyon.hpp"

void Mutasyon::mutasyon(Organizma* organizma) //mutasyon uygular
{
    Kontrol kontrol;
    for (int i = 0; i < organizma->size(); i++) //organizmanin tuttugu sistem sayisi kadar doner
    {
        for (int j = 0; j < 100; j++) //sistem icerisinde ki organ sayisi
        {
            if(kontrol.mutasyonControl(organizma->organizma[i]->sistem[j])) 
            {
                organizma->organizma[i]->sistem[j]->mutasyonUygula();
                organizma->organizma[i]->sistem[j]->setMutas(true);
            }       
        }
    }
}