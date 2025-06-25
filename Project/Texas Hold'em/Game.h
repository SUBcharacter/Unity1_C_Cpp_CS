#pragma once
#include "UsingLibrary.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "EvaluateManager.h"

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
		communityCard.reserve(10);
		playerCard.reserve(10);
		dealerCard.reserve(10);
		actPlayer = DEFAULT;
		actDealer = DEFAULT;
	}
	int Input();

	void Title();
	void StartNewRound();
	void DealCommunityCard(int count);
	void ShowCommunityCard();
	void ShowGameState(bool showDown = false);
	void ShowHand();
	bool CheckPlayerMoney();
	
	void BetFromPlayer(Player& p, int chip);
	void FirstBet();
	void DefaultBet();
	void DealerDecision(Acting actPlayer, int entry = 0);
	bool DecisionCheck();
	void PlayerCard();
	void ShowPlayerCard();

	void Rewarding(Player& p, Player& d);

	void Round();

};

