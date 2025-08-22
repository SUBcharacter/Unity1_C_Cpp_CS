#pragma once
#include "Integration.h"
#include "Card.h"
class Deck
{
private:
	int deckIndex;
	vector<Card> deck;

public:
	Deck();

	void ShuffleDeck();

	Card& Draw();
};

