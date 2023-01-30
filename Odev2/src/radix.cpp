/** 
* @file radix.cpp
* @description sayıları küçükten büyüğe sıralamaya yarayan sınıf
* @course 2. öğretim 2A
* @assignment 2.odev
* @date 10.12.2022
* @author Enes Buğra Turğut  bugra.turgut@ogr.sakarya.edu.tr
*/

#include "radix.hpp"

Radix::Radix()  
{
	queues = new Queue*[10];
	for(int j=0;j<10;j++){ queues[j] = new Queue(); }
}

int Radix::MaxStepNumber(int* items,int length) //en yuksek basamak sayisi  
{
	int max=0;
	for(int i=0;i<length;i++){
		if(StepCount(items[i])>max) max = StepCount(items[i]);
	}
	return max;
}
int Radix::StepCount(int number) //basamak sayisi
{
	number = abs(number);
	int basamak=0;
	while(number>0){
		basamak++;
		number /= 10;
	}
	return basamak;
}

int* Radix::QueueCurrentLengths() //kuyurugun suanki uzunlugu
{
	int *lengths = new int[10];
	for(int i=0;i<10;i++){
		lengths[i] = queues[i]->count();
	}
	return lengths;
}
int Radix::power(int e)
{
	int result=1;
	for(int i=0;i<e;i++) result *= 10;
	return result;
}
int* Radix::Sort(int* numbers,int length)
{

	int maxStep = MaxStepNumber(numbers,length);
	int numberIndex=0;
	for(;numberIndex<length;numberIndex++){
		int stepValue = numbers[numberIndex]%10;
		int num = numbers[numberIndex];
		queues[stepValue]->enqueue(num);
	}				
	for(int i=1;i<maxStep;i++){
		int *qlengths = QueueCurrentLengths();
		for(int index=0;index<10;index++){
			int len=qlengths[index];
			for(;len>0;len--){
				int number = queues[index]->peek();
				queues[index]->dequeue();
				int stepValue = (number/power(i))%10;			
				queues[stepValue]->enqueue(number);				
			}
		}
		delete [] qlengths;
	}
	int* ordered = new int[length];
	numberIndex=0;
	for(int index=0;index<10;index++){
		while(!queues[index]->isEmpty()){
			int number = queues[index]->peek();
			ordered[numberIndex++] = number;
			queues[index]->dequeue();
		}
	}				
	return ordered;
}

Radix::~Radix(){	
	for(int i=0;i<10;i++) delete queues[i];
	delete [] queues;
}