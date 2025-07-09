#include <iostream>

using namespace std;



template<typename T>
class list
{
private:
    int size;

    struct Node
    {
        T data;
        Node* next;

        Node(const T& d) : data(d) { next = nullptr; }
    };
    Node* head;

public:
    list()
    {
        size = 0;
        head = nullptr;
    }

    int size() const
    {
        return size;
    }

    void push_front(const T& data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void push_back(const T& data)
    {
        Node* newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }

    }

    void pop_back()
    {
        if (head == nullptr)
            return;

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    }

    bool empty()
    {
        return this->size == 0;
    }

    void remove(T data)
    {
        while (head != nullptr && head->data == data)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;

        }

        Node* previousNode = head;

        while (previousNode != nullptr && previousNode->next != nullptr)
        {
            if (previousNode->next->data == data)
            {
                Node* deleteNode = nullptr;

                deleteNode = previousNode->next;
                previousNode->next = deleteNode->next;
                delete deleteNode;
                size--;
            }
            else
            {
                previousNode = previousNode->next;
            }
        }
    }

    ~list()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
};



int main()
{
    list<int> lis;

    lis.push_front(10);
    lis.push_front(5);



    return 0;
}
