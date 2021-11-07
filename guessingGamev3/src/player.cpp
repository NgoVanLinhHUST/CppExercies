#include <iostream>
#include "player.h"
using namespace std;

Player::Player(){}
Player::~Player(){}

int Player::guess()
{
	int guess;
	cout << "\nEnter a random number: "  ;	
	cin >> guess;
	return guess;
}

void Player::showPointMoney()
{
	point+= bet*5;
	cout << "Your Point : " << point ;
	cout << "\nYour Money : " << point*1000 ;
}
int Player::decreasePoint()
{
	return point = point - bet;
}
int  Player::getnTry()
{
	return nTry++;
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
		cout << "Game Over. Your Point : " << point;
		return 1;
	}
}
void Player::shownTry()
{
	cout << "\nNumber of guess : " << nTry;
}
void Player::reset()
{
	nTry = 0;
}
int Player::cashIn()
{
	cout << "\n\tEnter money your cash in : ( 1000vnd = 1 point) ";
	cin >> money;
	return point = money/1000;
}

int Player::checkBet()
{
    cout << " Do you wanna bet? 1-yes 2-no" ;
    char wanBet;
    cin >> wanBet;
    if ( wanBet =='1')
    {
        cout << " You wanna how many bet ?" ;
        cin  >> bet;
        return bet;
    }
    if ( wanBet == '2')
    {
        return bet =1;
    }
}
bool Player::checkPoint()
{
	if (point <= 0)
    {
        cout << "\nYour point is 0. Do you want to cash in? 1-yes 2-no";
        char cash;
        cin >> cash;
        if (cash == '1')
        {
            point = cashIn();
			reset();
			return true;
        }
        if (cash == '2')
        {
            cout << "gameover";
            return false;
        }
    }
	else 
		return 1;

}