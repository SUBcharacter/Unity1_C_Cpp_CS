#pragma once
#include "Deck.h"

class Player
{
protected:
	int health;

public:
	Player();

	void setHealth(int x);
	int getHealth();
};

