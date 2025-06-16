#pragma once
	
#include "UsingLibrary.h"
class Card
{
private:
	Mark mark;
	Number number;

	string SetMark()
	{
		switch (mark)
		{
		case SPADE: return "¢¼";
		case DIAMOND: return "¡ß";
		case HEART: return "¢¾";
		case CLOVER: return "¢À";
		}
	}

	string SetNumber()
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
	

	Card(Mark m, Number n) : mark(m), number(n)
	{

	}


	string GetMark()
	{
		return SetMark();
	}
	string GetNumber()
	{
		return SetNumber();
	}

	string GetCard();
	
};

