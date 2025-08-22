#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum Mark
{
	CLOVER = 1,
	HEART,
	DIAMOND,
	SPADE
};

enum Rank
{
	ACE = 1,
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING
};