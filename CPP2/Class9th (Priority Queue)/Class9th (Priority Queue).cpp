#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 6

using namespace std;

template<typename T>
class PriorityQueue
{
    int index;
    int capacity;

    T* container;

public:
    PriorityQueue()
    {
        index = 0;
        capacity = 0;
        container = nullptr;
    }

    void resize(int newSize)
    {
        T* newContainer = new T[newSize];

        for (int i = 0; i < index && i < newSize; i++)
        {
            newContainer[i] = container[i];
        }

        delete[] container;

        container = newContainer;
        capacity = newSize;

        if (index > newSize)
        {
            index = newSize;
        }
    }

    const T& top()
    {
        if (index == 0)
        {
            throw out_of_range("Queue is empty");
        }

        return container[0];
    }

    void push(T data)
    {
        if (index == capacity)
        {
            int newCap = capacity == 0 ? 1 : capacity * 2;
            resize(newCap);
        }

        int i = index;

        container[i] = data;

        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (container[parent] < container[i])
            {
                swap(container[parent], container[i]);
                i = parent;
            }
            else
            {
                break;
            }
        }
        index++;
    }

    void pop()
    {
        if (index == 0)
            return;

        container[0] = container[index - 1];
        index--;

        int i = 0;

        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < index && container[left] > container[largest])
            {
                largest = left;
            }

            if (right < index && container[right] > container[largest])
            {
                largest = right;
            }

            if (largest != i)
            {
                swap(container[largest], container[i])
                {
                    i = largest;
                }
            }
            else
            {
                break;
            }

        }
    }

    ~PriorityQueue()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }
};

int main()
{


    return 0;
}
