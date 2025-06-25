#pragma once
#include "UsingLibrary.h"
#include "Deck.h"


class Player
{
private:
	string name;
	int money;
	HandRank handRank;
	vector<Card> highCard;
	vector<Card> hand;

public:
	Player();
	Player(string name, int money) : name(name), money(money), highCard(NONE) { handRank = NONE; }
	string SetName();
	void SetMoney(int seedMoney);

	string GetStringHandRank();
	string GetName() const { return name; }
	int GetMoney() const { return money; }
	const vector<Card>& GetHand() const { return hand; }
	
	void AddCard(Card card);
	void ClearHand();
	void ShowHand();
	void ShowHighCard();
	void ChangeMoney(int chip);
	void SetHR(HandRank hr);

	void SetHC(const Card& card);
	void SetHC(const vector<Card>& card);
	void ClearHC();
	vector<Card> GetHC();
	HandRank GetHR() const { return handRank; }
};

