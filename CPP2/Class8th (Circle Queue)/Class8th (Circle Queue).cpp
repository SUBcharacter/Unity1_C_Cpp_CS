#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 6

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
        rear = 0;
        for (int i = 0; i < SIZE; i++)
        {
            _data[i] = T();
        }
    }

    bool full()
    {
        return ((rear + 1 + SIZE) % SIZE) == _front;
    }

    bool empty()
    {
        return _front == rear;
    }

    void push(T data)
    {
        if (full())
        {
            cout << "Warning : Queue Overflow" << endl;
            return;
        }

        _data[rear] = data;

        rear = (rear + 1 + SIZE) % SIZE;
    }

    void pop()
    {
        if (empty())
        {
            return;
        }

        _front = (_front + 1 + SIZE) % SIZE;
    }

    const T& front()
    {
        return _data[_front];
    }

    void size()
    {
        return (rear - _front + SIZE) % SIZE;
    }
};


int main()
{
    Queue<int> que;

    que.push(40);
    que.push(60);
    que.push(20);
    que.push(40);
    que.push(40);

    while (!que.empty())
    {
        cout << que.front() << endl;

        que.pop();
    }

    que.push(50);
    que.push(80);
    que.push(30);
    que.push(70);


    return 0;
}
