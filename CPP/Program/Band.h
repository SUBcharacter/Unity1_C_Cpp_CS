#pragma once
#include "Consumable.h"
class Band : public Consumable
{
public:
	string name = "Band";
	void Use() override;
};

