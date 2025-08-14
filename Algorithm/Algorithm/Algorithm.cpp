#include <iostream>
#include <random>
#include <vector>
#include <queue>
#define SIZE 8

using namespace std;

class Graph
{
private:
	vector<int> list[SIZE];
	int indegree[SIZE];

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			indegree[i] = 0;
		}
	}

	void insert(int vertex, int edge)
	{
		list[vertex].push_back(edge);
		indegree[edge]++;
	}

	void search()
	{
		queue<int> q;

		for (int i = 0; i < SIZE; i++)
		{
			if (indegree[i] == 0 && !list[i].empty())
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int current = q.front();

			q.pop();

			cout << current << " ";

			for (int next : list[current])
			{
				indegree[next]--;
				if (indegree[next] == 0)
				{
					q.push(next);
				}
			}
		}
	}

};

int main()
{
#pragma region 위상 정렬

	// 병합 그래프에 존재하는 각 정점들의 선행 순서를 지키며,
	// 모든 정점을 차례대로 진행하는 알고리즘
	
	// 사이클이 발생하는 경우 위상 정렬을 수행할 수 없다.
	
	// DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프

	// 시간 복잡도 : 0(V + E)

	// 1. 진입 차수가 0인 정점을 Queue에 삽입
	
	// 2. Queue에서 원소를 꺼내 연결된 모든


	Graph graph;

	graph.insert(1, 2);
	graph.insert(1, 5);

	graph.insert(2, 3);
	graph.insert(3, 4);
	graph.insert(4, 6);

	graph.insert(5, 6);
	graph.insert(6, 7);

	graph.search();

#pragma endregion


	return 0;
}