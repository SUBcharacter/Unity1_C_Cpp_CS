#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void Process(int* number)
{
	printf("Process 함수 호출됨.\n\n");
	printf("현재 숫자 : %d\n", *number);
	*number += 30;
	printf("숫자 변환 됨\n\n");
	
}

void Stat(int health, const char* name)
{
	printf("닉네임 : %s\n\n", name);
	printf("체력 : %d/100\n\n\n", health);
}

void Switching1(int a, int b)
{
	printf("교환 전 숫자 | a = %d, b = %d\n\n", a, b);
	int temp = b;
	b = a;
	a = temp;

	printf("교환 된 숫자 | a = %d, b = %d\n\n\n", a, b);

}

void Switching2(int* a, int* b)
{
	int temp = *b;  // 매개변수 b에 들어온 주소를 역참조한 값을 temp에 저장

	*b = *a;  // 매개변수 a의 역참조 값을 매개변수 b의 역참조 값으로 대입
	*a = temp; // 매개변수 a의 역참조 값에 temp(b의 역참조 값)의 값을 대입
}

void main()
{
#pragma region 함수

	// 하나의 특별한 목적의 작업을 수행하기 위해
	// 독립적으로 설계된 코드의 집합
	// 함수는 프로그램이 실행 중일 때 함수 호출 위치에서
	// 해당 함수로 이동시킨 두, 작업을 수행하고
	// 다시 원래 위치로 돌아오는 구조
	//int testing = 10;
	//printf("testing : %d\n",testing);
	//
	//Process(&testing);
	//
	//printf("testing : %d\n",testing);
#pragma endregion

#pragma region 매개변수

	// 함수의 정의에서 전달받은인수를 함수 내부로
	// 전달하기 위해 사용하는 변수
	//매개 변수는 함수 내부에서만연산이 이루어지며,
	// 여러개의 매백 변수르 생성할 수 있음

	//int health = 80;
	//char* name = "Goblin";
	//
	//Stat(health, name);
	//Stat(90, "Orc");
	//Stat(100, "Fenrir");

#pragma endregion

#pragma region 인수

	// 함수가 호출될 때 매개 변수에 실제로 전달되는 값
	// 인수의 경우 값을 전달하는 인수와 값을 전달받는 매개 변수의 자료형이 서로 일치해야 함

	Switching1(30, 10);

	int x = 100;
	int y = 50;

	printf("교환 전 숫자 : x = %d, y = %d\n\n", x, y); // 교환 전 숫자를 출력

	Switching2(&x, &y);  // 매개 변수로 x와 y의 주소값을 전달

	printf("교환 후 숫자 : x = %d, y = %d\n\n", x, y); // 교환 후 숫자를 출력
#pragma endregion

}

