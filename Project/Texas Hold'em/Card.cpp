#include "Card.h"

string Card::GetCard()
{
	return GetMark() + GetNumber();
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