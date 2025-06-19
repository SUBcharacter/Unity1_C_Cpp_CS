#pragma once
#include "UsingLibrary.h"
#include "Deck.h"
#include "Player.h"

class Game
{
private:
	bool isAllin = false;
	int pot = 0;
	int entry = 500;
	int bettingPlayer = 0;
	int bettingDealer = 0;
	Acting actPlayer;
	Acting actDealer;

	Deck deck;
	Player& player;
	Player& dealer;
	vector<Card> communityCard;
	vector<Card> playerCard;
	vector<Card> dealerCard;

public:
	Game(Player& p, Player& d) : player(p), dealer(d) 
	{
		communityCard.reserve(5);
		playerCard.reserve(7);
		dealerCard.reserve(7);
		actPlayer = DEFAULT;
		actDealer = DEFAULT;
	}
	int Input();

	void StartNewRound();
	void DealCommunityCard(int count);
	void ShowCommunityCard();
	void ShowGameState(bool showDown = false);
	bool CheckPlayerMoney();
	
	void BetFromPlayer(Player& p, int chip);
	void FirstBet();
	void DefaultBet();
	void DealerDecision(Acting actPlayer, int entry = 0);
	bool DecisionCheck();


	void Round();

};

