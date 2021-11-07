#pragma once 
#include <iostream>
#include <cstdlib>
#include <ctime>

class Computer
{
	public:
		int number;
	public:
		Computer();
		~Computer();
		void random(const int &min ,const int &max);
		int getNumber() const;
		int compare(int guess) const;
};

