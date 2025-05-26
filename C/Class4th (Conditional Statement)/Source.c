#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
#pragma region 반복문 과제

	//for (int i = 1; i <= 9; i++)
	//{
	//	for (int j = 1; j <= 9; j++)
	//	{
	//		int multi = i * j;
	//		printf("%d X %d = %d\n\n", i, j, multi);
	//	}
	//	printf("다음으로...(아무키 입력)\n\n\n");
	//	_getch();
	//}

#pragma endregion

#pragma region 조건문

	// 어떤 조건이 주어질 때 해당 조건에 따라 동작을 수행하도록 실행하는 명령문

#pragma region 관계 연산자

	// 두 개의 피연산자의 값을 비교하여 그 결과를 0 또는
	// 1이라는 값으로 나타내는 연산자

	// > : 왼쪽의 값이 더 크다면
	// < : 오른쪽의 값이 더 크다면
	// >= : 왼쪽의 값이 크거나 같다면
	// <= : 오른쪽의 값이 크거나 같다면
	// == : 값이 서로 같다면
	// != : 값이 서로 다르다면

	//int state1 = 11 > 10;
	//int state2 = 9 < 10;
	//int state3 = 11 >= 10;
	//int state4 = 9 <= 10;
	//int state5 = 10 == 10;
	//int state6 = 9 != 10;
	//
	//printf("%d", state1);
	//printf("%d", state2);
	//printf("%d", state3);
	//printf("%d", state4);
	//printf("%d", state5);
	//printf("%d", state6);

#pragma endregion

#pragma region if문

	// 어떤 특정한 조건을 비교하여 조건이 맞다면 실행되는 조건문
	// if(문은 조건이 1일떄 실행되며, 0일 때 실행되지 않는다

	//int a = _getch();
	//
	//if (a == '1')
	//{
	//	printf("1번 실행중");
	//}
	//else if (a == '2')
	//{
	//	printf("2번 실행중");
	//}
	//else
	//{
	//	printf("잘못된 입력");
	//}

#pragma endregion 

#pragma region else if 문

	// if문에서 여러 개의 조건을 순차적으로 검사하고 싶을때 사용하는 조건문
	// else if문의 경우 여러개를 사용할 수 있으며, if문 부터 위에서 하나씩 검사하다가
	// 가장 먼저 조건이 맞는 분기로 들어감

	//int x = _getch();
	//
	//if (x == 'q')
	//{
	//	printf("첫번째 메뉴");
	//}
	//else if (x == 'w')
	//{
	//	printf("두번째 메뉴");
	//}
	//else if (x == 'e')
	//{
	//	printf("나가기");
	//	return;
	//}



#pragma endregion

#pragma region else 문

	// if문을 포함한 여러 조건문에서 모든 조건이 맞지 않을때 실행되는 조건문
	// if문에 연결된 모든 조건문의 조건이 맞을 때 가장 위에 있는 조건문만 실행됩니다.

//int number = 0;
//scanf("%d", &number);
//
//if (number > 0)
//{
//	printf("양수 number의 수 : %d", number);
//}
//else if (number < 0)
//{
//	printf("음수 number의 수 : %d", number);
//}
//else
//{
//	printf("number의 수 : %d", number);
//}

#pragma endregion

#pragma region 논리 연산자

// 두 개 이상의 조건을 결합하거나 하나의 조건을 반전시키는 연산자

#pragma region And 연산자

//두개의 조건이 맞다면 실행되는 연산자

//srand((unsigned int)time(NULL));
//
//int count = 0;
//while (1)
//{
//	int sub1 = 30;
//	int sub2 = rand() % 31;
//	int sub3 = rand() % 50;
//	
//	if (sub1 == sub2 && sub3 == 40)
//	{
//		printf("조건 달성\n");
//		printf("시도 횟수 : %d", count);
//		break;
//	}
//	else
//	{
//		printf("조건 미달성\n");
//	}
//	count++;
//}
#pragma endregion

#pragma region Or 연산자

// 두 개의 조건 중 하나라도 맞다면 실행되는 연산자
// 조건문의 논리 표현식을 평가하는 도중,
// 결과가 이미 확정났다면, 그 이후의 평가를 생략

//srand((unsigned int)time(NULL));
//int count = 0;
//while (1)
//{
//	count++;
//	int sub1 = rand() % 50;
//	int sub2 = rand() % 50;
//	int sub3 = rand() % 50;
//
//	if (sub1 == sub2 || sub2 == sub3)
//	{
//		printf("조건 달성\n");
//		printf("시도 횟수 : %d", count);
//		break;
//	}
//	else
//	{
//		printf("조건 미달성\n");
//	}
//	
//}

#pragma endregion

#pragma region Not 연산자

// 하나의 조건을 반전시키는 연산자

//srand((unsigned int)time(NULL));
//int count = 0;
//
//while (1)
//{
//	int sub1 = rand() % 10;
//	int sub2 = rand() % 50;
//	count++;
//	if (!(sub1 < sub2))
//	{
//		printf("조건 달성\n");
//		printf("sub1 : %d , sub2 : %d\n", sub1, sub2);
//		printf("시도 횟수 : %d", count);
//		break;
//	}
//	else
//	{
//		printf("조건 미달성\n");
//	}
//}


#pragma endregion

#pragma region 사분면

//while (1)
//{
//	system("cls");
//	printf("좌표값 입력 :");
//	int x = 0;
//	int y = 0;
//
//	scanf_s("%d %d", &x, &y);
//
//	if (x > 0 && y > 0)
//	{
//		printf("좌표값 : (%d, %d)\n", x, y);
//		printf("제 1 사분면\n");
//	}
//	else if (x < 0 && y>0)
//	{
//		printf("좌표값 : (%d, %d)\n", x, y);
//		printf("제 2 사분면\n");
//	}
//	else if (x < 0 && y < 0)
//	{
//		printf("좌표값 : (%d, %d)\n", x, y);
//		printf("제 3 사분면\n");
//	}
//	else if (x > 0 && y < 0)
//	{
//		printf("좌표값 : (%d, %d)\n", x, y);
//		printf("제 4 사분면\n");
//	}
//	else if (x == 0 && y != 0)
//	{
//		printf("좌표값 : (%d, %d)\n", x, y);
//		printf("X 절편\n");
//	}
//	else if (x != 0 && y == 0)
//	{
//		printf("좌표값 : (%d, %d)\n", x, y);
//		printf("Y 절편\n");
//	}
//	else
//	{
//		printf("좌표값 : (%d, %d)\n", x, y);
//		printf("원점\n");
//	}
//	_getch();
//}
#pragma endregion

#pragma endregion

#pragma region switch 문

// 어떤 결과에 따라 그 결과부터 실행되는 명령문
// switch문에는 조건식으로 실수형 변수와 실수형 상수를 선언할 수 없음.

	int state;
	scanf_s("%d", &state);

	switch (state)
	{
	case 0: printf("Idle State"); break;
	case 1: printf("Attack State"); break;
	case 2: printf("Die State"); break;
	default: printf("Exception\n");  break;
	}
#pragma endregion

#pragma endregion
}