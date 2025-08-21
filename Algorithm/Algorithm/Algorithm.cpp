#include <iostream>
#define INFINITY 1e18
#define SIZE 7
using namespace std;

class Dikstra
{
private:
	long long graph[SIZE][SIZE];
	long long dist[SIZE];
	bool visited[SIZE];
public:
	Dikstra()
	{
		for (int i = 0; i < SIZE; i++)
		{
			dist[i] = 0;
			visited[i] = false;
			for (int j = 0; j < SIZE; j++)
			{
				graph[i][j] = (i == j ? 0 : INFINITY);
			}
		}
	}

	void insert(int x, int y, int w)
	{
		graph[x][y] = w;
		graph[y][x] = w;
	}

	const int find()
	{
		long long distance = INFINITY;
		int minDist = 0;

		for (int i = 1; i < SIZE; i++)
		{
			if (!visited[i] && dist[i] < distance)
			{
				minDist = i;
				distance = dist[i];
			}
		}

		return minDist;
	}

	void update(int start)
	{
		visited[start] = true;
		for (int i = 1; i < SIZE; i++)
		{
			if (i == start)
			{
				dist[i] = 0;
			}
			else
			{
				dist[i] = graph[start][i];
			}
		}
	}

	void search(int start)
	{
		update(start);

		for (int i = 1; i < SIZE; i++)
		{
			int x = find();
			visited[x] = true;
			for (int j = 1; j < SIZE; j++)
			{
				if (!visited[j] && dist[x] + graph[x][j] < dist[j])
				{
					dist[j] = dist[x] + graph[x][j];
				}
			}
		}
	}

	void printDist() {
		for (int i = 1; i < SIZE; i++) {
			cout << "1번에서 " << i << "번까지 거리: ";
			if (dist[i] == INFINITY)
				cout << "INF" << endl;
			else
				cout << dist[i] << endl;
		}
	}
};

int main()
{
#pragma region 다익스트라 알고리즘

	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘

	// 1. 거리 배열에서 weight[시작 노드]의 값들로 초기화 합니다.
	
	// 2. 시작점을 방문 처리
	
	// 3. 거리 배열에서 최소 비용 노드를 찾고 방문 처리
	//	  단, 이미 방문한 노드는 제외
	
	// 4. 최소 비용 노드를 거쳐갈 지 고민해서 거리 배열을 갱신
	//	  단, 이미 방문한 노드는 제외
	
	// 5. 모든 노드를 방문할 때까지 3번 ~ 4번 반복

	// 방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를
	// 방문하고, 그 노드와 연결된 다른 노드까지의 거리를 계산

	Dikstra dik;

	dik.insert(1, 2, 2);
	dik.insert(1, 3, 5);
	dik.insert(1, 4, 1);
	dik.insert(2, 3, 3);
	dik.insert(2, 4, 2);
	dik.insert(3, 4, 3);
	dik.insert(3, 5, 1);
	dik.insert(3, 6, 5);
	dik.insert(4, 5, 1);
	dik.insert(5, 6, 2);

	dik.search(1);

	dik.printDist();
#pragma endregion

	return 0;
}