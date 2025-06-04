#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct 
{
	char grade;
	int health;
	double attack;

	// 구조체의 크기는 구조체를 구성하는 멤버 중에서 크기가
	// 가장 큰 자료형의 배수가 되도록 설정한다
}Card;

typedef struct
{
	double x;
	double y;
}Point;

typedef struct
{
	int data;
	struct Node* nextptr;

}Node;

typedef struct
{
	int HP;
	int MP;
	int DF;
}Player;

int main()
{
#pragma region 구조체

	// 여러 개의 변수를 하나의 집합으로 구조화 한 다음
	// 하나의 객체를 생성하는 것
	// 구조체를 선언하기 전에 구조체는 메모리 공간이 생성되지 않으므로,
	// 구조체 내부에 있는 데이터를 초기화 할 수 없다
	// 구조체의 각 멤버는 구조체 선언에서 나타나는 순서대로 초기화 해야함
	// 순서는 왼쪽에서 오른쪽

	//Card attacker = { 'S', 5, 6 };
	//
	//printf("카드 정보\n\n");
	//printf("카드 등급 : %c\n", attacker.grade);
	//printf("카드 체력 : %d\n", attacker.health);
	//printf("카드 공격력 : %.0lf\n", attacker.attack);


#pragma endregion

#pragma region 바이트 패딩

	// 멤버 변수를 메모리에서 CPU로 읽을 때 한 번에
	// 읽을 수 있도록 컴파일러가 레지스터의 블록에 맞추어 바이트를 패딩해주는 최적화 작업
	// 구조체 크기의 경우 멤버 변수의 순서에 따라 메모리 크기가
	// 다르게 설정될 수 있으며, 구조체 크기를 결정하는 형태는
	// 기본 자료형으로만 구성된다

	//printf("Card 구조체의 크기 : %d", sizeof(Card));

#pragma endregion

#pragma region 두 점 사이의 거리

	//srand((unsigned int)time(NULL)); // 랜덤 시드
	//int count = 0;
	//
	//for (int i = 0; i < 30; i++)
	//{
	//	system("cls");
	//
	//	Point player = { rand() % 10, rand() % 10 }; // 플레이어 랜덤 좌표 생성
	//	Point enemy = { rand() % 10, rand() % 10 }; // 적 랜덤 좌표 생성
	//
	//	// 거리 계산
	//	double distance = sqrt(pow(fabs(player.x - enemy.x), 2) + pow(fabs(player.y - enemy.y), 2));
	//
	//	// 정보 표시
	//	printf("플레이어 좌표 : (%.0lf, %.0lf)\n\n", player.x, player.y);
	//	printf("적 좌표 : (%.0lf, %.0lf)\n\n", enemy.x, enemy.y);
	//	printf("적과의 거리 : %.2lf\n\n", distance);
	//
	//	// 전투 여부 판단
	//	if (distance > 3)
	//	{
	//		printf("전투 불가\n");
	//	}
	//	else
	//	{
	//		count++;
	//		printf("전투 시작\n");
	//	}
	//	_getch();
	//}
	//
	//printf("전투 횟수 : %d\n", count);
#pragma endregion

#pragma region 자기 참조 구조체

	// 자기 자신과 같은 타입의 포인터를 멤버로 포함하고 있는 구조체

	//Node* node1 = malloc(sizeof(Node));
	//node1->data = 30;
	//node1->nextptr = NULL;
	//
	//Node* node2 = malloc(sizeof(Node));
	//node2->data = node1->data * 2;
	//node1->nextptr = node2;
	//node2->nextptr = NULL;
	//
	//Node* node3 = malloc(sizeof(Node));
	//node3->data = node2->data * 2;
	//node2->nextptr = node3;
	//node3->nextptr = NULL;
	//
	//Node* head = node1;
	//
	//while (head!= NULL)
	//{
	//	printf("data : %d\n\n", head->data);
	//	head = head->nextptr;
	//}
	//
	//free(node1);
	//node1 = NULL;
	//free(node2);
	//node2 = NULL;
	//free(node3);
	//node3 = NULL;

	//Node node1 = {10,NULL};
	//Node node2 = {20,NULL};
	//Node node3 = {30,NULL};
	//
	//node1.nextptr = &node2;
	//node2.nextptr = &node3;
	//node3.nextptr = NULL;
	//
	//Node* currentNode = &node1;
	//
	//while (currentNode != NULL)
	//{
	//	printf("Node 값 : %d\n\n", currentNode->data);
	//	currentNode = currentNode->nextptr;
	//}

	//---------------------------------------------------

	// typedef에 대해
	// 기존 자료형에 새 이름을 정의해 주는 키워드
		
	typedef unsigned int UI;

	UI testing;

	printf("typedef UI testing : %d\n\n\n", 255);
	
	// 구조체와 함께 쓰면 구조체의 이름을 struct없이 간단히 쓸 수 있다.
	// Ex.
	// typedef struct
	//{
	//	int HP;
	//	int MP;
	//	int DF;
	//}Player;
	
	Player player = { 100, 50, 30 };
	
	printf("플레이어 스탯\n\n");
	printf("체력 : %d\n\n",player.HP);
	printf("마나 : %d\n\n",player.MP);
	printf("방어력 : %d\n\n",player.DF);

	// 복잡한 선언을 단순화 해서 코드 가독성을 올려주고, 코드 작성에서도 편의성을 가질 수 있다.

#pragma endregion


	return 0;
}