#include <iostream>
#include <random>
#include <vector>
#include <queue>
#define SIZE 7

using namespace std;

class Kruskal
{
private:
	class Edge
	{
	private:
		int x;
		int y;
		int weight;

	public:
		Edge(int x, int y, int weight) : x(x), y(y), weight(weight) {}

		const int GetX() { return x; }

		int GetY() { return y; }

		int GetWeight() { return weight; }

		bool operator<(const Edge& other)
		{
			return this->weight < other.weight;
		}
	};
	int cost = 0;
	vector<Edge> edges;
	vector<int> parent;

public:
	Kruskal() {}

	void InitVertex(int vertex)
	{
		parent.resize(vertex + 1);
		for (int i = 1; i <= vertex; i++)
		{
			parent[i] = i;
		}
	}

	void insert(int vertexX, int vertexY, int weight)
	{
		edges.push_back(Edge(vertexX, vertexY, weight));
	}

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

		if (rootX < rootY)
		{
			parent[rootY] = rootX;
		}
		else if (rootX > rootY)
		{
			parent[rootX] = rootY;
		}
	}

	bool same(int x, int y)
	{
		return find(x) == find(y);
	}

	void calculate()
	{
		InitVertex(7);
		sort(edges.begin(), edges.end());

		vector<Edge> mst;

		cost = 0;

		for (auto& e : edges)
		{
			if (!same(e.GetX(), e.GetY()))
			{
				Union(e.GetX(), e.GetY());
				cost += e.GetWeight();
				mst.push_back(e);
			}
		}

		for (auto& e : mst)
		{
			cout << "(" << e.GetX() << ", " << e.GetY() << ")";
		}

		cout << endl;

		for (int i = 1; i <= 7; i++)
		{
			cout << parent[i] << " ";
		}

		cout << cost;

	}

	void ShowEdge()
	{
		for (auto e : edges)
		{
			cout << e.GetWeight() << " ";
		}
	}
};

int main()
{
#pragma region 최소 신장 트리

	// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는
	// 부분 그래프로, 그래프의 모든 정점을 최소 비용으로 연결하는 트리

	// 그래프의 정점의 수가 n개 일 때, 간선의 수는 n-1개

	Kruskal krus;

	krus.insert(1, 7, 12);
	krus.insert(4, 7, 13);
	krus.insert(1, 4, 30);
	krus.insert(2, 4, 23);
	krus.insert(1, 2, 71);
	krus.insert(1, 5, 15);
	krus.insert(2, 5, 65);
	krus.insert(3, 5, 18);
	krus.insert(5, 6, 44);
	krus.insert(3, 6, 36);

	krus.calculate();



#pragma endregion

	return 0;
}