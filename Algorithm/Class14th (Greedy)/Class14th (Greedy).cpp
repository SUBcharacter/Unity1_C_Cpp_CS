#include <iostream>
#include <random>

using namespace std;



int main()
{
#pragma region 탐욕법

	// 최적의 해를 구하는 데에 사용되는 근사적인 방법으로 여러 경우 중
	// 하나를 검색해야 할 떄마다 그 순간에 최적이라고 생각되는 것을 선택해
	// 나가는 방식으로 진행하여 최종적인 해답을 구하는 알고리즘

	// 1. 탐욕 선택 속성
	// 각 단계에서 '최적의 선택'을 했을 떄 전체 문제에 대한
	// 최적의 해를 구할 수 있는 경우

	// 2. 최적 부분 구조
	// 전체 문제의 최적의 해가 '부분 문제의 최적의 해로 구성'될 수 있는 경우

	// 탐욕 알고리즘으로 문제를 해결하는 방법

	// 1. 선택 절차 (Selection Procedure)
	// 현재 상태에서의 최적의 해답을 선택한다.

	// 2. 적절성 검사 (Feasibility Check)
	// 선택된 해가 문제의 조건을 만족하는지 검사한다

	// 3. 해답 검사 (Solution Check)
	// 원래의 문제가 해결되었는지 검사하고, 해결되지 않았다면
	// 선택 정차로 돌아가 위의 과정을 반복한다
	int count = 0;
	int exchange = 0;
	int money[] = { 5000,1000,500,100,50,10 };
	cin >> exchange;

	for (int i = 0; i < 6; i++)
	{
		count += exchange / money[i];
		exchange %= money[i];
	}

	cout << count;





#pragma endregion


	return 0;
}