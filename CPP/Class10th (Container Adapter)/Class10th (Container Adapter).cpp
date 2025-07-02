#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{

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

#pragma endregion

#pragma region container Queue

queue<int> q;

q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.push(60);

while (!q.empty())
{
	cout << q.front() << "  ";
	q.pop();
}

#pragma endregion


#pragma endregion


return 0;
}