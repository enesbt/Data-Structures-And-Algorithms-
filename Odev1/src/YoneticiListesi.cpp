/** 
* @file      YoneticiListesi.cpp
* @description  yonetici listesi
* @course  2-A
* @assignment 1.odev
* @date  12.11.2022
* @author Enes Buğra Turğut bugra.turgut@ogr.sakarya.edu.tr
*/

#include "YoneticiListesi.hpp"

YoneticiListesi::YoneticiListesi()
{
    head= NULL;
    length = 0;
    seciliindex = 0;
}

NodeYonetici* YoneticiListesi::findPrevByPosition(int position) 
{
    if(position<0 || position>length) throw "index out of range";
    NodeYonetici* prev = head;
    int index = 1;
   
    for(NodeYonetici* itr=head;itr->next!=NULL && index!=position;itr=itr->next,index++)
    {
        prev = prev->next;
    }
    return prev;
}

bool YoneticiListesi::isEmpty() const
{
    return length==0;
}



void YoneticiListesi::insert(int index,SatirListesi* data)
{
    if(index<0  || index>length) throw "index out of range";

    if(index == 0)
    {
        head = new NodeYonetici(data,head,0,data->ortalamaBul());
        if(head->next!=NULL) head->next->prev = head;
    }
    else
    {
        NodeYonetici* prev = findPrevByPosition(index);
        prev->next = new NodeYonetici(data,prev->next,prev,data->ortalamaBul());
        if(prev->next->next!=NULL) prev->next->next->prev = prev->next;
    } 
    length++;

}

int YoneticiListesi::satirsayisi(int index) //secili dugumun tuttugu satır listesi içerisindeki düğüm sayısını getirir
{
    NodeYonetici* adet = getir(index);
    int dugumadet= adet->adress->dugumSayisi();
    return dugumadet;
}


NodeYonetici* YoneticiListesi::first() 
{
    if(isEmpty()) throw "list is empty";
    return head;
}


void YoneticiListesi::add(SatirListesi* data)
{
   
    if(length==0)
    {
        head = new NodeYonetici(data,0,0,data->ortalamaBul());
    }
    if(length==1)
    {
        if(data->ortalamaBul()<head->ortalama)
        {
            head= new NodeYonetici(data,head,0,data->ortalamaBul());
            head->next->prev = head;
        }
        else
        {
            head->next = new NodeYonetici(data,0,head,data->ortalamaBul());
        }
    }
    if(length>1)
    {
        if(data->ortalamaBul()<=head->ortalama)
        {
            head = new NodeYonetici(data,head,0,data->ortalamaBul());
            head->next->prev = head;
        }
        else
        {            
            for(NodeYonetici* itr = head;itr->next!=0;itr=itr->next)
            {
                if(itr->next->next==NULL)
                {
                    if(data->ortalamaBul() >= itr->next->ortalama)
                    {
                        itr->next->next = new NodeYonetici(data,0,itr->next,data->ortalamaBul());
                        break; 
                    }              
                }            
                if(itr->ortalama <= data->ortalamaBul() && itr->next->ortalama > data->ortalamaBul())
                {
                    itr->next = new NodeYonetici(data,itr->next,itr,data->ortalamaBul());
                    if(itr->next->next!=NULL) itr->next->next->prev = itr->next; break;             
                }               
            } 
        }   
    }
    length++;
}


void YoneticiListesi::satirsil(NodeSatir* satir,int index,YoneticiListesi* yonet)
{
    NodeYonetici* itr = getir(index); 
    SatirListesi* gecici = new SatirListesi();
    int sil = itr->adress->indexOfadress(satir);

    gecici = itr->adress;  //gecici artık secili dugumun gösterdigi adresi gösteriyor
   
    if(satirsayisi(index)==1)  //1düğüm var onunda silinmesi gerekir.
    {
        itr->adress->removeAt(0);
        removeAt(index);
    }
    else
    {
        gecici->removeAt(sil);  
        yonet->remove(itr->adress);    //silincek elemanın bulunduğu düğüm silinir
        yonet->add(gecici);            // silinmiş olan düğüm silinmiş olan hariç tekrar eklenir 
    }
}



void YoneticiListesi::removeAt(int index)
{
    if(index<0 || index>= length) throw "index out of range";
    NodeYonetici* del;

    if(index == 0)
    {
        del = head;
        head = head->next;
        if(head!=NULL) head->prev = NULL;
    }
    else if(index==length-1)
    {

        NodeYonetici* prev = findPrevByPosition(index);
        del = prev->next;
        prev->next=NULL;
    }
    else
    {
        NodeYonetici* prev = findPrevByPosition(index);
        del = prev->next;
        prev->next = prev->next->next;
        if(prev->next->next!=NULL)
            prev->next->next->prev = prev;      
    }
    length--;
    delete &del;
}

