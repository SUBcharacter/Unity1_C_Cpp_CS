#pragma once
#include "UsingLibrary.h"
#include "Player.h"

void EvaluateCard(Player& p, vector<Card> playerCard);

bool RSF(Player& p, vector<Card> playerCard);
bool SF(Player& p, vector<Card> playerCard);
bool FC(Player& p, vector<Card> playerCard);
bool FH(Player& p, vector<Card> playerCard);
bool FL(Player& p, vector<Card> playerCard);
bool STR(Player& p, vector<Card> playerCard);
bool TRI(Player& p, vector<Card> playerCard);
bool OTP(Player& p, vector<Card> playerCard);
bool HC(Player& p, vector<Card> playerCard);