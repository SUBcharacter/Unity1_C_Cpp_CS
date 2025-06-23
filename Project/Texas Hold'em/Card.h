#pragma once	
#include "UsingLibrary.h"
class Card
{
private:
	Mark mark;
	Number number;
	bool isFromHand = false;

	string SetMarkString()
	{
		switch (mark)
		{
		case SPADE: return "¢¼";
		case DIAMOND: return "¡ß";
		case HEART: return "¢¾";
		case CLOVER: return "¢À";
		}
	}

	string SetNumberString()
	{
		switch (number)
		{
		case TWO: return "2";
		case THREE: return "3";
		case FOUR: return "4";
		case FIVE: return "5";
		case SIX: return "6";
		case SEVEN: return "7";
		case EIGHT: return "8";
		case NINE: return "9";
		case TEN: return "10";
		case J: return "J";
		case Q: return "Q";
		case K: return "K";
		case A: return "A";
		}
	}
public:
	
	Card() : mark(CLOVER), number(TWO) {}
	Card(Mark m, Number n) : mark(m), number(n)
	{

	}

	Mark GetMark() { return mark; }

	Number GetNumber() { return number; }


	string GetMarkString()
	{
		return SetMarkString();
	}
	string GetNumberString()
	{
		return SetNumberString();
	}

	string GetCardString();
	
	void SetFH(bool type) { isFromHand = type; }

	bool FromHand() { return isFromHand; }

	bool operator<(const Card& otherCard) const;
	
};

