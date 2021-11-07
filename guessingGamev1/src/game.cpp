#include <iostream>
#include "game.h"
using namespace std;


void Game::start( const int &min,const int &max)
{
	c.random(min,max);
	c.getNumber();
	bool gameOver = false;
	while(gameOver == 0 )
	{
		int numberGuess = p.guess();
		int check = c.compare(numberGuess);
		if(check == 1 || check == 2)
		{
			int nTry = p.getnTry();

		}
		else if ( check == 0)
		{
			p.reset();
			gameOver = p.confirmPlay();
			if(gameOver == 0)
			{
				c.random(min,max);
				c.getNumber();
			}
		}
		
	}
}

