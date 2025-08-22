#include "Integration.h"
#include "Play.h"


int main()
{
#pragma region 시뮬레이션 알고리즘

	// 문제에 주어진 규칙이나 상황을 그대로 모방하여 결과를 도출하는 알고리즘
	// 수학적 공식이나 최적화된 해법을 찾기보다는 실제 문제 상황을 모델링하여 그대로 실행하여 해법 도출

	// 1. 상태
	// 현재 상황을 표현하는 변수들의 집합 ex) 좌표, 방향, 시간, 체력, 점수 등

	// 2. 규칙
	// 문제에서 주어진 조건이나 동작 방식

	// 3. 사건
	// 특정 시점에 발생하는 변화 ex) 충돌, 시간초과, 종료 조건 만족

	// 4. 종료 조건
	// 시뮬레이션을 끝내는 조건 ex) 미로찾기(목적지 도달), 게임(게임 종료 버튼)


	// 절차

	// 1. 초기 상태 정의 - 시뮬레이션을 위한 초기 상태 설정

	// 2. 반복 구조 - 문제에서 제시된 규칙을 기반으로 지속 업데이트

	// 3. 상태 변화 기록 - 변화된 상태를 기록 및 출력

	// 4. 종료 조건 검사 - 종료 조건을 만족하면 시뮬레이션 종료

	// <예제 - 카드뽑기 : 귀족을 피해라>

	Player me;
	Player your_friend;

	Play play(me, your_friend);

	while (true)
	{
		system("cls");
		cout << "1. 게임시작" << endl << endl;
		cout << "2. 게임종료" << endl << endl;

		int input = 0;

		cin >> input;

		if (input == 1)
		{
			play.start();
		}
		else if (input == 2)
		{
			return 1;
		}
		else
		{
			cout << "잘못된 입력입니다. 다시 시도하십시오." << endl;
			_getch();
		}
	}
#pragma endregion

}