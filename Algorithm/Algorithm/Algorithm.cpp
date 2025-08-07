#include <iostream>
#include <random>

using namespace std;

int find(int array[], int left, int right, int target)
{
	if (left > right)
		return -1;

	int mid = (left + right) / 2;

	if (array[mid] == target)
	{
		return mid;
	}
	else if (array[mid] < target)
	{
		return find(array, mid + 1, right, target);
	}
	else
		return find(array, left, mid - 1, target);
}

int main()
{
#pragma region 이분 탐색

	// 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
	// 좁혀나가는 방식으로 동작하는 알고리즘

	int list[] = { 1, 5, 13, 22, 58 };

	cout << list[find(list, 0, (sizeof(list) / sizeof(int)), 22)];

#pragma endregion


	return 0;
}