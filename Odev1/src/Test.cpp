/** 
* @file      Test.cpp
* @description  test 
* @course  2-A
* @assignment 1.odev
* @date  27.11.2022
* @author Enes Buğra Turğut bugra.turgut@ogr.sakarya.edu.tr
*/


#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include<fstream>
#include<string>


int main()
{
  
  fstream file;
  int sayi;
  string satir;
  file.open("veriler.txt",ios::in);
  YoneticiListesi *yonetici = new YoneticiListesi(); //yonetici listesi heap alaninda olusturuldu.

  if(file.is_open())
  {
    while(getline(file,satir))
    {
        SatirListesi* sayilar = new SatirListesi();  // her satirda satir listesi olusturuldu.
        stringstream ss(satir);
        while(ss>>sayi)
        {
          sayilar->add(sayi); //satır listesine sayilar eklenir
        }
        yonetici->add(sayilar);  // yonetici listesine satır listesi eklenir.
    }
  }

  file.close();



  NodeSatir* gecicisatir;  //rastgele silinecek satırın gecici satır düğümüne atanması için
  int sekizli=0;
  system("cls");
  yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
  char ch;
  char ch2;
    do
    {
      cout<<endl<<"c: saga git"<<endl;
      cout<<"z: sola git"<<endl;
      cout<<"p: yonetici cikar"<<endl;
      cout<<"k: rastgele satir sil"<<endl;
      cout<<"d: sekizli ileri"<<endl;
      cout<<"a: sekizli geri"<<endl;
      cout<<"q: cikis"<<endl;
      cout<<"secim"<<endl;
      cin>>ch;
      switch (ch)
      {
        system("cls");
        case 'z':

          yonetici->seciliindex -= 1;
          system("cls");
          
          if(yonetici->seciliindex < sekizli)
          {
            yonetici->seciliindex = sekizli;
            yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
            
          }         
          else
          {
            yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
          }
          
        break;

        case 'c':
          yonetici->seciliindex+=1;
          system("cls");
          
      
          if(yonetici->seciliindex==sekizli+8 || yonetici->seciliindex==yonetici->dugumsayisi())
          {
             yonetici->seciliindex-=1;
          }
          yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
           
        break;
        case 'd':
          system("cls");
          sekizli+=8;
          yonetici->seciliindex=sekizli;
     
          if(sekizli>yonetici->dugumsayisi()-1)
          {
            sekizli -=8;
            yonetici->seciliindex = sekizli;
            yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);

          }

          else
          {
            yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);

          }
        break;
        case 'a':
          system("cls");
          sekizli-=8;
          yonetici->seciliindex=sekizli;
          if(sekizli<0)
          {
            yonetici->seciliindex=0;
            sekizli = 0;
            yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
          }
          else
          {
            yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
          }

              
          break;

        case 'p':
          system("cls");
      
          if(yonetici->seciliindex==yonetici->dugumsayisi()-1)
          {
            yonetici->removeAt(yonetici->seciliindex);
            yonetici->seciliindex-=1;
            if(yonetici->seciliindex+1==sekizli)
             {
                sekizli-=8;
                yonetici->seciliindex=sekizli;
                yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);

             }
             else
                yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
          }
          else
          {
            yonetici->removeAt(yonetici->seciliindex);
            yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
          }
                 
        break;
        case 'k':
          system("cls");
          gecicisatir = yonetici->getir(yonetici->seciliindex)->adress->rastgelegetir();
          yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);

          cin>>ch2; 
          switch (ch2)
          {
            case 'k':
                system("cls");
                int oncedugum;
                int sonradugum;
                
              
                if(yonetici->seciliindex==yonetici->dugumsayisi()-1)
                {
                    oncedugum = yonetici->dugumsayisi();
                    yonetici->satirsil(gecicisatir,yonetici->seciliindex,yonetici);
                    system("cls");
                    sonradugum =yonetici->dugumsayisi();
                  if(oncedugum!=sonradugum)
                  {
                      yonetici->seciliindex-=1;
                      if(yonetici->seciliindex+1==sekizli)
                      {
                          sekizli-=8;
                          yonetici->seciliindex=sekizli;                          
                          yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);

                      }
                      else
                        yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);

                  }
                  else
                      yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli);
                  
                }

                else
                {
                    yonetici->satirsil(gecicisatir,yonetici->seciliindex,yonetici);
                    system("cls");
                    yonetici->yazdir(yonetici->seciliindex,gecicisatir,sekizli); 
                }          
              break;
            
            default:
              break;
          }
          gecicisatir = 0;
        break;

        case 'q':
          cout<<"cikis"<<endl;
          break;
        default:
          break;
      }
    } while (ch!='q');




  delete yonetici;
  delete gecicisatir;
  

  return 0;
}