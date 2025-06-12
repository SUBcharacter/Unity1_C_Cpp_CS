#pragma once
#include "Vehicle.h"
class Bicycle : public Vehicle
{

public:
	Bicycle(const char* name, int speed) : Vehicle(name, speed) {}
	void Move() override;

	~Bicycle();
};

