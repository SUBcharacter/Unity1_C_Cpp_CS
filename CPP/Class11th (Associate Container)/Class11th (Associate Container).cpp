#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;

class SquaHashTable
{
private:
	vector<int> table;
public:
	SquaHashTable()
	{
		table.resize(TABLE_SIZE, EMPTY);
	}

	bool insert(int key)
	{
		int hash = key % TABLE_SIZE;

		for (int i = 0; i < TABLE_SIZE; i++)
		{
			int idx = (hash + i * i) % TABLE_SIZE;

			if (table[idx] == EMPTY)
			{
				table[idx] = key;
				return true;
			}
		}

		cout << "자리 없음" << endl;
		return false;
	}

	void ShowTable()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			cout << "table[" << i << "] : " << table[i] << endl;
		}
	}
};

int main()
{
#pragma region 연관 컨테이너

#pragma region unordered set

	//unordered_set<const char*> inven;
	//
	//inven.max_load_factor(2.0f);
	//
	//inven.insert("AK-47");
	//inven.insert("HK416");
	//inven.insert("ppsh-41");
	//inven.insert("Moshin Naghant");
	//inven.insert("L85A1");
	//inven.insert("MP5SD");
	//inven.insert("MP7");
	//inven.insert("AS Val");
	//inven.insert("M4A1");
	//inven.insert("SCAR-L");
	//inven.insert("MCX");
	//
	//for (const auto& gun : inven)
	//{
	//	cout << gun << endl;
	//	cout << "bucket count : " << inven.bucket_count() << endl;
	//	cout << "load factor : " << inven.load_factor() << endl << endl;
	//}
	//
	//const char* find = "SCAR-L";
	//
	//if (inven.find(find) != inven.end())
	//{
	//	cout << "Founded gun " << find << endl;
	//}
	//else
	//	cout << "Can't found gun " << find << endl;

#pragma endregion

#pragma region map

	//unordered_map<string, int> item;
	//
	//item.insert({ "체력 포션", 500 });
	//item.insert({ "롱 소드", 1000 });
	//item.insert({ "바스타드 소드", 2000 });
	//
	//for (auto& i : item)
	//{
	//	cout << "key : " << i.first << endl;
	//	cout << "value : " << i.second << endl << endl;
	//}
	//
	//cout << "inven size : " << item.size() << endl;
	//cout << "Bucket Count : " << item.bucket_count() << endl;
	//cout << "Load Factor : " << item.load_factor() << endl;
	//
	//item.clear();
	//
	//cout << "Load Factor : " << item.load_factor() << endl;

#pragma endregion

#pragma region set

	set<int> set;
	set.insert(10);
	set.insert(35);
	set.insert(55);
	set.insert(64);

	for (auto s : set)
	{
		cout << s << " " << endl;
	}

#pragma endregion

#pragma endregion

#pragma region 과제 (제곱 탐사, 이중 해싱)

	// 제곱 탐사 : 충돌 발생시 제곱 형식으로 빈 자리를 찾는 방법
	// - 선형 탐사와 달리 +1^2, +2^2 등으로 위치를 이동
	// - 군집화(클러스터링)을 줄일 수 있음
	// - 테이블 크기가 소수(prime)이 아니라면 무한 루프에 빠질 수 있음

	//SquaHashTable table;
	//
	//table.insert(100);
	//table.insert(88);
	//table.insert(90);
	//table.insert(100);
	//
	//table.ShowTable();

	// 이중 해싱 : 

#pragma endregion

	return 0;
}


