#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "computer.h"

using namespace std;

void Computer::random(const int &min, const int &max)
{
	srand(time(NULL));
	number = rand()%max + 1;
}

int Computer::getNumber() const 
{
	// cout << number << endl;
	return number;
}
int Computer::compare(int guess) const
{
	if( number > guess)
	{
		// cout <<number << "<=========";
		cout << "\nyour number is less than my number";
		return 1;
	}

	else if (number < guess)
	{
		// cout <<number << "<=========";
		cout << "\nYour number is greater than my number";
		return 2;
	}

	else if(number == guess )
	{
		std::cout << " correct ";
		return 0;
	}
}
