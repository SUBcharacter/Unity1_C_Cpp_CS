#include <iostream>
#include <random>
#include <vector>
#include <queue>
#define SIZE 8

using namespace std;

class Graph
{
private:
	bool visited[SIZE];
	vector<int> list[SIZE];

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	void insert(int i, int j)
	{
		list[i].push_back(j);
		list[j].push_back(i);
	}

	void search(int start)
	{
		queue<int> q;

		visited[start] = true;

		q.push(start);

		while (!q.empty())
		{
			int current = q.front();

			q.pop();

			cout << current << endl;

			for (int next : list[current])
			{
				if (!visited[next])
				{
					visited[next] = true;
					q.push(next);
				}
			}
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색

	// 시작 정점을 방문한 후 시작 정점에 인접한
	// 모든 정점들을 우선적으로 방문하는 탐색

	// 더 이상 방문하지 않은 정점이 없을 떄까지 방문하지 않은
	// 모든 정점들에 대해서 너비 우선 탐색을 적용한다.

	Graph graph;

	graph.insert(1, 2);
	graph.insert(1, 3);
	graph.insert(2, 4);
	graph.insert(2, 5);
	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.search(1);

#pragma endregion


	return 0;
}