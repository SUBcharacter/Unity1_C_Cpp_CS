#pragma once
#include <iostream>

using namespace std;

class Resource
{
private:
public:
	int amount;
	shared_ptr<Resource> partner;
	Resource() { cout << "Create Resource" << endl; }

	void SetAmount(int a);
	void GetAmount();
	void Share(const shared_ptr<Resource>& pointer);

	~Resource() { cout << "Release Resource" << endl; }

};

