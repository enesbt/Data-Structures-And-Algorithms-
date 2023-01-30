/** 
* @file queue.cpp
* @description kuyruk sınıfı radix siralamasinda kullanılacak
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 10.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "queue.hpp"

Queue::Queue() //kuyruk kurucu
{ 
    capacity = 0;
    clear();
    items = new int[capacity];
}
void Queue::reserve(int newCapacity) //dizi genisletilir.
{
    int* tmp = new int[newCapacity];
    for (int i = front, j = 0; j < length; j++) 
    {
        tmp[j] = items[i];
        i = (i + 1) % capacity;
    }
    capacity = newCapacity;
    delete[] items;
    items = tmp;
    front = 0;
    back = length - 1;
}

void Queue::clear()
{
    front = 0;
    back = -1;
    length = 0;
}

int Queue::count()
{
    return length;
}

bool Queue::isEmpty()
{
    if (length == 0) return true;
    return false;
}
int Queue::peek()  //kuyruktan suan cikacak eleman doner
{
    if (isEmpty()) throw "Empty List";
    return items[front];
}
 
void Queue::enqueue(int item)  //kuyruga ekle back arttirilir.
{
    if (length >= capacity) reserve(1+ capacity);
    back = (back + 1) % capacity;
    items[back] = item;
    length++;
}
void Queue::dequeue() //kuyruktan cikar front kapasiteye gore arttirilir dairesel dizi olabilmesi icin 
{
    if (isEmpty()) throw "Empty List";
    front = (front + 1) % capacity;
    length--;
}
Queue::~Queue()
{
    delete[] items;
}