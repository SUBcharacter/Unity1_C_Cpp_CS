#pragma once
#include "Vehicle.h"
class Boat : public Vehicle
{
private:
	int fuel;

public:
	Boat(const char* name, int speed, int fuel) : fuel(fuel),Vehicle(name, speed) {}
	void Move() override;

	~Boat();
};

