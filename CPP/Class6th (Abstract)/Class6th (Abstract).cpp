#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include "../Program/Brush.h"
#include "../Program/Pencil.h"
#include "../Program/Vector2.h"

using namespace std;

int main()
{
#pragma region 추상 클래스

	// 함수에 특정한 내용이 구현되어 있지 않고, 선언만 되어있는 클래스
	// 추상 클래스는 정의되어 있지 않은 함수가 있으므로, 객체를 생성할 수 없음

	//Paint* p = new Pencil(10);
	//
	//p->Draw();


#pragma endregion

#pragma region 연산자 오버로딩

	Vector2 point1D(3, 4);
	Vector2 point2D(1, 2);

	Vector2 direction = point1D + point2D;

	cout << "Direction Vector : (" << direction.x << ", " << direction.y << ")" << endl;

#pragma endregion


	return 0;
}


