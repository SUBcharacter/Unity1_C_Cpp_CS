#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class String
{
private:
    char* _data;
    size_t _size;

public:
    String() 
    {
        _data = nullptr;
        _size = 0;
    }
    String(const char* d)
    {
        _size = strlen(d);
        _data = new char[_size + 1];
        strcpy(_data, d);
    }

    size_t size()
    {
        return _size;
    }

    size_t length()
    {
        return _size;
    }



    void operator=(const char* other)
    {
        _size = strlen(other) + 1;
        if (_data = nullptr)
        {
            _data = new char[_size];
            for (int i = 0; i < _size; i++)
            {
                _data[i] = other[i];
            }
        }
        else
        {
            delete[] _data;
            _data = new char[_size];
            for (int i = 0; i < _size; i++)
            {
                _data[i] = other[i];
            }
        }
    }

    friend ostream& operator<<(ostream& os, const String& str)
    {
        os << str._data;
        return os;
    }
};

int main()
{
    String str;
    str = "출력 하고 싶어요";

    cout << str;
    
    return 0;
}
