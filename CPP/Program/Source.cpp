#include <iostream>
#include "Packet.h"
#include "Resource.h"
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

	shared_ptr<Resource> oil = make_shared<Resource>();
	shared_ptr<Resource> mineral = make_shared<Resource>();

	oil->SetAmount(100);
	mineral->SetAmount(150);

	oil->GetAmount();
	mineral->GetAmount();

	cout << "Used Count : " << oil.use_count() << endl;

	oil->partner = mineral;
	mineral->partner = oil;
	


#pragma endregion

	
#pragma endregion


	return 0;
}


