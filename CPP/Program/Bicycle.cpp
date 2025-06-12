#include "Bicycle.h"

void Bicycle::Move()
{
	cout << name << " is move in " << speed << " km/h" << endl << endl;
	cout << "No fuel" << endl << endl << endl;
}

Bicycle::~Bicycle()
{
	cout << name << " has been destroyed" << endl << endl;
}
