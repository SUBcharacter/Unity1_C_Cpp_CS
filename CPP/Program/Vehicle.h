#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	const char* name;
	int speed;


public:
	Vehicle(const char* name, int speed) : name(name), speed(speed) 
	{
		cout << "Created " << name << endl;
	}
	virtual void Move();

	virtual ~Vehicle();
};

