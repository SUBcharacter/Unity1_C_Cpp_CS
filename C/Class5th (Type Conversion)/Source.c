#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "../C/Library.h"

#define SIZE 10

void main()
{
#pragma region 자료형 변환

	// 서로 다른 자료형을 가지고 있는 변수끼리 연산이 이루어질 때
	// 기존에 저장했던 자료형을 다른 자료형으로 변환하는 과정

#pragma region 암묵적 형 변환

	// 서로 다른 자료형으로 연산이 이루어질때 자료형의 크기가
	// 큰 자료형으로 변환되는 과정

	// 표현 범위가 작은 데이터에 표현 범위가 큰 데이터를 저장하게 되면
	// 암묵적으로 데이터 손실이 발생

	//int integer = 100;
	//float realnumber = 36.5f;
	//
	//printf("char 자료형의 크기 : %u\n", sizeof(integer+realnumber));
#pragma endregion

#pragma region 명시적 형 변환
	// 연산이 이루어지기 전에 사용자가 직접 자료형을 변환하는 과정 

	//int a = 10;
	//int b = 9;
	//
	//float x =  (float)a/b;
	//
	//printf("%f", x);
#pragma endregion

#pragma endregion

#pragma region 전처리기

	// 프로그램이 컴파일되기 이전에 프로그램에 대한 사전 처리 과정
	// 전처리기는 컴파일러가 아닌 선행처리기에 의해 처리되는 문장이기 때문에
	// 명령문 끝에 ':'을 사용하지 않움

#pragma region 매크로

	// 프로그램 내에서 특정한 데이터가 문자열로 정의되고 처리되는 과정

	//printf("SIZE의 값 : %d\n", SIZE);

	// 매크로의 경우 자료형이 존재하지 않으므로, 메모리 공간을 가지고 있지 않다
	// 매크로의 과정은 컴파일 이전에 실행되며,
	// 각 매크로가 실행될 때 매크로의 대체 목록을 넣어야 하므로
	// 프로그램의 크기가 커지게 된다
#pragma endregion

	//printf("channel 변수의 값 : %d\n",channel);

#pragma endregion

}