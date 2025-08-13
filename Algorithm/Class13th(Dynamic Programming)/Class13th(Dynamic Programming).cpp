#include <iostream>
#include <random>

using namespace std;



long long fibonacci(int n, vector<long long>& fibo)
{
	if (n <= 1) return n;
	if (fibo[n] != -1) return fibo[n];
	return fibo[n] = fibonacci(n - 1, fibo) + fibonacci(n - 2, fibo);
}

int main()
{
#pragma region 동적 계획법

	// 특정 범위까지의 값을 구하기 위해 그것과 다른
	// 범위까지의 값을 이용하여 효율적으로 값을 구하는 알고리즘

	// 겹치는 부분 문제 (Overlapping Subproblems)
	// 동일한 작은 문제들이 반복하여 나타나는 경우

	// 최적 부분 구조 (optimal Substructure)
	// 부분 문제의 최적 결과 값을 사용하여 전체 문제의 최적의
	// 결과를 낼 수 있는 경우

	// 메모이제이션 (Memoization)
	// 프로그램이 동일한 게산을 반복해야 할 때, 이전에 계산한 값을
	// 메모리에 저장함으로써 동일한 계산을 반복 수행하는 작업을
	// 제거하여 프로그램이 실행 속도를 향상시키는 방법

	vector<long long> fibo;

	fibo.assign(10000 + 1, -1);

	cout << fibonacci(90, fibo);

#pragma endregion


	return 0;
}