#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* nextNode;

        Node(T d)
        {
            data = d;
            nextNode = nullptr;
        }
    };

    int _size;
    Node* head;

public:

    List()
    {
        _size = 0;
        head = nullptr;
    }

    void push_front(T data)
    {
        Node* newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            newNode->nextNode = head;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->nextNode != head)
            {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
            newNode->nextNode = head;
            head = newNode;
        }
        _size++;
    }

    void push_back(T data)
    {
        Node* newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            newNode->nextNode = head;
        }
        else
        {
            Node* currentNode = head;
            while (currentNode->nextNode != head)
            {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
            newNode->nextNode = head;
        }

        _size++;
    }

    void pop_front()
    {
        if (head == nullptr)
            return;

        Node* deleteNode = head;

        if (_size == 1)
        {
            head = nullptr;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->nextNode != head)
            {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = head->nextNode;
            head = head->nextNode;
        }
        

        delete deleteNode;
        deleteNode = nullptr;
        _size--;

    }

    void pop_back()
    {
        if (head == nullptr)
            return;

        Node* deleteNode = head;

        if (_size == 1)
        {
            head = nullptr;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->nextNode->nextNode != head)
            {
                currentNode = currentNode->nextNode;
            }
            deleteNode = currentNode->nextNode;
            currentNode->nextNode = head;
        }

        delete deleteNode;
        deleteNode = nullptr;

        _size--;
    }
};


int main()
{

    return 0;
}
