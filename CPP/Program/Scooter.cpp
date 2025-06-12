#include "Scooter.h"

void Scooter::Move()
{
	cout << name << " is move in " << speed << " km/h" << endl << endl;
	cout << "fuel : " << fuel << "L" << endl << endl << endl;

}

Scooter::~Scooter()
{
	cout << name << " has been destroyed" << endl << endl;
}
