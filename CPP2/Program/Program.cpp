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
    size_t _size;
    size_t _capacity;

public:

    Vector()
    {
        _size = 0;
        _capacity = 0;
        _data = nullptr;
    }

    void resize(size_t newSize)
    {
        if (_size > newSize)
        {
            _size = newSize;
            return;
        }

        if (newSize > _capacity)
        {
            T* newData = new T[newSize];

            for (size_t i = 0; i < _size; i++)
            {
                newData[i] = NULL;
                newData[i] = _data[i];
            }
            for (size_t i = _size; i < newSize; i++)
            {
                newData[i] = T();
            }

            delete[] _data;
            _data = newData;
            _capacity = newSize;
        }
        else
        {
            for (size_t i = _size; i < newSize; i++)
            {
                _data[i] = T();
            }
        }
        
        _size = newSize;
    }

    void push_back(T data)
    {
        if (_capacity == 0)
        {
            _capacity++;
            _data = new T[_capacity];
        }
        else if (_size >= _capacity)
        {
            resize(_capacity * 2);
        }
        _data[_size] = data;
        _size++;
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
    

    return 0;
}
