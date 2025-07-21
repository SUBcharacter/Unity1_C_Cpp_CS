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
        if (_data == nullptr)
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

    void append(const char* word)
    {
        size_t wordSize = strlen(word);
        size_t newSize = _size + wordSize;

        char* newData = new char[newSize + 1];

        if (_data)
        {
            strcpy(newData, _data);
        }
        else
        {
            newData[0] = '\0';
        }

        strcat(newData, word);

        delete[] _data;

        _data = newData;
        _size = newSize;

    }

    unsigned long long find(const char* word)
    {
        if (_data == nullptr || word == nullptr)
        {
            return -1;
        }

        size_t wordSize = strlen(word);

        for (size_t i = 0; i < _size - wordSize; i++)
        {
            bool wordMatch = true;
            for (size_t j = 0; j < wordSize; j++)
            {
                if (_data[i + j] != word[j])
                {
                    wordMatch = false;
                    break;
                }
            }
            if (wordMatch)
            {
                return i;
            }
        }

        return -1;
    }

    friend ostream& operator<<(ostream& os, const String& str)
    {
        os << str._data;
        return os;
    }

    char& operator[](size_t index)
    {
        return _data[index];
    }

    ~String()
    {
        delete[] _data;
    }
};

int main()
{
    String str;
    str = "출력 하고 싶다";

    return 0;
}
