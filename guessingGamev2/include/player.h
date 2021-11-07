#pragma once 
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
Player::Player(){}
Player::~Player(){}