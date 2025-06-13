#include "FirstAid.h"

void FirstAid::Use()
{
	count--;
	cout << "Using First Aid Kit...." << endl;
	cout << "Remain : " << count << endl;
}