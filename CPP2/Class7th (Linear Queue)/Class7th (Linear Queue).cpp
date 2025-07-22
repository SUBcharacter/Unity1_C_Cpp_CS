#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 5

using namespace std;

template<typename T>
class Queue
{
private:
    int _front;
    int rear;
    T _data[SIZE];

public:
    Queue()
    {
        _front = 0;
        rear = -1;
        for (int i = 0; i < SIZE; i++)
        {
            _data[i] = NULL;
        }
    }

    int size()
    {
        return rear - front + 1;
    }

    const T& front()
    {
        if (isEmpty())
        {
            exit(1);
        }
        else
        {
            return _data[_front];
        }

    }

    bool isEmpty()
    {
        return _front > rear;
    }

    bool isFull()
    {
        return rear == SIZE - 1;
    }

    void push(T data)
    {
        if (isFull())
        {
            cout << "Warning : Queue Overflow" << endl;
            return;
        }

        _data[++rear] = data;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        ++_front;
    }
};


int main()
{
    Queue<int> que;

    que.push(30);
    que.push(10);
    que.push(50);
    que.push(80);
    que.push(40);

    while (que.isEmpty() == false)
    {
        cout << que.front() << endl;

        que.pop();
    }

    return 0;
}
