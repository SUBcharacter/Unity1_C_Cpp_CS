#pragma once
#include "UsingLibrary.h"
#include "Card.h"
#include <algorithm>
#include <random>

class Deck
{
private:
	vector<Card> deck;
	int currentCardIndex;
public:
	Deck();
	
	void ShuffleDeck();
	Card DrawCard();
};

