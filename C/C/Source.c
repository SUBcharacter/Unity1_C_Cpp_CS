#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
#pragma region 배열

	// 같은 자료형의 변수들로 이루어진 유한 집합
	// 배열의 경우 첫 번째 원소는 0부터 시작	

	//int array[1000];
	//int count = sizeof(array) / sizeof(int);
	//printf("배열의 크기 : %d\n\n", count);
	//
	//for (int i = 1; i <= count; i++)
	//{
	//	array[i-1] = 10 * i;
	//	printf("대입 x-%d : %d\n", i, array[i-1]);
	//}
	
	// 배열은 원하는 원소에 원하는 값을 저장할 수 있으며,
	// 배열의 크기는 컴파일 되는 시점부터 고정된 메모리 공간을 가지게 된다

	//int list[5] = { 1, 2, 3, 4, 5 };
	//
	//int* pointer = list;
	//printf("list[0] : %d\n", list[0]);
	//printf("list[0] address : %p\n", pointer);
	//*pointer = 99;
	//
	//printf("list[0] : %d\n\n", list[0]);
	//
	//
	//printf("list[1] : %d\n", list[1]);
	//printf("list[1] address : %p\n", pointer+1);
	//pointer++;
	//*pointer = 100;
	//
	//printf("list[1] : %d\n", list[1]);

	// 배열의 크기는 생략할 수 있으며, 초기화 목록에서 설정한 요소에 따라 배열의 크기가 결정됨

	//float container[ ] = { 10.5f,20.8f,35.6f,31.4f };
	

#pragma endregion

#pragma region 문자열

	// 연속적인 메모리 공간에 저장된 문자 변수의 집합
	// 문자열의 경우 포인터를 이용하여
	// 문자열 상수를 가리키도록 할 수 있으며,
	// 문자열 상수는 데이터 영역에 읽기 전용 공간에 저장되기 때문에,
	// 문자열의 값을 변경할 수 없다

	//const char* Title = "Call of Duty : Modern Warfare";
	//printf("%s\n", Title);

	// 문자열은 공백도 함께 메모리 공간에 포함하여 크기가 결정되며,
	// 마지막에 문자열의 끝을 알려주는 제어 문자가 포함된다

	//Title = "Battle Field";
	
	//printf("%s\n", Title);

	// 문자열을 저장하게 되면 맨 마지막에 무효의 문자까지 메모리 공간에 저장된다

	//char name[] = "Bob Robert";
	//char* const name2 = "Bob Robert";
	//printf("%s\n", name);
	//
	//name[0] = 'J';
	//name[1] = 'i';
	//name[2] = 'm';
	//
	//printf("%s\n", name);

#pragma endregion

#pragma region 과제

	/*
	* 아스키 코드, 유니코드 조사 및 활용
	*/

	// 아스키코드(American Standard Code for Information Interchange)
	// 미국정보교환표준부호
	// 다양한 문자들을 0~127까지의 숫자로 표현할 수 있게 만든 것
	// C언어에서 문자를 표현할 때 주로 사용된다.
	// Ex.

	int character = 'A';

	printf("아스키 코드 숫자 : %d\n", character);
	printf("아스키 코드 문자 : %c\n", character);

	// 표현되는건 문자이지만, 숫자와도 연산할 수 있다.
	// Ex.
	
	character += 1;
	printf("아스키 코드 숫자 : %d\n", character);
	printf("아스키 코드 문자 : %c\n", character);
	//---------------------------------------------------------

	// 유니코드
	// 전세계 모든 문자를 일관되게 표현할 수 있도록 설계된 산업 표준
	// C언어에서는 주로 사용되지 않지만 출력할 수 있는 방법은 있다.
	// Ex.
	
	printf("유니코드(A) : \u0041");

#pragma endregion


}