#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 5

using namespace std;

template<typename T>
class Stack
{
private:
    int count;
    int highSet;
    T array[SIZE];

public:
    Stack()
    {
        count = 0;
        highSet = -1;
        for (int i = 0; i < SIZE; i++)
        {
            array[i] = 0;
        }
    }

    int size()
    {
        return count;
    }

    const T& top()
    {
        return array[highSet];
    }

    void push(T data)
    {
        ++highSet;

        if (highSet >= SIZE)
        {
            cerr << "Warning : Stack OverFlow" << endl;
            return;
        }

        array[highSet] = data;
        count++;
    }

    void pop()
    {
        if (highSet == -1)
        {
            return;
        }

        --highSet;
        --count;
    }

    bool empty()
    {
        return count == 0;
    }

    T operator[](int index)
    {
        if (index > highSet)
        {
            cerr << "Warning : Undefind Behavior" << endl;
            return NULL;
        }

        return array[index];
    }
};

int main()
{
    Stack<int> stack;

    stack.push(50);
    stack.push(60);
    stack.push(20);
    stack.push(30);
    stack.push(80);

    while (stack.empty() == false)
    {
        cout << stack.top() << endl;

        stack.pop();
    }


    return 0;
}
