#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 6

using namespace std;

template<typename T>
class AdjacencyMatrix
{
private:
    int vertice; // 정점의 개수
    int capacity; // 최대 용량
    T* vertex;
    int** matrix;


public:
    AdjacencyMatrix()
    {
        vertice = 0;
        capacity = 0;
        vertex = nullptr;
        matrix = nullptr;

    }

    void InitResize()
    {
        matrix = new int* [vertice];
        for (int i = 0; i < vertice; i++)
        {
            matrix[i] = new int[vertice];
            for (int j = 0; j < vertice; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void resizeMat(int newCap)
    {
        int** newMat = new int* [newCap];
        for (int i = 0; i < newCap; i++)
        {
            newMat[i] = new int[newCap];
            for (int j = 0; j < newCap; j++)
            {
                if (matrix != nullptr && i < vertice && j < vertice)
                {
                    newMat[i][j] = matrix[i][j];
                }
                else
                {
                    newMat[i][j] = 0;
                }
            }
        }

        if (matrix != nullptr)
        {
            for (int i = 0; i < vertice; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        matrix = newMat;
    }

    void resize(int newSize)
    {
        T* newData = new T[newSize];

        int limit = (newSize < vertice) ? newSize : vertice;
        for (int i = 0; i < limit; i++)
        {
            newData[i] = vertex[i];
        }

        delete[] vertex;
        vertex = newData;
        capacity = newSize;


    }



    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(2);
            resizeMat(2);
        }
        else if (vertice >= capacity)
        {
            int newCap = capacity * 2;
            resize(newCap);
            resizeMat(newCap);
        }

        vertex[vertice++] = data;

    }

    void edge(int i, int j)
    {
        if (vertice == 0 || vertex == nullptr)
        {
            cout << "Warning : No Exist Vertice" << endl;
            return;
        }
        if (i >= vertice || j >= vertice)
        {
            cout << "Warning : Out of Range Vertice" << endl;
            return;
        }

        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    void print()
    {
        for (int i = 0; i < vertice; i++)
        {
            for (int j = 0; j < vertice; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    friend ostream& operator<<(ostream& ostream, const AdjacencyMatrix<T>& admat)
    {
        for (int i = 0; i < admat.vertice; i++)
        {
            for (int j = 0; j < admat.vertice; j++)
            {
                ostream << admat.matrix[i][j] << " ";
            }
            ostream << endl;
        }

        return ostream;
    }

    ~AdjacencyMatrix()
    {
        if (matrix != nullptr)
        {
            for (int i = 0; i < capacity; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
        delete[] vertex;
    }

};

int main()
{
    AdjacencyMatrix<int> adj;

    adj.push(5);
    adj.push(7);
    adj.push(12);

    adj.edge(0, 1);
    adj.edge(0, 2);


    cout << adj;
    return 0;
}
