#include "Card.h"

string Card::GetCardString()
{
	return GetMarkString() + GetNumberString();
}

void Card::PrintCard(int x, int y)
{
	int totalWidth = 6;
	int leftPadding = (totalWidth - GetCardString().length()) / 2;
	int rightPadding = totalWidth - GetCardString().length() - leftPadding;
	string symbol = "|" + string(leftPadding, ' ') + GetCardString() + string(rightPadding, ' ') + "|";
	GotoXY(x, y);
	cout << " ______ ";
	GotoXY(x, y+1);
	cout << "|      |";
	GotoXY(x, y+2);
	cout << "|      |";
	GotoXY(x, y+3);
	cout << symbol;
	GotoXY(x, y+4);
	cout << "|      |";
	GotoXY(x, y+5);
	cout << "|      |";
	GotoXY(x, y+6);
	cout << "|______|";

}


bool Card::operator<(const Card& otherCard) const
{
	if (number != otherCard.number)
	{
		return number < otherCard.number;
	}
	else
		return mark < otherCard.mark;
}

bool Card::operator==(const Card& otherCard) const
{
	return number == otherCard.number && mark == otherCard.mark;
}

bool Card::CompareNumber1(Card& a, Card& b)
{
	return a.number > b.number;
}

bool Card::CompareNumber2(Card& a, Card& b)
{
	return a.number < b.number;
}
