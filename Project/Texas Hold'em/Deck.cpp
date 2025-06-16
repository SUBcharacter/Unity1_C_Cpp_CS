#include "Deck.h"

Deck::Deck()
{
	currentCardIndex = 0;
	for (int i = SPADE; i <= CLOVER; i++)
	{
		for (int j = TWO; j <= A; j++)
		{
			deck.push_back(Card(static_cast<Mark>(i), static_cast<Number>(j)));
		}
	}
}

void Deck::ShuffleDeck()
{
	currentCardIndex = 0;
	random_device seed;
	mt19937 g(seed());
	shuffle(deck.begin(), deck.end(), g);
}

Card Deck::DrawCard()
{
	return deck[currentCardIndex++];
}
