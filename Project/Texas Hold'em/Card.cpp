#include "Card.h"

string Card::GetCard()
{
	return GetMark() + GetNumber();
}
