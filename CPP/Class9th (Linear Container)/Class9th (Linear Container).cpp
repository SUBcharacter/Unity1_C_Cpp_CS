#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
using namespace std;


int main()
{
#pragma region 선형 컨테이너

#pragma region vector container

	//vector<int> vec;
	//
	//vec.reserve(10);
	//
	//cout << vec.capacity() << endl;
	//
	//vec.push_back(10);
	//cout << vec.capacity() << endl;
	//vec.push_back(20);
	//cout << vec.capacity() << endl;
	//vec.push_back(30);
	//cout << vec.capacity() << endl;
	//
	//vec.pop_back();
	//
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	cout << "vec[" << i <<"] : " << vec[i] << endl << endl;
	//}

#pragma endregion

#pragma region list container

	//list<int> list;
	//
	//// [20]
	//list.push_front(20);
	//for (int val : list) 
	//{
	//	cout << val << "  ";
	//}
	//cout << endl;
	//// [20] - [30]
	//list.push_back(30);
	//for (int val : list)
	//{
	//	cout << val << "  ";
	//}
	//cout << endl;
	//// [10] - [20] - [30]
	//list.push_front(10);
	//for (int val : list)
	//{
	//	cout << val << "  ";
	//}
	//cout << endl;
	//// [20] - [30]
	//list.pop_front();
	//for (int val : list)
	//{
	//	cout << val << "  ";
	//}
	//cout << endl;
#pragma endregion

#pragma region string

	//string contents;
	//
	//contents.append("Texas Hold'em");
	//
	//cout << contents << endl;
	//
	//contents = "Indian Poker";
	//
	//cout << contents << endl;

#pragma endregion

#pragma region 컨테이너 어댑터

	//stack<int> stack;
	//
	//for (int i = 0; i < 4; i++)
	//{
	//	stack.push((i + 1) * 10);
	//}
	//
	//while (!stack.empty())
	//{
	//	cout << stack.top() << endl;
	//	stack.pop();
	//}

#pragma region container Queue

//queue<int> q;
//
//q.push(10);
//q.push(20);
//q.push(30);
//q.push(40);
//q.push(50);
//q.push(60);
//
//while (!q.empty())
//{
//	cout << q.front() << "  ";
//	q.pop();
//}

#pragma endregion

#pragma region Deque Container

	//deque<int> container;
	//
	//for (int i = 0; i < 5; i++)
	//{
	//	container.push_back((i + 1) * 10);
	//}
	//
	//container.push_front(5);
	//container.push_front(1);
	//
	//container.push_back(60);
	//container.push_back(75);
	//
	//for (int i = 0; i < container.size(); i++)
	//{
	//	cout << "container[" << i << "] : " << container[i] << endl;
	//}

#pragma endregion

#pragma region Priority Queue Container

	//priority_queue<int> top;
	//top.push(20);
	//top.push(10);
	//top.push(31);
	//top.push(45);
	//top.push(20);
	//
	//while (!top.empty())
	//{
	//	cout << "top's priority value : " << top.top() << endl;
	//
	//	top.pop();
	//}


#pragma endregion
#pragma endregion




#pragma endregion


	return 0;
}


