#pragma once
#include "UsingLibrary.h"
#include "Deck.h"
#include "Player.h"

class Game
{
private:
	int pot = 0;
	int entry = 500;
	Deck deck;
	Player& player;
	Player& dealer;
	vector<Card> communityCard;

public:
	Game(Player& p, Player& d) : player(p), dealer(d) {}
	void StartNewRound();
	void DealCommunityCard(int count);
	void ShowCommunityCard();
	void ShowGameState(bool showDown = false);
	void FirstBet();

	void Round();

};

