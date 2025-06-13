#pragma once
#include "Consumable.h"
class Potion : public Consumable
{
public:
	string name = "Potion";
	void Use() override;
};

