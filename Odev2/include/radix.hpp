#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include<math.h>

class Radix{
	private:	
		Queue **queues;	
		int MaxStepNumber(int*,int);
		int power(int);
		int StepCount(int);
		int* QueueCurrentLengths();
	public:
		Radix();
		int* Sort(int*,int);
		~Radix();
};
#endif