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

    int size()
    {
        return _size;
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

    void remove(T data)
    {
        if (head == nullptr)
            return;

        if (head->data == data)
        {

            if (head->nextNode == head)
            {
                delete head;
                head = nullptr;
                _size--;
                return;
            }

            Node* deleteNode = head;
            Node* currentNode = head;

            while (currentNode->nextNode != head)
            {
                currentNode = currentNode->nextNode;
            }

            currentNode->nextNode = head->nextNode;
            head = head->nextNode;

            delete deleteNode;
            deleteNode = nullptr;
            _size--;
            return;
        }

        Node* currentNode = head;

        while (currentNode->nextNode != head)
        {
            if (currentNode->nextNode->data == data)
            {
                Node* deleteNode = currentNode->nextNode;

                currentNode->nextNode = deleteNode->nextNode;

                delete deleteNode;
                deleteNode = nullptr;
                _size--;
                return;
            }
            else
            {
                currentNode = currentNode->nextNode;
            }
        }
    }

    bool empty()
    {
        return head == nullptr;
    }
};


int main()
{
    List<int> list;

    list.push_back(50);
    list.push_back(60);
    list.push_front(80);
    list.push_front(40);

    cout << "list size : " << list.size() << endl;

    list.remove(50);

    cout << "list size : " << list.size() << endl;


    return 0;
}
