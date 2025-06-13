#include "Potion.h"

void Potion::Use()
{
	count--;
	cout << "Using Potion..." << endl;
	cout << "Health Recovered!" << endl;
	cout << "Remain : " << count << endl;
}