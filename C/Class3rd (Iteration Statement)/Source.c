#include <stdio.h>

void main()
{
#pragma region 대입 연산자 과제

	//int plus = 0;
	//int minus = 0;
	//long long multi = 1;
	//long long divid = 10000000000000;
	//
	//for (int i = 1; i <= 10; i++)
	//{
	//	system("cls");
	//
	//	printf("대입 연산자 (10회 반복 실행)\n\n\n");
	//	printf("+= 의 경우 : %d\n\n", plus);
	//	printf("-= 의 경우 : %d\n\n", minus);
	//	printf("*= 의 경우 : %lld\n\n", multi);
	//	printf("/= 의 경우 : %lld\n\n", divid);
	//
	//	plus += i;
	//	minus -= i;
	//	multi *= i;
	//	divid /= i;
	//
	//	Sleep(200);
	//}

#pragma endregion

#pragma region 반복문

	// 프로그램 내에서 특정한 작업을 반복적으로 수행하는 명령문

	// for, while 문

	// for(초기식;조건식;증감식){반복할 코드}

	// while(조건){반복할 코드}

#pragma region 증감 연산자

	// 피연산자를 하나씩 증가시키거나 감소시킬 때
	// 사용하는 연산자

	/*
	* 종류는 ++, --
	* 위치에 따라 조금씩 다름
	*/

#pragma region 전위 증감 연산자

	// 변수의 값을 증감시킨 후에 연산을 수행하는 연산자

	//int a = 0;
	//int b = ++a;
	//
	//printf("a:%d b:%d\n\n", a, b);
	//
	//b = --a;
	//
	//printf("a:%d b:%d\n\n", a, b);

	/*
	* 연산 과정
	* - a에 0 할당
	* - a를 1 증감 시킨 후 b에 할당
	* - 결과 a와 b 둘다 1이 할당
	*/

#pragma endregion

#pragma region 후위 증감 연산자

	// 연산을 수행한 다음 변수의 값을 증감시키는 연산자.

	//int x = 0;
	//int y = x++;
	//
	//printf("x : %d  y : %d\n\n", x, y);
	//
	//y = x--;
	//
	//printf("x : %d  y : %d", x, y);

	/*
	* 연산 과정
	* - x에 0을 할당
	* - y에 x를 할당 후, x를 1증가
	* - x는 1, y는 0이 할당됨
	*/

#pragma endregion


#pragma endregion

#pragma region for문

	// 초기실을 연산하여 조건시의 결과에 따라 특정한 수 만큼 반복하는 반복문
	// 반복문이 동작하는 순서는 초기화 -> 조건 검사 -> 실행 -> 증감

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("실행중.");
	//	Sleep(500);
	//	system("cls");
	//	printf("실행중..");
	//	Sleep(500);
	//	system("cls");
	//	printf("실행중...");
	//	Sleep(500);
	//	system("cls");
	//	printf("실행중....");
	//	Sleep(500);
	//	system("cls");
	//	printf("실행중...");
	//	Sleep(500);
	//	system("cls");
	//	printf("실행중..");
	//	Sleep(500);
	//	system("cls");
	//	printf("실행중.");
	//	Sleep(500);
	//	system("cls");
	//}

#pragma endregion

#pragma region while 문

// 특정 조건을 만족할 때까지 계속해서 주어진 명령문을 실행하는 반복문
// 반복문을 순차적으로 실행하면서 조건 분기를 만나게 되면
// 어느 쪽으로 실행흐름이 갈지 미리 예측한다
//int a = 0;
//while (a< 300)
//{
//	system("cls");
//	a += 20;
//	printf("현재 a의 값 : %d", a);
//	Sleep(250);
//}

#pragma endregion

#pragma region do while 문

// 조건과 상관없이 한번의 작업을 수행한 다음
// 조건에 따라 명령문을 실행하는 반복문
// 반복문의 경우 미리 예측해서 실행하는 구조를 가지며,
// 예측이 틀렸다면 현재 반복문 내의 조건 분기만 다시 검사하여 처리

int a = 0;

do
{
	system("cls");
	a += 20;
	printf("조건 : a가 3000을 초과 하기 전까지 반복\n");
	printf("현재 a의 값 : %d\n\n", a);
	Sleep(100);

} while (a<3000);

printf("반복 종료");

#pragma endregion

#pragma region nested for 문

//char 배열[10][10];
//
//for (int i = 0; i < 10; i++)
//{
//	for (int j = 0; j < 10; j++)
//	{
//		배열[i][j] = 'A'+i;
//	}
//}
//
//for (int i = 0; i < 10; i++)
//{
//	for (int j = 0; j < 10; j++)
//	{
//		printf("%c", 배열[i][j]);
//	}
//	printf("\n");
//}

#pragma endregion

#pragma endregion


}