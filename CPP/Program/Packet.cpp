#include "Packet.h"

void Packet::SetNumber(int a)
{
	number = a;
}

void Packet::GetNumber()
{
	cout << "The number is " << number << endl;
}

void Packet::Receive(unique_ptr<Packet>&& ptr)
{
	ptr = move((unique_ptr<Packet>)this);
	cout << "Received" << endl;
}
