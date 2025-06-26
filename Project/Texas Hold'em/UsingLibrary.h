#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include "UIManager.h";

using namespace std;

enum Mark
{
	CLOVER,
	HEART,
	DIAMOND,
	SPADE
};

enum Number
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	J,
	Q,
	K,
	A
};

enum Acting
{
	RAISE,
	CALL,
	CHECK,
	DIE,
	DEFAULT
};

enum HandRank
{
	NONE,
	HIGHCARD,
	ONEPAIR,
	TWOPAIR,
	TRIPLE,
	STRAIGHT,
	FLUSH,
	FULLHOUSE,
	FOURCARD,
	STRAIGHTFLUSH,
	ROYALSTRAIGHTFLUSH
};