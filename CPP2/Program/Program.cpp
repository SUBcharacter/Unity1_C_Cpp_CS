#include <iostream>

using namespace std;

template<typename T>
class List
{
private:

    struct node
    {
        T data;
        node* nextNode;
        node* previousNode;
    };

    int size;
    node* head;
    node* tail;

public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T data)
    {
        node* newNode = new node;
        newNode->data = data;
        newNode->previousNode = nullptr;
        newNode->nextNode = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previousNode = newNode;
            newNode->nextNode = head;
            head = newNode;
        }
        size++;
    }

    void push_back(T data)
    {
        node* newNode = new node;
        newNode->data = data;
        newNode->nextNode = nullptr;
        newNode->previousNode = nullptr;
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->nextNode = newNode;
            newNode->previousNode = tail;
            tail = newNode;
        }

        size++;
        
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
            

        node* deleteNode = head;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = deleteNode->nextNode;
            head->previousNode = nullptr;
        }

        delete deleteNode;
        size--;
    }

    void pop_back()
    {
        if (tail == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        node* deleteNode = tail;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = deleteNode->previousNode;
            tail->nextNode = nullptr;
        }

        delete deleteNode;
        size--;
    }

    bool empty()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return true;
        }
        else
            return false;
    }

    ~List() {
        node* current = head;

        while (current != nullptr)
        {
            node* next = current->nextNode;

            delete current;

            current = next;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

int main()
{
    List<int> list;

    list.push_front(30);
    list.push_front(30);
    list.push_front(30);

    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_front();

    list.empty();

    return 0;
}
