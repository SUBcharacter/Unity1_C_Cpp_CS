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