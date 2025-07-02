#pragma once
#include <iostream>

using namespace std;

class Packet
{
private:
	int number;

public:
	Packet() { cout << "패킷 생성" << endl; }

	void SetNumber(int a);
	void GetNumber();

	void Receive(unique_ptr<Packet>&& ptr);

	~Packet() { cout << "패킷 소멸" << endl; }


};

