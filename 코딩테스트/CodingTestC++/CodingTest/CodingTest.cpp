#include <iostream>
#include <Windows.h>

using namespace std;

class Component
{
public:
    Component() {}

    virtual void Update() = 0;
    virtual void Move() = 0;
    virtual void Jump() = 0;

    ~Component() {}
};

class InputComponent : public Component
{
public:
    InputComponent() {}

    void Move() override
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            cout << "왼쪽" << endl;
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            cout << "오른쪽" << endl;
        }
    }

    void Jump() override
    {
        if (GetAsyncKeyState(VK_SPACE))
        {
            cout << "점프" << endl;
        }
    }

    void Update() override
    {
        Move();
        Jump();
    }
    
    ~InputComponent() {}
};

int main()
{
    Component* input = new InputComponent();

    while (true)
    {
        input->Update();
        Sleep(500);
    }

    delete input;
}
