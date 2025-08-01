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

    Node* root;

    Node* insert(Node* node, T data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }

        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }

        return node;
    }

    Node* findMin(Node* node)
    {
        if (node == nullptr)
            return nullptr;

        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node* erase(Node* node, T data)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (data < node->data)
        {
            node = erase(node->left, data);
        }
        else if (data > node->data)
        {
            node = erase(node->right, data);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node* minNode = findMin(node->right);
                node->data = minNode->data;
                node->right = erase(node->right, minNode->data);
            }
        }
        return node;
    }

    void inorder(Node* rt)
    {
        if (root != nullptr)
        {
            inorder(rt->left);
            cout << rt->data << " ";

            inorder(rt->right);
        }
    }

public:
    Set()
    {
        root = nullptr;
    }

    void insert(T data)
    {
        root = insert(root, data);
    }

    void erase(T data)
    {
        root = erase(root, data);
    }

    void destroy(Node* node)
    {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }


    void inorder()
    {
        inorder(root);
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

    set.inorder();

    return 0;
}
