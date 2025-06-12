#pragma once
#include "Vehicle.h"
class Scooter : public Vehicle
{
private:
	int fuel;

public:
	Scooter(const char* name,int speed,int fuel) : fuel(fuel), Vehicle(name,speed) {}
	void Move() override;

	~Scooter();
};

