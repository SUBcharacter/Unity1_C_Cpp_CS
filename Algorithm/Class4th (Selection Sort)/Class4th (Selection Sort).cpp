#include <iostream>
#include <random>

using namespace std;

int main()
{
#pragma region 선택 정렬

	// 주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서
	// 결과를 교체하는 방식으로 정렬하는 알고리즘

	int list[15] = { 1, 4, 8, 3, 6, 5, 2, 7, 9, 10,7,20,30,-5,90 };

	int size = sizeof(list) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < size - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (list[j] < list[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			int temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}

#pragma endregion


	return 0;
}