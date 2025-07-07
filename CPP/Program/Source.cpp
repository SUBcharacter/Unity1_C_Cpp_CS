#include <iostream>
#include <vector>

using namespace std;

int main()
{
#pragma region 반복자

	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);
	vec.push_back(70);
	vec.push_back(80);
	vec.push_back(90);
	vec.push_back(100);

	vector<int>::iterator vecIter;

	for (vecIter = vec.begin(); vecIter != vec.end(); vecIter++)
	{

		cout << *vecIter << " " << endl;
	}

	

#pragma endregion


	return 0;
}