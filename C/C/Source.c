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
	 
	//int packet = 10;
	//int* pointer = &packet;
	//
	//printf("packet의 주소 : %p\n", &packet);
	//printf("packetptr의 주소 : %p\n\n", pointer);
	//printf("packet의 값 : %d\n", packet);
	//printf("packetptr 역참조 값 : %d\n\n", *pointer);
	
	// 포인터 변수도 자신의 메모리 공간을 가지고 있으며
	// 포인터 변수에 변수의 시작 주소를 저장하게 되면,
	// 해당 변수의 시작 주소를 가리키게 된다

	//*pointer = 99;
	//
	//printf("*packetptr = 99; 이후\n\n");
	//printf("packet의 값 : %d\n", packet);
	//printf("packetptr 역참조 값 : %d\n\n\n\n", *pointer);

	// 포인터 변수는 포인터가 가리키는 메모리 공간의 자료형은
	// 알 수 없으므로, 포인터가 가리키는 메모리의 자료형을 선언 해주어야 함.

	// 포인터 변수의 크기는 중앙 처리 장치가 한 번에 처리할 수 있는 크기로 정해지며,
	// 한 번에 처리할 수 있는 크기는 운영 체제에 따라 크기가 결정된다.

	//printf("packetptr 변수의 크기 : %u\n", sizeof(packetptr));

	//int storage=0;
	//pointer = &storage;
	//
	//printf("packetptr = &storage; 이후\n\n");
	//printf("storage의 값 : %d\n", storage);
	//printf("packetptr 역참조 값 : %d\n\n", *pointer);
	//*pointer = 20;
	//printf("*packetptr = 20; 이후\n\n");
	//printf("storage의 주소 : %p\n", &storage);
	//printf("packetptr의 주소 : %p\n\n", pointer);
	//printf("storage의 값 : %d\n", storage);
	//printf("packetptr 역참조 값 : %d\n", *pointer);

#pragma endregion

#pragma region 상수 지시 포인터

	// 포인터가 가리키는 주소에 저장되어 있는 값을
	// 변경할 수 없도록 지정되어 있는 포인터

	// 상수 지시 포인터
	// 
	//int height = 10;
	//int width = 20;
	//const int* pointer = &height;
	//
	//printf("height 값 : %d\n", height);
	//printf("height 주소값 : %d\n\n", &height);
	//
	//printf("width 값 : %d\n", width);
	//printf("width 주소값 : %d\n\n", &width);
	//
	//printf("포인터의 값 : %p\n", pointer);
	//printf("포인터 역참조 값 : %d\n\n", *pointer);
	//
	//pointer = &width;
	//printf("pointer 주소 교체\n\n");
	//printf("포인터의 값 : %p\n", pointer);
	//printf("포인터 역참조 값 : %d\n", *pointer);


#pragma endregion

#pragma region 포인터 상수

	// 포인터 변수가 가리키고 있는 주소 값을 변경 할 수 없도록 지정되어 있는 포인터

	//int some= 10;
	//int day = 30;
	//int* const pointer = &some;
	//
	//printf("some 값 : %d\n", some);
	//printf("some 주소값 : %p\n\n", &some);
	//
	//printf("day 값 : %d\n", day);
	//printf("day 주소값 : %p\n\n", &day);
	//
	//printf("pointer 값 : %p\n", pointer);
	//printf("pointer 역참조 값 : %d\n\n", *pointer);
	//
	//*pointer = day;
	//
	//printf("pointer 역참조 값 변경\n\n");
	//printf("pointer 값 : %p\n", pointer);
	//printf("pointer 역참조 값 : %d\n\n" ,*pointer);
	//
	//printf("day 값 : %d\n", day);
	//printf("day 주소값 : %p\n\n", &day);

#pragma endregion

#pragma region 범용 포인터

// 자료형이 정해지지 않은 상태로 모든 자료형을 저장할 수 있는 포인터
int integer = 10;
float realnum = 15.8f;
char yob ='A';

void * pointer = &yob;

printf("pointer 값 : %p\n", pointer);
printf("pointer 역참조 값 : %c\n\n", *(char*)pointer);

*(char*)pointer = 'B';

printf("pointer 값 : %p\n", pointer);
printf("pointer 역참조 값 : %c\n\n", *(char*)pointer);

pointer = &integer;

printf("pointer 값 : %p\n", pointer);
printf("pointer 역참조 값 : %d\n\n", *(int*)pointer);

*(int*)pointer = 50;

printf("pointer 값 : %p\n", pointer);
printf("pointer 역참조 값 : %d\n\n", *(int*)pointer);

pointer = &realnum;

printf("pointer 값 : %p\n", pointer);
printf("pointer 역참조 값 : %f\n\n", *(float*)pointer);

*(float*)pointer = 30.5f;

printf("pointer 값 : %p\n", pointer);
printf("pointer 역참조 값 : %f\n\n", *(float*)pointer);

printf("integer 값 : %d\n\n", integer);
printf("realnum 값 : %f\n\n", realnum);
printf("yob 값 : %c\n\n", yob);

// 범용 포인터는 메모리 주소에 접근해서 값을 변경 할 수 없으므로
// 범용 포인터가 가리키는 변수의 자료형으로 변환해주어야 함

#pragma endregion

	//데이터의 주소 값은 해당 데이터가 저장된 메모리의 시작 주소를 의미함
#pragma endregion

}