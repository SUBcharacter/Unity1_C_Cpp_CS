#include <iostream>
#include "../Program/Scooter.h"
#include "../Program/Boat.h"
#include "../Program/Bicycle.h"

using namespace std;

class homework

{
	// 멤버 이니셜라이저 : 생성자에서 매개변수를 이용해 멤버변수를 초기화 하는 방법
private:
	int a;
	int b;
public:
	homework(int a, int b) // 콜론으로 멤버 이니셜라이즈
		: a(a), b(b)
	{

	}
	// 생성자 사용시 원하는 값으로 초기화 가능
	// 초기화시 바로 값이 설정되기 때문에 객체 생성시 기본 초기화와 대입 작업이 없어짐

	void ShowMembers()
	{
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}
};

class Monster
{
protected:
	string name;
	int health;
	int defence;
	int attack;

public:
	Monster(string name, int health, int defence, int attack) : name(name), health(health), defence(defence), attack(attack) {}
	void ShowStats()
	{
		cout << name << " 스테이터스" << endl << endl << endl;
		cout << "체력 : " << health << endl << endl;
		cout << "방어력 : " << defence << endl << endl;
		cout << "공격력 : " << attack << endl << endl << endl;
	}
};

class Goblin : public Monster
{
public:
	Goblin(string name, int health, int defence, int attack) : Monster(name, health, defence, attack) {}
};

class JuniorGolem : public Monster
{
public:
	JuniorGolem(string name, int health, int defence, int attack) : Monster(name, health, defence, attack) {}
};

class Slime : public Monster
{
public:
	Slime(string name, int health, int defence, int attack) : Monster(name, health, defence, attack) {}
	void ShowStats()
	{
		cout << name << " 스테이터스" << endl << endl << endl;
		cout << "체력 : " << health << endl << endl;
		cout << "방어력 : " << defence << endl << endl << endl;
	}
};

int main()
{
#pragma region 과제 : 멤버 이니셜라이저

	//homework meminit(3, 6);
	//meminit.ShowMembers();


#pragma endregion

#pragma region 상속

	// 상위 클래스의 속성을 하위 클래스가 사용할 수 있도록 설정해주는 기능
	// 클래스의 상속 관계에서 상위 클래스는 하위 클래스의 속성을 사용할 수 없으며,
	// 하위 클래스는 상위 클래스의 메모리를 포함한 상태로 메모리의 크기가 결정됩니다.

	//Goblin gob("고블린", 100, 5, 30);
	//JuniorGolem gol("주니어 골렘",200, 10, 55);
	//Slime slime("슬라임",50, 1, 0);
	//
	//gob.ShowStats();
	//gol.ShowStats();
	//slime.ShowStats();
	//
	//cout << "size of Slime : " << sizeof(Slime) << endl;
	//cout << "size of Goblin : " << sizeof(Goblin) << endl;
	//cout << "size of JuniorGolem : " << sizeof(JuniorGolem) << endl;

	Vehicle* s = new Scooter("Scooter", 50, 100);
	Vehicle* B = new Boat("Boat", 100, 250);
	Vehicle* b = new Bicycle("Bicycle", 25);

	s->Move();
	B->Move();
	b->Move();

	delete s;
	delete B;
	delete b;

#pragma endregion


	return 0;
}


