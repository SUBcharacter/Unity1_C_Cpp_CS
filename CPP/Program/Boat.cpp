#include "Boat.h"

void Boat::Move()
{
	cout << name << " is move in " << speed << " km/h" << endl << endl;
	cout << "fuel : " << fuel << "L" << endl << endl << endl;
}

Boat::~Boat()
{
	cout << name << " has been destroyed" << endl << endl;
}
