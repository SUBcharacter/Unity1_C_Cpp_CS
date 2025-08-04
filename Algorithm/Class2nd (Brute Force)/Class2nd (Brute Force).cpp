#include <iostream>
#include <random>

using namespace std;

int main()
{
#pragma region 완전 탐색

	// 가능한 모든 경우의 수를 탐색하면서 결과를 찾아내는 알고리즘

	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<> dist(0, 9);

	int password[3];

	for (int i = 0; i < 3; i++)
	{
		password[i] = dist(gen);
	}

	for (int x = 0; x <= 9; x++)
	{
		for (int y = 0; y <= 9; y++)
		{
			for (int z = 0; z <= 9; z++)
			{
				cout << "Current Number : " << x << y << z << endl;
				if (password[0] == x && password[1] == y && password[2] == z)
				{
					cout << "Access Complete" << endl;
					return 0;
				}

			}
		}
	}

#pragma endregion


	return 0;
}