#include <iostream>
#include <random>
#include <vector>
#include <queue>
#define SIZE 8

using namespace std;

//class Graph
//{
//private:
//	vector<int> list[SIZE];
//	int indegree[SIZE];
//
//public:
//	Graph()
//	{
//		for (int i = 0; i < SIZE; i++)
//		{
//			indegree[i] = 0;
//		}
//	}
//
//	void insert(int vertex, int edge)
//	{
//		list[vertex].push_back(edge);
//		indegree[edge]++;
//	}
//
//	void search()
//	{
//		queue<int> q;
//
//		for (int i = 0; i < SIZE; i++)
//		{
//			if (indegree[i] == 0 && !list[i].empty())
//			{
//				q.push(i);
//			}
//		}
//
//		while (!q.empty())
//		{
//			int current = q.front();
//
//			q.pop();
//
//			cout << current << " ";
//
//			for (int next : list[current])
//			{
//				indegree[next]--;
//				if (indegree[next] == 0)
//				{
//					q.push(next);
//				}
//			}
//		}
//	}
//
//};

bool Solution(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited)
{
	if (x == maze[0].size() - 1 && y == maze.size() - 1)
		return true;

	bool result = false;

	visited[y][x] = true;

	if (x + 1 <= maze[0].size()-1 && !visited[y][x + 1] && maze[y][x + 1] > 0)
	{
		result |= Solution(x + 1, y, maze, visited);
	}
	if (y + 1 <= maze.size() - 1 && !visited[y + 1][x] && maze[y + 1][x] > 0)
	{
		result |= Solution(x, y + 1, maze, visited);
	}
	if (x - 1 >= 0 && !visited[y][x - 1] && maze[y][x - 1] > 0)
	{
		result |= Solution(x - 1, y, maze, visited);
	}
	if (y - 1 >= 0 && !visited[y - 1][x] && maze[y - 1][x] > 0)
	{
		result |= Solution(x, y - 1, maze, visited);
	}

	return result;
}

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


	//Graph graph;
	//
	//graph.insert(1, 2);
	//graph.insert(1, 5);
	//
	//graph.insert(2, 3);
	//graph.insert(3, 4);
	//graph.insert(4, 6);
	//
	//graph.insert(5, 6);
	//graph.insert(6, 7);
	//
	//graph.search();

#pragma endregion

	int width=0;
	int height=0;

	cin >> width;
	cin >> height;

	int destx = width - 1;
	int desty = height - 1;

	vector<vector<int>> maze(height);
	vector<vector<bool>> visited(height);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int input = 0;

			cin >> input;
			maze[i].push_back(input);
			visited[i].push_back(false);
		}
	}

	if (Solution(0, 0, maze,visited))
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}