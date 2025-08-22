#pragma once
#include "Integration.h"

class Card
{
private:
	Rank rank;
	Mark mark;

public:
	Card(Rank r, Mark m) : rank(r), mark(m) {};

	Rank GetCardRank();
	Mark GetCardMark();
};

