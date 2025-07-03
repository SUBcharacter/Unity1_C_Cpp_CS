#include <iostream>
#include "../Program/Packet.h"
#include "../Program/Resource.h"
#include "../Program/Character.h"
using namespace std;

int main()
{
#pragma region Smart Pointer

#pragma region unique Pointer

	// 특정한 객체를 하나의 스마트 포인터만 가리킬 수 있도록 되어 있는 포인터
	// 복사 불가, 소유권 이전 가능

	//unique_ptr<Packet> ptr1 = make_unique<Packet>();
	//unique_ptr<Packet> ptr2;
	//
	//ptr1->SetNumber(30);
	//ptr1->GetNumber();
	//
	//ptr1->Receive(move(ptr2));
	//
	//ptr2->SetNumber(60);
	//ptr2->GetNumber();

#pragma endregion

#pragma region Shared Pointer

	// 하나의 자원 객체를 여러 포인터 객체가 가리킬 수 있으며,
	// 모든 포인터 객체가 자원 객체를 필요하지 않을 때 자원 객체를
	// 해제하도록 설계되어 있는 포인터

	//shared_ptr<Resource> oil = make_shared<Resource>();
	//shared_ptr<Resource> mineral = make_shared<Resource>();
	//
	//oil->SetAmount(100);
	//mineral->SetAmount(150);
	//
	//oil->GetAmount();
	//mineral->GetAmount();
	//
	//cout << "Used Count : " << oil.use_count() << endl;
	//
	//oil->Share(mineral);
	//mineral->Share(oil);

#pragma endregion

#pragma region R,L value

	// rvalue(Right Value) : 임시 값, 대입연산의 오른쪽에만 올 수 있음, 이후 사라지는 값
	// lvalue(Left Value) : 메모리 주소를 갖는 값, 참조할 이름이 있는 객체, 대입 연산에 왼쪽에 있는 값

	// Ex.
	//int x = 10;    // x는 lvalue, 10은 rvalue
	//int y = x + 5; // y는 lvalue, x + 5는 rvalue, x는 메모리에 존재, 위치를 참조 할 수 있음
	//
	//cout << "x : " << x << endl;
	//cout << "y : " << y << endl;

#pragma endregion

#pragma region Weak Pointer

	// 자원 객체를 소유하지 않기 때문에 공유 포인터로 관리되는 객체를
	// 가리켜서 참조 개수에 영향을 미치지 않게 하는 포인터

	shared_ptr<Character> partner = make_shared<Character>();
	shared_ptr<Character> character = make_shared<Character>();

	partner->Partner(character);
	character->Partner(partner);

	cout << "Reference Count(partner) : " << partner.use_count() << endl;
	cout << "Reference Count(character) : " << character.use_count() << endl;


#pragma endregion


#pragma endregion


	return 0;
}


