#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Library.h"

#define SIZE 10

void main()
{
#pragma region 주소 연산자

	// 변수의 주소 값을 반환하는 연산자
	
	//int x = 10;
	//printf("%p", &x);

#pragma region scanf_s 함수

	// 표준 입력 함수로, 여러 종류의 데이터를 다양한 서식에 맞춰 입력하는 함수
	// 표준 입력 함수로 데이터를 입력하게 되면 버퍼에 데이터를 보관하였다가 입력하는 순간
	// 버퍼 안의 내용을 프로그램에 전송한다

	//int a = 0;
	//scanf_s("%d", &a);
	//printf("출력값 : %d", a);

	// 표준 입력 함수는 입력을 수행할 때까지 다음 작업으로 넘어 갈 수 없다

#pragma endregion

#pragma region  포인터

	// 메모리의 주소 값을 저장할 수 있는 변수
	 
	int packet = 10;
	int* packetptr = &packet;

	printf("포인터로 표현 : %p\n", packetptr);
	printf("포인터로 표현 : %p\n", &packet);
	printf("포인터로 표현 : %d\n", *packetptr);
	
	// 포인터 변수도 자신의 메모리 공간을 가지고 있으며
	// 포인터 변수에 변수의 시작 주소를 저장하게 되면,
	// 해당 변수의 시작 주소를 가리키게 된다
#pragma endregion

	//데이터의 주소 값은 해당 데이터가 저장된 메모리의 시작 주소를 의미함
#pragma endregion

}