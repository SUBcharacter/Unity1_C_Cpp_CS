#include <iostream>
#include <random>

using namespace std;

void Combine(int list[], int start, int middle, int end)
{
	int count = 0;
	int left = start;
	int right = middle + 1;
	int* container = new int[end - start + 1];

	while (left <= middle && right <= end)
	{
		if (list[left] <= list[right])
		{
			container[count++] = list[left++];
		}
		else
		{
			container[count++] = list[right++];
		}
	}

	while (left <= middle)
	{
		container[count++] = list[left++];
	}
	while (right <= end)
	{
		container[count++] = list[right++];
	}

	for (int i = 0; i < count; i++)
	{
		list[start + i] = container[i];
	}

	delete[] container;
}

void MergeSort(int list[], int start, int end)
{
	if (start >= end)
		return;

	int middle = (start + end) / 2;

	MergeSort(list, start, middle);
	MergeSort(list, middle + 1, end);

	Combine(list, start, middle, end);
}

int main()
{
#pragma region 병합 정렬

	// 하나의 리스트를 두 개의 균일한 크기로 분할하고 분할된
	// 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를
	// 합하여 전체가 정렬된 리스트가 되게 하는 방법

	// 1. 리스트의 길이가 0 또는 1이 되면 이미 정렬 된 것으로 본다.
	// 2. 그렇지 않은 경우
	// 2-1. 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눈다.
	// 2-2. 각 부분 리스트를 재귀적으로 병합 정렬을 이용하여 정렬한다.
	// 2-3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 병합한다.

	int list[8] = { 39,12,54,23,43,21,10,4 };

	for (int i = 0; i < 8; i++)
	{
		cout << list[i] << " ";
	}

	MergeSort(list, 0, 7);

	cout << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << list[i] << " ";
	}

#pragma endregion


	return 0;
}