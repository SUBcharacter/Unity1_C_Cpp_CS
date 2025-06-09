#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void Shuffle(int list[], int size)
{
	srand((unsigned int)time(NULL));
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		int value = rand() % 10;
		temp = list[value];
		list[value] = list[i];
		list[i] = temp;
	}
}

void Explanation()
{
	system("cls");

	printf("게 임 설 명 !                 스킵하려면 s를 누르세요.\n\n");
	char skip = _getch();
	if (skip == 's')
		return;

	printf("컴퓨터가 가지고 있는 숫자(1 ~ 50)를 맞추면 되는 게임입니다.\n\n");
	skip = _getch();
	if (skip == 's')
		return;

	printf("플레이어가 숫자를 입력하면 숫자를 비교해 숫자가 높은지 낮은지를 알려줍니다.\n\n");
	skip = _getch();
	if (skip == 's')
		return;

	printf("총 5번의 기회 안에 맞추지 못하면 패배하게 됩니다.\n\n");
	skip = _getch();
	if (skip == 's')
		return;

	printf("준비 되셨다면 아무 키나 누르십시오....");
	_getch();
}

void LifeDisplay(int life)
{
	printf("라이프 : ");
	for (int i = 0; i < life; i++)
	{
		printf("♥");
	}
	printf("\n\n");
}

void Play()
{
	srand((unsigned int)time(NULL));

	int randomNumber = rand() % 50 + 1;
	int life = 10;

	Explanation();

	while (true)
	{
		int inputNumber = 0;

		system("cls");

		LifeDisplay(life);
		printf("숫자를 입력해주세요! : ");

		scanf("%d", &inputNumber);

		if (inputNumber == 1099464864)
		{
			printf("디버그 모드 : %d\n\n", randomNumber);
			printf("계속하려면 아무키 입력\n\n");
			_getch();
			continue;
		}

		if (inputNumber == randomNumber)
		{
			system("cls");
			printf("숫자를 맞추셨습니다!\n\n\n");
			printf("V I C T O R Y !!\n\n\n");
			printf("타이틀로 돌아갑니다.\n");
			_getch();
			return;
		}
		else if (inputNumber > randomNumber && inputNumber <= 50)
		{
			system("cls");
			life--;
			printf("틀리셨습니다..... 이것보단 작은 숫자입니다...\n\n");
			printf("남은 기회 : %d\n\n", life);
		}
		else if (inputNumber < randomNumber && inputNumber <= 50)
		{
			system("cls");
			life--;
			printf("틀리셨습니다..... 이것보단 큰 숫자입니다...\n\n");
			printf("남은 기회 : %d\n\n", life);
		}
		else
		{
			printf("범위를 벗어난 숫자입니다. 1 ~ 50 사이의 숫자를 입력해 주십시오.\n\n");
			_getch();
			continue;
		}

		if (life <= 0)
		{
			system("cls");
			printf("아쉽습니다... 기회를 모두 소진 하셨습니다...\n\n");
			printf("랜덤 숫자는 : %d 였습니다...\n\n\n", randomNumber);
			printf("D E F E A T...\n\n\n");

			printf("타이틀로 돌아갑니다.\n");
			_getch();
			return;
		}
		printf("계속하시려면 아무키나 누르십시오.....\n\n");
		_getch();
	}
}

void Title()
{
	while (true)
	{
		system("cls");
		printf("1_ 게임 시작\n\n\n");
		printf("2_ 게임 종료\n\n\n");

		char input = _getch();

		if (input == '1')
		{
			Play();
		}
		else if (input == '2')
		{
			return;
		}
		else
		{
			printf("잘못 된 입력입니다. 다시 시도 하십시오.\n\n");
			_getch();
		}
	}
}

typedef enum
{
	// 저장시에는 정수형으로 저장됨
	// 숫자 순서를 정할수 있음(0~)
	// 순서를 할당한 경우 할당 된 숫자부터 1씩 올라감
	BOW,
	GUN,
	KNIFE = 3,
	SWORD,
	HAMMER

}WeaponCategory;

int main()
{
#pragma region 의사 난수

	// rand() : 0 ~ 32767 사이의 난수의 값을 반환하는 함수
	// time(NULL) : 1970년 1월 1일 (00 : 00 : 00) UTC 이후에 지난 초(Second)를 반환하는 함수
	// srand(seed) : 난수 생성기의 시드를 설정하는 함수

	//srand((unsigned int)time(NULL));
	//int count = 0;
	//
	//for (int i = 0; i < 10000; i++)
	//{
	//	int value = rand() % 100+1;
	//	
	//
	//	if (value > 75)
	//	{
	//		printf("value : %d 당첨!\n", value);
	//		count++;
	//	}
	//	else
	//	{
	//		printf("value : %d\n", value);
	//	}
	//	
	//}
	//
	//printf("25%% 확률 10000회 독립시행 당첨 횟수 : %d/10000", count);

#pragma endregion

#pragma region 셔플 함수

	//srand((unsigned int)time(NULL));
	//
	//int list[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	//
	//int size = sizeof(list) / sizeof(int);
	//
	//int numberTemp = 0;
	//Shuffle(list, size);
	//printf("필드 패 :");
	//for (int i = 0; i < 5; i++)
	//{
	//	int numValue = rand() % 15;
	//	int symbolValue = rand() % 4 + 1;
	//
	//	switch (symbolValue)
	//	{
	//	case 1: printf("♠"); break;
	//	case 2: printf("◆"); break;
	//	case 3: printf("♥"); break;
	//	case 4: printf("♣"); break;
	//	}
	//	
	//	switch (list[numValue])
	//	{
	//	case 1: printf("A "); break;
	//	case 13: printf("J "); break;
	//	case 14: printf("Q "); break;
	//	case 15: printf("K "); break;
	//	default: printf("%d ", list[numValue]); break;
	//	}
	//}
	//printf("\n\n\n");
	//
	//printf("내 패 :");
	//
	//for (int i = 0; i < 2; i++)
	//{
	//	int numValue = rand() % 15;
	//	int symbolValue = rand() % 4 + 1;
	//	switch (symbolValue)
	//	{
	//	case 1: printf("♠"); break;
	//	case 2: printf("◆"); break;
	//	case 3: printf("♥"); break;
	//	case 4: printf("♣"); break;
	//	}
	//	
	//	switch (list[numValue])
	//	{
	//	case 1: printf("A "); break;
	//	case 13: printf("J "); break;
	//	case 14: printf("Q "); break;
	//	case 15: printf("K "); break;
	//	default: printf("%d ", list[numValue]); break;
	//	}
	//}

#pragma endregion

#pragma region Up & Down Game

	//Title();


#pragma endregion

#pragma region 열거형

	// 열거형 : 서로 관련된 상수들을 이름 붙여 묶는 자료형
	// 객체나 코드끼리의 구분을 쉽게해주어 유지보수가 쉬워지게 해줌

	//WeaponCategory weapon = BOW;
	//
	//for (int i = 0; i < 6; i++)
	//{
	//	switch (weapon)
	//	{
	//	case BOW:printf("무기 종류 : 활\n\n"); break;
	//	case GUN:printf("무기 종류 : 총\n\n"); break;
	//	case KNIFE:printf("무기 종류 : 나이프\n\n"); break;
	//	case SWORD:printf("무기 종류 : 검\n\n"); break;
	//	case HAMMER:printf("무기 종류 : 해머\n\n"); break;
	//	default:
	//		printf("없음\n\n");
	//		break;
	//	}
	//	weapon++;
	//}
#pragma endregion

}