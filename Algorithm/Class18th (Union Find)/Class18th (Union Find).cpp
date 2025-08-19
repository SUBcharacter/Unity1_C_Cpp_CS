#include <iostream>
#include <random>
#include <vector>
#include <queue>
#define SIZE 7

using namespace std;

int parent[SIZE];

int find(int x)
{
	if (parent[x] != x)
	{
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void Union(int x, int y)
{
	int rootX = find(x);
	int rootY = find(y);

	if (rootX > rootY)
	{
		parent[rootX] = rootY;
	}
	else if (rootX < rootY)
	{
		parent[rootY] = rootX;
	}
}

bool Same(int x, int y)
{
	if (find(x) != find(y))
	{
		return false;
	}

	return true;
}

int main()
{
#pragma region 서로소 집합

	// 서로 공통된 원소를 가지고 있지 않은 두 개 이상의 집합

	// union (합집합) : 두 집합을 하나로 합치는 연산

	// find (찾기) : 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산

	// 1. 합집합 연산을 확인하여, 서로 연결된 두 노드를 확인한다.
	//	1) A와 B의 루트 노드를 통해 A'과 B'을 각각 찾는다.
	//	2) A'과 B'의 부모 노드를 설정한다.

	// 2. 모든 합집합 연산을 처리할 때까지 1번 과정을 반복한다.

	for (int i = 0; i < SIZE; i++)
	{
		parent[i] = i;
	}

	for (int p : parent)
	{
		cout << p << " ";
	}

	cout << endl;

	Union(0, 1);
	Union(1, 2);
	Union(3, 0);
	Union(4, 5);

	for (int p : parent)
	{
		cout << p << " ";
	}

	cout << endl << (Same(1, 4) ? "true" : "false");

#pragma endregion

	return 0;
}