#include "Consumable.h"

void Consumable::Use()
{
	count--;
	cout << "Using Consumable...." << endl;
	cout << "Remain : " << count << endl;
}
