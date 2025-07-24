#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 6

using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE data;
        Node* next;
    };

    struct Bucket
    {
        int count;
        Node* head;
    };

    template<typename T>
    const int& hash_function(T key)
    {
        hash<T> hasher; 
        size_t hash_value = hasher(key);

        return static_cast<int>(hash_value % SIZE);
    }

    Bucket buc[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            buc[i].count = 0;
            buc[i].head = nullptr;
        }
    }

    Node* create_node(KEY key, VALUE value)
    {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->data = value;
        newNode->next = nullptr;

        return newNode;
    }

    void insert(KEY key, VALUE value)
    {
        int hashIndex = hash_function(key);

        Node* newNode = create_node(key, value);

        if (buc[hashIndex].count == 0)
        {
            buc[hashIndex].head = newNode;
        }
        else
        {
            newNode->next = buc[hashIndex].head;
            buc[hashIndex].head = newNode;
        }

        buc[hashIndex].count++;
    }

    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* current = buc[i].head;

            while (current->next != nullptr)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            buc[i].head = nullptr;
            buc[i].count = 0;
        }
    }
};

int main()
{


    return 0;
}
