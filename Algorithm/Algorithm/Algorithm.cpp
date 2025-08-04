#include <iostream>
#include <random>

using namespace std;

int main()
{
#pragma region 거품 정렬

	int array[7];

	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<> dist(0, 9);

	int length = sizeof(array) / sizeof(int);

	for (int i = 0; i < length; i++)
	{
		array[i] = dist(gen);

		cout << array[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

#pragma endregion

	return 0;
}