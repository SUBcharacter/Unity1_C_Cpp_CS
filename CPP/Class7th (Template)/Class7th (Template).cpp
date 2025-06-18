#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

template<typename T>
bool Same(T left, T right)
{
	return left == right;
}

template<>
bool Same<const char*>(const char* left, const char* right)
{
	return strlen(left) == strlen(right);
}
#define SIZE 5
template<typename T>
class Container
{
private:
	int index;
	T operater[SIZE];
public:
	Container()
	{
		index = 0;
		for (int i = 0; i < SIZE; i++)
		{
			operater[i] = NULL;
		}
		cout << "초기화 완료" << endl << endl;
	}

	void Add(T a)
	{
		if (index < SIZE)
		{
			operater[index++] = a;
		}
		else
		{
			cout << "배열 가득참!" << endl << endl;
		}


	}

	void Print()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "operater[" << i << "] : " << operater[i] << endl;
		}
	}

	const T& operater[](int count)
	{
		return operater[count];
	}
};

int main()
{
#pragma region 템플릿

	// 데이터 형식에 의존하지 않고, 하나의 값이 
	// 여러 다른 데이터 형식을 가질 수 있는 기술에 중점을 두어
	// 재사용성을 높일 수 있는 기능

	//Same<char>('A', 'B') ? cout << "true\n" : cout << "False\n";
	//Same<int>(5, 5) ? cout << "true\n" : cout << "False\n";
	//Same<char>(14.5f, 7.5f) ? cout << "true\n" : cout << "False\n";


#pragma endregion

#pragma region 템플릿 특수화

	// 특정 자료형에 대해 다르게 처리하고 싶은 경우
	// 특정한 자료형만 다른 형식으로 동작시키는 기능

	//Same("CSS", "PUS") ? cout << "True" : cout << "False";

#pragma endregion

#pragma region 클래스 템플릿

	Container<int> con;

	con.Add(10);
	con.Add(20);
	con.Add(30);
	con.Add(40);
	con.Add(50);

	con.Print();


#pragma endregion


	return 0;
}


