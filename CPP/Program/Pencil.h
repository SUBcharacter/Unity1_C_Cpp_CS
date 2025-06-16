#pragma once
#include "Paint.h"
class Pencil : public Paint
{
private:
	string color = "Black";
public:
	Pencil(int thick) : Paint(thick) {}
	virtual void Draw() override;

	~Pencil();
};

