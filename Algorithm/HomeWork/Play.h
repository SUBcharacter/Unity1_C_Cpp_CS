#pragma once
#include "Player.h"

class Play
{
private:
	Player& you;
	Player& your_Friend;

	Deck deck;

public:
	Play(Player& y, Player& yf) : you(y), your_Friend(yf) {}

	void DamageReport(Player& p, Card& c);

	void CheckCard(Player& p, Card& card);

	bool CheckSomeOneDied();

	void start();
};

