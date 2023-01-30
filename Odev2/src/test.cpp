/** 
* @file test.cpp
* @description  programın test edilmesi için kullanılır
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 08.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "print.hpp"
#include "mutasyon.hpp"
#include "radix.hpp"
#include <fstream>
#include <sstream>

#define maxDoku 20  //gecici olarak tutulacak doku ve organlarin max dizi boyutunun belirlenmesi
#define maxOrgan 100

int main()
{
    fstream dosya;
    string satir;
    int sayi;
    int dokuSayisi = 0;
    int organSayisi = 0;
    dosya.open("veriler.txt", ios::in);     //veriler.txt dosyasi acildi

    Doku **dokular = new Doku *[maxDoku];     // dokular geici tutulacak
    Organ **organlar = new Organ *[maxOrgan]; // organlar gecici tutulacak
    Radix* radix = new Radix();
    Organizma *organizma = new Organizma();  //yeni organizma
    int* sirali;
    if (dosya.is_open())
    {
        while (getline(dosya, satir))     //satir satir dosyayi okur
        {
            stringstream ss(satir);  //okunan satiri alir
            int hucreSay = 0;
            while (ss >> sayi)  //her satirdaki hucre sayisinin belirlenmesi
            {
                hucreSay++;
            }
            ss.clear();    //satir temizlenir
            ss.str(satir); // satir tekrar eklenir

            Doku *doku = new Doku(hucreSay); //her satirda doku nesnesi olusur
            while (ss >> sayi)  //her satirdaki sayi okunur ve her sayi hucre kurucusuna yollanir olusan hucre dokuya eklenir.
            {
                Hucre *hucre = new Hucre(sayi);
                doku->add(hucre);
            }
            
            sirali =radix->Sort(doku->dokuHucreleri(),doku->size()); //doku hucreleri siralanir
               
            doku->setOrta(sirali[doku->size()/2]); //siralanan dokunun orta hucresi belirlenir
            delete[] sirali;


            dokular[dokuSayisi++] = doku;  //olusan doku gecici olarak tutulmasi icin diziye eklenir ve doku sayisi arttirilir

            if (dokuSayisi == 20)   //doku sayisi 20 ye ulasirsa organ nesnesi olusturulur.
            { 
                dokuSayisi = 0;
                Organ *organ = new Organ();
                for (int i = 0; i < 20; i++)  //organin icerisine gecici olarak dizede tutulan 20 doku eklenir.
                {
                    organ->add(dokular[i]);
                }
             
                organlar[organSayisi++] = organ;  //olusan organ 100 tane organi gecici olarak tutacagimiz diye eklenir ve organ sayisi arttirilir.

                if (organSayisi == 100) // organ sayisi 100 e ulastiginda sistem nesnesi olusturulur.
                {
                    organSayisi = 0;
                    Sistem *sistem = new Sistem();
                    for (int i = 0; i < 100; i++) //gecici dizide tutulan organlar sisteme eklenir.
                    {                     
                        sistem->add(organlar[i]); 
                    }
                    organizma->add(sistem); //olusan sistem organizmaya eklenir.
                }
            }
        }
    }

    dosya.close();
    delete[] dokular; // gecici diziler serbest birakilir.
    delete[] organlar;
    //delete radix;


    system("cls");

    Print print;
    Mutasyon mutasyon;
    Kontrol kontrol;
    int* sirali2;
    cout << "                           ORGANIZMA" << endl;
    print.yazdir(organizma); //olusan organizma yazdirilir

    char input;
    input = cin.get();
    if (input == '\n') //enter tusu disardan alinir
    {
        system("cls");
        Doku **mutasyonDoku = new Doku *[maxDoku]; //dosya okuma sisteminde yapılan gecici diziler tanimlandi
        Organ **yeniOrganlar = new Organ *[maxOrgan];

        mutasyon.mutasyon(organizma); //organizmanın kontrolleri yapilarak organlarin icerisindeki dokulara mutasyon uygulanir

        for (int i = 0; i < organizma->size(); i++) //organizma icerisindeki sistem sayisi kadar doner 
        {
            for (int j = 0; j < 100; j++) //sistem icerisindeki organ sayisi kadar doner 
            {

                if (kontrol.mutasyonUgradiMi(organizma->organizma[i]->sistem[j]))  //organizma icersindeki organlarin mutasyona ugrayip ugramadigi kontrol edilir.
                {
                    Organ *yeniOrgan = new Organ(); //mutasyona ugrayan organlar icin yeni organ olusturulur.
                    organizma->organizma[i]->sistem[j]->postOrderArray(mutasyonDoku); // mutasyona ugrayan organlar post order olarak diziye alinir.


                    for (int i = 0; i < 20; i++)  //post order diziye alinan organ doku kopyalari olusturularak yeni organa eklenir
                    {
                        Doku *yeniDoku = new Doku(*mutasyonDoku[i]);
                        sirali2 = radix->Sort(yeniDoku->dokuHucreleri(), yeniDoku->size()); //doku hucreleri siralanir
                        yeniDoku->setOrta(sirali2[yeniDoku->size() / 2]); //siralanan hucrelerin ortasi belirlenir
                        delete[] sirali2;
                        yeniOrgan->add(yeniDoku);
                    }
                    delete organizma->organizma[i]->sistem[j]; //eski organ silinir
                    organizma->organizma[i]->sistem[j] = yeniOrgan; 
                }
            }
        }

        cout << "                           ORGANIZMA(MUTASYONA UGRADI)" << endl;
        print.yazdir(organizma);
        

        delete[] mutasyonDoku;
        delete[] yeniOrganlar;
        delete organizma;   //organizma serbest birakilir.
    }    
    delete radix;
    return 0;
}