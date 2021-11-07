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

class Player
{ 
	public:
		int nTry;
		int point;
		int money;
		int bet;
	public:
		Player();
		~Player();
		int guess();
		int  getnTry();
		bool confirmPlay();
		void reset();
		int cashIn();
		bool checkPoint();
		int decreasePoint();
		void showPointMoney();
		void shownTry();
		int checkBet();
};


class Game
{
	public:
		Player p;
		Computer c;
	public:
		Game();
		~Game();
		void start(const int &min,const int &max);
};
