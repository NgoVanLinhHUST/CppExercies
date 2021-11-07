#include <iostream>
#include <cstdlib>
#include <ctime>
#include "computer.h"
using namespace std;

Game::Game(){}
Game::~Game(){}

void Game::start( const int &min,const int &max)
{
	p.cashIn();
	p.checkBet();
	c.random(min,max);
	c.getNumber();
	bool gameOver = false;
	while(gameOver == 0 )
	{
		int numberGuess = p.guess();
		int check = c.compare(numberGuess);
		if(check == 1 || check == 2)
		{
			p.getnTry();
			p.decreasePoint();
			if (p.checkPoint()==0)
			{
				gameOver = 1;
			}
		}
		else if ( check == 0)
		{
			
			p.shownTry();
			p.showPointMoney();
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