void YoneticiListesi::remove(SatirListesi* data)
{
    int index = indexOf(data);
    removeAt(index);
}
int YoneticiListesi::indexOf(SatirListesi* data)
{
    int index = 0 ;
    for (NodeYonetici* itr = head; itr!=0; itr=itr->next)
    {
        if(itr->adress==data) return index;
        index++;
    }
    throw "index out of range";
}


NodeYonetici* YoneticiListesi::getir(int index)
{
    if(index<0 || index>=length) throw "index out of range";
    int i=0;
    NodeYonetici* itr = head;
    for(;itr!=0;itr=itr->next,i++)
    {
        if(i == index )
        {
            return itr;
        }

    }
    throw "item not found";
}



void YoneticiListesi::satiryazdir(int index,NodeSatir* satir) //adresler 8 veya 9 uzunluğunda geldiği için extra kontroller yapılmıştır.
{
    NodeYonetici* gecici = getir(index);  //secili düğüm
    ostringstream oss;
    oss<<gecici;
    string itrsize = oss.str();
    int size = itrsize.length();  //gelen adresin uzunluğu

    cout<<endl;

   
    
    while (index>=8)
    {
        index-=8;
    }
 
    if(size==9)
    {
        for (int i = 0; i < index; i++)
        {
            
            cout<<"                 ";
        }   
        cout<<"^^^^^^^^^^^"<<endl;
    
        for(NodeSatir* itr =gecici->adress->first();itr!=0;itr=itr->next)
        {  
            int y = itr->data;
            ostringstream oss;
            oss<<y;
            string itrsize = oss.str();
            int size2 = itrsize.length();
            int dongu = size - size2 ;
            
            for (int i = 0; i < index; i++)
            {
                cout<<"                 ";
            }
           
            cout<<" "<<itr<<endl;
            for (int i = 0; i < index; i++)
            {
                cout<<"                 ";
            }

            cout<<"-----------"<<endl;
                for (int i = 0; i < index; i++)
            {
                cout<<"                 ";
            }
            if(satir==itr)
            {
                cout<<"|";
                for (int i = 0; i < dongu; i++)
                {
                   cout<<" ";
                }
                
                cout<<itr->data;
                cout<<"|"<<" <----silincek"<<endl;
            }
            
            else
            {
                cout<<"|";
                for (int i = 0; i < dongu; i++)
                {
                   cout<<" ";
                }
                
                cout<<itr->data;
                cout<<"|"<<endl;
            }
                
            for (int i = 0; i < index; i++)
            {
                cout<<"                 ";
            }
            cout<<"-----------"<<endl;
                for (int i = 0; i < index; i++)
            {
                cout<<"                 ";
            }
            cout<<"|"<<itr->next<<"|"<<endl;
                for (int i = 0; i < index; i++)
            {
                cout<<"                 ";
            }
            cout<<"-----------"<<endl<<endl;
        }
    }
      if(size==8)
    {
       
        for (int i = 0; i < index; i++)
        {
            
            cout<<"                ";
        }   
        cout<<"^^^^^^^^^^"<<endl;
    
        for(NodeSatir* itr =gecici->adress->first();itr!=0;itr=itr->next)
        {  
            int y = itr->data;
            ostringstream oss;
            oss<<y;
            string itrsize = oss.str();
            int size2 = itrsize.length();
            int dongu = size - size2 ;

            for (int i = 0; i < index; i++)
            {
                cout<<"                ";
            }   
            cout<<" "<<itr<<endl;
            for (int i = 0; i < index; i++)
            {
                cout<<"                ";
            }

            cout<<"----------"<<endl;
                for (int i = 0; i < index; i++)
            {
                cout<<"                ";
            }
            if(satir==itr)
            {
                cout<<"|";
                for (int i = 0; i < dongu; i++)
                {
                   cout<<" ";
                }
                
                cout<<itr->data;
                cout<<"|"<<" <----silincek"<<endl;
            }
            else
            {
                cout<<"|";
                for (int i = 0; i < dongu; i++)
                {
                   cout<<" ";
                }
                
                cout<<itr->data;
                cout<<"|"<<endl;

            }
                
                for (int i = 0; i < index; i++)
            {
                cout<<"                ";
            }
            cout<<"----------"<<endl;
                for (int i = 0; i < index; i++)
            {
                cout<<"                ";
            }
            cout<<"|"<<itr->next<<"|"<<endl;
                for (int i = 0; i < index; i++)
            {
                cout<<"                ";
            }
            cout<<"----------"<<endl<<endl;
        }
    }
}

