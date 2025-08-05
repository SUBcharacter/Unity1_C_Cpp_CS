#include <iostream>
#include <random>

using namespace std;

int main()
{
#pragma region 삽입 정렬

	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬 하는 알고리즘

	int array[10];
	int size = sizeof(array) / sizeof(int);

	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<> dist(0, 9);
	for (int i = 0; i < size; i++)
	{
		array[i] = dist(gen);
	}

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	for (int i = 1; i < size; i++)
	{
		int key = array[i];

		int j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = key;
	}

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

#pragma endregion


	return 0;
}