#pragma once
#include "UsingLibrary.h"
#include "Deck.h"


class Player
{
private:
	string name;
	int money;
	HandRank handRank;
	Card highCard;
	vector<Card> hand;
public:
	Player();
	Player(string name, int money) : name(name), money(money), highCard() { handRank = NONE; }
	string SetName();
	void SetMoney(int seedMoney);

	string GetName() const { return name; }
	int GetMoney() const { return money; }
	const vector<Card>& GetHand() const { return hand; }
	
	void AddCard(Card card);
	void ClearHand();
	void ShowHand();
	void ChangeMoney(int chip);
	void SetHR(HandRank hr);

	void SetHC(const Card& card);
	Card GetHC();
	HandRank GetHR() const { return handRank; }
};

