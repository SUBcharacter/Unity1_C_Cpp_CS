#include <iostream>
#include <random>

using namespace std;

int function(int x, int y)
{
	// 1. 두 개의 자연수 x, y가 있을 때 x와 y를 나눈 나머지를 r이라고 한다.
}

int main()
{
#pragma region 유클리드 호제법

	// 2개의 자연수 또는 정식의 최대 공약수를 구하는 방식으로
	// 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘

	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<> dist(0, 100);

	int a = 100245;
	int b = 20004;
	int r;

	while (b != 0)
	{
		r = a % b;

		a = b;
		b = r;
	}

	cout << a << endl;


#pragma endregion


	return 0;
}