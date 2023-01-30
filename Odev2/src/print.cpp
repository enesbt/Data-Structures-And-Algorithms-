/** 
* @file print.cpp
* @description konsola yazdırma sınıfı
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 14.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "print.hpp"

void Print::yazdir(Organizma* organizma)  //agacin dengeli olup olmadigina gore yazdirma yapilir.
{
    Kontrol kontrol;
    for (int i = 0; i < organizma->size(); i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(kontrol.dengeliMi(organizma->organizma[i]->sistem[j])) 
                cout<<" ";
            else
                cout<<"#";
        }
        cout<<endl;
    }
}