#pragma once
#include "Consumable.h"
class FirstAid : public Consumable
{
public:
	string name = "First Aid Kit";
	void Use() override;
};

