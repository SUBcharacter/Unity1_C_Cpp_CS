#include "Card.h"

string Card::GetCardString()
{
	return GetMarkString() + GetNumberString();
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
