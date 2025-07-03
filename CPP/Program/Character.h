#pragma once
#include "Resource.h"
#include <iostream>

using namespace std;

class Character
{
public:
	Character() { cout << "Character Summon" << endl; }

	weak_ptr<Character> resource;

	void Partner(const shared_ptr<Character>& pointer);

	~Character() { cout << "Character Disappeared" << endl; }
};

