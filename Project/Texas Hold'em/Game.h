#pragma once
#include "UsingLibrary.h"
#include "Deck.h"
#include "Player.h"

class Game
{
private:
	int pot = 0;
	int entry = 500;
	int bettingPlayer = 0;
	int bettingDealer = 0;
	Deck deck;
	Player& player;
	Player& dealer;
	vector<Card> communityCard;

public:
	Game(Player& p, Player& d) : player(p), dealer(d) 
	{
		communityCard.reserve(5);
	}
	void StartNewRound();
	void DealCommunityCard(int count);
	void ShowCommunityCard();
	void ShowGameState(bool showDown = false);
	bool CheckPlayerMoney();
	
	void BetFromPlayer(Player& p, int chip);
	bool FirstBet();
	bool DefaultBet();
	void DealerDecision();

	void Round();

};

