/** 
* @file kontrol.cpp
* @description yazdırma ve mutasyon kontrol eden sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 10.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "kontrol.hpp"

 
bool Kontrol::dengeliMi(Organ* organ) //organin dengeli olup olmadigini kontrol eder
{
    if(organ->dengeliMi())
        return true;
    else
        return false;
}

bool Kontrol::mutasyonUgradiMi(Organ* organ) // organin mutasyona ugrayip ugramadigini kontrol eder
{
    return organ->getMutas();
}

bool Kontrol::mutasyonControl(Organ* organ) //organa mutasyon uygulanmasi gerekiyor mu kontrol eder
{
    if(organ->rootOrta() % 50 == 0)
        return true;
    else
        return false;
}
