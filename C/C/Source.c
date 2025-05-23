#include <stdio.h>
#include <conio.h>

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


}