#include <iostream>
#include "computer.h"
#include <stdlib.h>
#include "player.h"

using namespace std;
int Player::guess()
{
	int guess;
	cout << "\nEnter a random number: "  ;	
	cin >> guess;
	return guess;
}

int Player::getnTry()
{
	cout << "\n Number Of Guess:" << ++nTry;
	return nTry;
	
}

bool Player::confirmPlay()
{
	char conf;
	cout << "\n\nDo you want to continue? 1-y 2-n";
	cin >> conf;
	if (conf =='1')
	{
		return 0;
	}
	else if ( conf == '2')
	{
		cout << "Game Over";
		return 1;
	}
}

void Player::reset()
{
	nTry = 0;
}