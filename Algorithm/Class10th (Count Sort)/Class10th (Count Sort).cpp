#include <iostream>
#include <random>

using namespace std;



int main()
{
#pragma region 계수 정렬

	// 데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개 있는지
	// 개수를 세어 저장한 다음 정렬하는 알고리즘

	int list[8] = { 1, 3, 2, 2, 4, 5, 1, 2 };
	int size = sizeof(list) / sizeof(list[0]);

	vector<int> radix(6 + 1, 0);

	for (int i = 0; i < size; i++)
	{
		radix[list[i]]++;
	}

	for (int i = 0; i < radix.size(); i++)
	{
		cout << radix[i] << " ";
	}
	cout << endl;

	int index = 0;

	for (int i = 0; i < radix.size(); i++)
	{
		for (int j = 0; j < radix[i]; j++)
		{
			list[index++] = i;
		}
	}

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;

#pragma endregion


	return 0;
}