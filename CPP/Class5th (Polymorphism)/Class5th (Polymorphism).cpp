#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include "../Program/Potion.h"
#include "../Program/Band.h"
#include "../Program/FirstAid.h"
using namespace std;


void Square(int x)
{
	cout << "area : " << x * x << endl;
}

void Square(double x)
{
	cout << "area : " << x * x << endl;
}

int main()
{
#pragma region 다형성

	// 여러개의 서로 다른 객체가 동일한 기능을 서로 다른 방법으로 처리할 수 있는 작업
	// 다형성은 컴파일 시점에 함수와 속성이 결정되는 정적 바인딩을 하지 않고,
	// 실행 시간에 함수와 속성이 결정될 수 있는 동적 바인딩을 가능하게 한다

#pragma region 함수의 오버로딩

	// 같은 이름의 함수를 매개변수의 자료형과 갯수로 구분하여 여러 개를 선언 할 수 있는 기능

	// 함수의 오버로딩의 경우 함수의 매개 변수에 전달하는 인수의 형태를 보고 호출하므로,
	// 반환형으로 함수의 오버로딩

	//Square(3);
	//Square(3.0);

#pragma endregion

#pragma region 함수의 오버라이딩

	// 상위 클래스에 있는 함수를 하위 클래스에서 재정의하여 사용하는 기능
	// 함수의 오버라이딩은 상속 관계에서만 이루어지며,
	// 하위 클래스에서 함수를 재정의할 때 상위 클래스의 함수 형태와 일치해야 한다


	Potion health;
	Band band;
	FirstAid FA;

	Consumable* x[10] = {};

	int input = 0;

	while (true)
	{
		system("cls");

		cout << "Current Inventory:\n";
		for (int i = 0; i < 10; ++i) {
			cout << i + 1 << ": ";
			if (x[i] != nullptr)
				cout << x[i]->name << " (" << x[i]->count << " left)\n";
			else
				cout << "Empty\n";
		}

		cout << "Select create item" << endl << endl;
		cout << "1_ Potion\n" << "2_ Band\n" << "3_ First Aid Kit" << endl << endl;
		cin >> input;

		int insertPtr = -1;

		for (int i = 0; i < 10; i++)
		{
			if (x[i] == nullptr)
			{
				insertPtr = i;
				break;
			}
		}

		if (insertPtr == -1)
		{
			cout << "Inventory is full!!" << endl;
		}


		switch (input)
		{
		case 1: x[insertPtr] = new Potion(); break;
		case 2: x[insertPtr] = new Band(); break;
		case 3: x[insertPtr] = new FirstAid(); break;
		}

		cout << "Select Use Item" << endl << endl;


		int useItem;
		cin >> useItem;

		if (useItem < 1 || useItem >10 || x[useItem - 1] == nullptr)
		{
			cout << "No Item" << endl;
			_getch();
			continue;
		}

		x[useItem - 1]->Use();

		if (x[useItem - 1]->count == 0)
		{
			delete x[useItem - 1];
			x[useItem - 1] = nullptr;
			cout << "No." << useItem << " space has been empty!!" << endl;
		}
		_getch();
	}

	for (int i = 0; i < 10; i++)
	{
		delete x[i];
	}
#pragma endregion


#pragma endregion


	return 0;
}


