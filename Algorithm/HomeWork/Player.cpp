#include "Player.h"

Player::Player()
{
	health = 100;
}

void Player::setHealth(int x)
{
	health = x;
}

int Player::getHealth()
{
	return health;
}
