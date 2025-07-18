#include <iostream>

using namespace std;

/*
* 필요한 것
* - 벡터의 크기
* - 벡터가 저장할 수 있는 메모리 공간
* - 동적 배열을 하기 위한 포인터 변수
*/

template<typename T>
class Vector
{
private:
    T* _data;
    int _size;
    int _capacity;

public:

    Vector()
    {
        _size = 0;
        _capacity = 0;
        _data = nullptr;
    }

    const int& size()
    {
        return _size;
    }

    void resize(int newSize)
    {
        T* newData = new T[newSize];

        int limit = (newSize < _size) ? newSize : _size;
        for (int i = 0; i < limit; i++)
        {
            newData[i] = _data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = newSize;
    }

    void push_back(T data)
    {
        if (_capacity == 0)
        {
            resize(1);
        }
        else if (_size >= _capacity)
        {
            resize(_capacity * 2);
        }
        _data[_size++] = data;
    }

    void pop_back()
    {
        if (_size > 0)
            _size--;

    }

    T& operator[](int index)
    {
        if (index >= _size)
        {
            throw out_of_range("Index out of range");
        }
        return _data[index];
    }

    ~Vector()
    {
        if (_data != nullptr)
        {
            delete[] _data;
        }
    }

};

int main()
{
    Vector<int> vec;

    vec.push_back(40);
    vec.push_back(30);
    vec.push_back(50);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(90);
    vec.push_back(70);

    vec.pop_back();

    cout << vec[5];

    return 0;
}
