#pragma once
#include "Paint.h"
class Brush : public Paint
{
private:
	string color;
public:
	Brush(int thickness, string color) : color(color), Paint(thickness) {}

	virtual void Draw() override;

	~Brush();
};

