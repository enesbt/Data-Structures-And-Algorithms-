#ifndef QUEUE_HPP
#define QUEUE_HPP

#include<iostream>
using namespace std;

class Queue
{
private:
    int front;
    int back;
    int capacity;
    int length;
    int* items;
    void reserve(int);

public:
    Queue();
    void clear();
    int count();
    bool isEmpty();
    int peek();
    void enqueue( int);
    void dequeue();
    ~Queue();
};



#endif