int YoneticiListesi::dugumsayisi()
{
    return length;
}
NodeYonetici* YoneticiListesi::last()
{
    return findPrevByPosition(length);
};
void YoneticiListesi::yazdir(int index,NodeSatir* satir,int sekizli) //sekizli 0 dan başlar kullanıcı arttırdıkça 8li olarak artar kontrolleri buna göre yapılmıştır.
{
    if(isEmpty()) cout<<"list is empty"<<endl;
    else{

        int i = sekizli;
        int sekizlidekinodesayisi=0;

        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++)
        {
            sekizlidekinodesayisi++;      
        }
        i=sekizli;
        

        NodeYonetici* itr=getir(sekizli);
        NodeYonetici* itr2=getir(sekizli+sekizlidekinodesayisi-1);
        ostringstream oss;
        oss<<itr;
        string itrsize = oss.str();
        int size = itrsize.length();

        if(itr==last() || itr2==last())  
        {
            if(itr==first()||itr2==first())
                cout<<"head";
            else
                cout<<"<---";
            for (int i = 0; i < sekizlidekinodesayisi; i++)
            {
                cout<<"               ";
            }
            cout<<"son";

        }
        else if(itr==head || itr2==head)
        {
            cout<<"head";
            for (int i = 0; i < sekizlidekinodesayisi; i++)
            {
                cout<<"               ";
            }
            if(itr==last()||itr2==last())
                cout<<"last";
            else
                cout<<"--->";
            
        }
        else
        {
            cout<<"<---";
            for (int i = 0; i < sekizlidekinodesayisi; i++)
            {
                cout<<"               ";
            }
            cout<<"--->";
        }

   
        cout<<endl;
        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++) //her seferinde ekranda 8 veya daha az düğüm gözükür.
        {   
            cout<<" "<<itr;
            cout<<"       ";         
        }
        i=sekizli;
        cout<<endl;
        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++)
        {
           
            for (int i = 0; i <size+2; i++)
            {
                cout<<"-";
            }          
            cout<<"      ";
        }
        i=sekizli;
        cout<<endl;
        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++)
        {
           
            if(itr->prev==0)
            {
                cout<<"|";
                cout<<itr->prev;
                for (int i = 0; i <size-1; i++)
                {
                    cout<<" ";
                }
                cout<<"|";
                cout<<"      ";
               
            }
            
            else
            {          
                cout<<"|";
                cout<<itr->prev;
                cout<<"|";
                cout<<"      ";
            }             
        }

        i=sekizli;
        cout<<endl;


        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++)
        {
            int y = itr->ortalama;
            ostringstream oss;
            oss<<y;
            string itrsize = oss.str();
            int size2 = itrsize.length();
          
            int dongu = (size - size2) - 2 ;

                cout<<"|";               
                for (int i = 0; i <dongu; i++)
                {
                    cout<<" ";
                }
                cout<<setprecision(1)<<fixed<<itr->ortalama;
  
                cout<<"|";
            
                     
            cout<<"      ";
        }
        cout<<endl;
        i=sekizli;
        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++)
        {
            
            for (int i = 0; i <size+2; i++)
            {
                cout<<"-";
            }          
            cout<<"      ";
        }
        i=sekizli;
        cout<<endl;
        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++)
        {
           
            cout<<"|";
            cout<<itr->next;
            cout<<"|";          
            cout<<"      ";    
        }
        i=sekizli;
        cout<<endl;
        for(NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++)
        {
           
            for (int i = 0; i <size+2; i++)
            {
                cout<<"-";
            }                  
            cout<<"      ";
        }
        i=sekizli;
        cout<<endl;
        int index2 =sekizli;        
        for (NodeYonetici* itr=getir(sekizli);itr!=0&&(i<sekizli+8);itr=itr->next,i++,index2++)
        {
            if(index2==index)
            {
                if(index==dugumsayisi()-1 && itr==NULL)
                    satiryazdir(index2-1,satir);
                else
                    satiryazdir(index2,satir);    
            }
        }
        i=sekizli;
    }
}

void YoneticiListesi::satirdelete()
{
   
    for(NodeYonetici* itr = head;itr!=NULL;itr=itr->next) //satir listelerini serbest bırakır.
    {
        delete itr->adress;
    }
}


void YoneticiListesi::clear()
{
    while(!isEmpty())
        removeAt(0);
}

YoneticiListesi::~YoneticiListesi() 
{
    satirdelete();
    clear();
    delete head;
}