#include "Resource.h"

void Resource::SetAmount(int a)
{
	amount = a;
}

void Resource::GetAmount()
{
	cout << "this Resource's amount is " << amount << endl;
}

void Resource::Share(const shared_ptr<Resource>& pointer)
{
	partner = pointer;
}
