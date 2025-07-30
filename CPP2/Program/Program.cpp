#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 10

using namespace std;

template<typename T>
class Set
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;

        Node(T d) : data(d), left(nullptr), right(nullptr) {}
    };

    int size;
    Node* root;

    Node* insert(Node* node, T data)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->left, data);
        }

        return node;
    }

public:
    Set()
    {
        size = 0;
        root = nullptr;
    }

    void insert(T data)
    {
        root = insert(root, data);
    }

    void destroy(Node* node)
    {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    ~Set()
    {
        destroy(root);
    }

};

int main()
{
    Set<int> set;

    set.insert(30);
    set.insert(50);
    set.insert(90);
    set.insert(100);

    return 0;
}
