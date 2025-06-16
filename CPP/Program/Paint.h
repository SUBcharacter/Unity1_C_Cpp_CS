#pragma once
#include <iostream>
#include <string>
using namespace std;

class Paint
{
protected:
	int thickness;
public:
	Paint(int thick) : thickness(thick) {}
	virtual void Draw() = 0;
	~Paint();
};

