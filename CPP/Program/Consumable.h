#pragma once
#include <iostream>
using namespace std;

class Consumable
{
protected:
public:
	string name;
	int count = 10;
	virtual void Use();

#pragma region 가상함수

	// 가상 함수 테이블을 사용하여 함수가 호출되는 시간을 런타임에 결정하며,
	// 한 개 이상의 가상 함수를 포함하는 클래스가 있을 대 가상 함수 포인터가 추가된다
	// 가상함수는 실행 시간에 상위 클래스에 대한 참조로 하위 클래스에 재정의된 함수를 호출할 수 있다

#pragma endregion

};

