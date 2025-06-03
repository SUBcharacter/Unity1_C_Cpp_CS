#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#pragma region 전역 변수

int x = 0;

void SetStage(int up)
{
	printf("x값 변환\n\n");
	x += up;
	x--;
	x *= up;
}
#pragma endregion

void Increase()
{
	static int score = 0;

	score++;
	printf("%d\n\n", score);
}

int main()
{
#pragma region 메모리 영역

	// 메모리 영역 : 낮은 주소 ~ 높은 주소
	// 종류 : CODE, DATA, BSS, HEAP, STACK

#pragma region CODE 영역

	// 프로그램을 실행하기 위해 필요한 코드가 저장되는 영역으로
	// 함수의 주소와 상수가 저장되는 메모리 영역
	// CODE : 함수의 주소 저장

#pragma endregion

#pragma region DATA 영역

	// 프로그램의 시작과 함께 메모리에 저장되며,
	// 프로그램이 종료될 때 메모리가 해제되고,
	// 초기화가 이루어진 전역 변수와 정적 변수가 저장되는 메모리 영역
	// DATA : 초기화가 이루어진 전역 변수 저장, Read Only

#pragma endregion

#pragma region BSS 영역

	// 프로그램이 실행될 때 초기화가 이루어지지 않은 전역 변수와
	// 정적 변수가 저장되는 메모리 영역
	// BSS : 초기화가 이루어지지 않은 전역 변수 저장
#pragma endregion

#pragma region STACK 영역

	// 프로그램이 자동으로 사용하는 임시 메모리 영역으로
	// 함수 호출 시 생성되는 지역 변수와 매개 변수가 저장되는 메모리 영역
	// STACK : 지역 변수, 매개 변수
#pragma endregion

#pragma region HEAP 영역

	// 사용자가 직접 메모리 공간을 저장해주는 메모리 영역이며,
	// 사용하지 앟는 경우 사용자가 직접 메모리를 해제해야 되는 메모리 영역
	// HEAP : 사용자가 직접 할당하는 메모리 영역, malloc으로 할당한 영역
#pragma endregion

#pragma endregion

#pragma region 변수의 범위


#pragma region 지역 변수

	// 함수 내부에서 선언된 변수로 함수 내부에서만 접근할 수 있으며,
	// 함수가 종료되었을 때 메모리에서 사라지는 특징을 가지고 있는 변수
	// 지역 변수는 선언과 동시에 초기화하지 않으면,
	// 이전 메모리 위치에 존재했던 값을 가지게 된다.

	//int x = 10;
	//{ 
	//	int x = 20;
	//	printf("x의 주소 : %p\n\n", x);
	//	printf("x의 값 : %d\n\n\n", x);
	//}
	//printf("x의 주소 : %p\n\n", x);
	//printf("x의 값 : %d\n\n", x);

#pragma endregion

#pragma region 전역 변수

	// 함수 외부에서 선언된 변수로 프로그램이 실행될 때
	// 메모리에 올라가게 되며, 프로그램이 종료 되면 메모리에서 해제되는 변수

	// 전역 변수는 선언과 동시에 초기화가 되어 있지 않으면
	// 자동으로 초기화 된다

	//printf("x의 값 : %d\n\n", x);
	//SetStage(200);
	//printf("x의 값 : %d\n\n", x);
	//
	//printf("x의 주소 : %p", x);

#pragma endregion

#pragma region 정적 변수

	// 프로그램이 실행되는 동안 메모리에 존재하며,
	// 선언된 범위 내에서만 접근이 가능한 특징을 가지고 있는 변수
	// 정적 변수는 단 한번만 초기화가 이루어진다

	Increase();
	Increase();
	Increase();

#pragma endregion


#pragma endregion


	return 0;
}

