#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 10

using namespace std;

template<typename T>
class AdjacencyList
{
private:
    struct Node
    {
        int index;
        Node* next;

        Node(int i, Node* n = nullptr)
        {
            this->index = i;
            next = n;
        }
    };

    int vertice; // 정점의 개수
    T vertex[SIZE]; // 정점의 집합
    Node* list[SIZE]; // 인접 리스트

public:
    AdjacencyList()
    {
        vertice = 0;
        for (int i = 0; i < SIZE; i++)
        {
            list[i] = NULL;
            vertex[i] = T();
        }
    }

    void push(T data)
    {
        if (vertice >= SIZE)
        {
            cout << "Warning : contact out of range" << endl;
            return;
        }
        vertex[vertice] = data;
        list[vertice] = nullptr;
        vertice++;
    }

    void edge(int i, int j)
    {
        if (vertice <= 0)
        {
            cout << "adjacency list is empty" << endl;
        }
        else if (i >= vertice || j >= vertice)
        {
            cout << "Warning : Invalied vertex index" << endl;
            return;
        }
        else
        {
            list[i] = new Node(j, list[i]);
            list[j] = new Node(i, list[j]);
        }
    }

    friend ostream& operator<< <>(ostream& ostream, const AdjacencyList<T>& adl)
    {
        for (int i = 0; i < adl.vertice; i++)
        {
            Node* current = adl.list[i];
            ostream << adl.vertex[i] << " : ";
            while (current != nullptr)
            {
                ostream << adl.vertex[current->index] << " ";

                current = current->next;
            }
            ostream << endl;
        }

        return ostream;
    }

    ~AdjacencyList()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* current = list[i];
            while (current != nullptr)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            list[i] = nullptr;
        }
    }
};

int main()
{
    AdjacencyList<int> adl;

    adl.push(5);
    adl.push(7);
    adl.push(12);

    adl.edge(0, 2);
    adl.edge(0, 1);

    cout << adl;

    return 0;
}
