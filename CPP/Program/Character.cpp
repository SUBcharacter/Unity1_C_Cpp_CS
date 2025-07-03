#include "Character.h"

void Character::Partner(const shared_ptr<Character>& pointer)
{
	if (pointer == nullptr)
	{
		cout << "partner is gone" << endl;
	}
	else
	{
		resource = pointer;
	}
}
