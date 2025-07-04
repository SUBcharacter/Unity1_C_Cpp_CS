#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;



int main()
{
#pragma region 연관 컨테이너

#pragma region unordered set

	unordered_set<const char*> inven;

	inven.max_load_factor(2.0f);

	inven.insert("AK-47");
	inven.insert("HK416");
	inven.insert("ppsh-41");
	inven.insert("Moshin Naghant");
	inven.insert("L85A1");
	inven.insert("MP5SD");
	inven.insert("MP7");
	inven.insert("AS Val");
	inven.insert("M4A1");
	inven.insert("SCAR-L");
	inven.insert("MCX");

	for (const auto& gun : inven)
	{
		cout << gun << endl;
		cout << "bucket count : " << inven.bucket_count() << endl;
		cout << "load factor : " << inven.load_factor() << endl << endl;
	}

	const char* find = "SCAR-L";

	if (inven.find(find) != inven.end())
	{
		cout << "Founded gun " << find << endl;
	}
	else
		cout << "Can't found gun " << find << endl;

#pragma endregion

#pragma region set

	// 

#pragma endregion


#pragma endregion

#pragma region 과제 (재고 탐사, 이중 해싱)

#pragma endregion



	return 0;
}


