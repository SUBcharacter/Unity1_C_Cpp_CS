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

    void erase(KEY key)
    {
        int hashIndex = hash_function(key);

        Node* current = buc[hashIndex].head;
        Node* previous = nullptr;

        if (current == nullptr)
        {
            return;
        }
        else
        {
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    if (previous == nullptr)
                    {
                        buc[hashIndex].head = current->next;

                    }
                    else
                    {
                        previous->next = current->next;
                    }

                    delete current;
                    buc[hashIndex].count--;
                    return;
                }

                previous = current;
                current = current->next;
            }
            cout << "not key found" << endl;
        }


    }

    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* current = buc[i].head;

            if (buc[i].head == nullptr)
            {
                continue;
            }
            else
            {
                while (current->next != nullptr)
                {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }

            buc[i].head = nullptr;
            buc[i].count = 0;
        }
    }
};

int main()
{
    HashTable<const char*, int> ht;

    ht.insert("MovingPlatform", 40);
    ht.insert("JumpPlatform", 40);
    ht.insert("StaticPlatform", 40);

    ht.erase("StaticPlatform");

    return 0;
}
