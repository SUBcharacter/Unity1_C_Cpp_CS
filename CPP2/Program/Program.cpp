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
};

int main()
{
    

    return 0;
}
