#include <iostream>
using namespace std;

class GameObject
{
#pragma region 접근 지정자

	// 클래스 내부에 포함되어 있는 속성에 접근 범위를 제한하는 지정자

	// public : 클래스 내부와 자기가 상속하고 있는 클래스 그리고 클래스 외부에서도 접근을 허용하는 지정자
	// protected : 클래스 내부와 자기가 상속하고 있는 클래스까지만 접근을 허용하는 지정자
	// private : 클래스 내부까지만 접근을 허용하는 지정자

#pragma endregion
private:
	string name;
	int x = 0;
	int y = 0;
	int z = 0;

protected:
	static int count;
public:
	void SetName(string stream)
	{
		name = stream;
	}

	void SetX(int value)
	{
		if (value >= 100)
		{
			cout << name << " X Exeception" << endl;
			return;
		}
		x = value;
	}
	const int& GetX()
	{
		return x;
	}

	void SetY(int value)
	{
		if (value >= 100)
		{
			cout << name << " Y Exeception" << endl;
			return;
		}
		y = value;
	}
	const int& GetY()
	{
		return y;
	}

	void SetZ(int value)
	{
		if (value >= 100)
		{
			cout << name << " Z Exeception" << endl;
			return;
		}
		z = value;
	}
	const int& GetZ()
	{
		return z;
	}
	void ShowCoord()
	{
		cout << name << "  x : " << GetX();
		cout << ", y : " << GetY();
		cout << ", z : " << GetZ() << endl << endl;
	}

	static void Increase()
	{
		count += 1;
	}
	static void ShowCount()
	{
		cout << "count : " << count << endl;
	}
};

int GameObject::count = 1;

int main()
{
#pragma region 참조자

	// 하나의 변수에 도 다른 이름을 지정하는 지정자

	//int x = 10;
	//
	//int& xValue = x;
	//
	//cout << "x의 값 : " << x << endl;
	//cout << "xValue의 값 : "<< xValue << endl;
	//
	//cout << "x의 주소 : " << &x << endl;
	//cout << "xValue의 주소 : "<< &xValue << endl;

#pragma endregion

#pragma region 클래스

	// 사용자 저의 자료형으로 속성과 함수가 포함되어 있으며,
	// 클래스를 통해 객체를 생성하여 접근하고 사용하는 집합체
	// 클래스의 경우 클래스 내부에 있는 변수는 클래스의 메모리 영역에 포함되지만,
	// 정적변수와 함수의 메모리는 클래스 영역에 포함되지 않는다


	GameObject gameObject1;
	GameObject gameObject2;
	GameObject gameObject3;

	//gameObject1.z = 10;
	//gameObject2.z = 30;
	//gameObject3.z = 15;
	//
	//cout << "gameObject1.z : " << gameObject1.z << endl;
	//cout << "gameObject2.z : " << gameObject2.z << endl;
	//cout << "gameObject3.z : " << gameObject3.z << endl;

	// 객체 지향 프로그래밍
	// 1. 추상화
	// 2. 캡슐화
	// 3. 상속
	// 4. 다형성
	//gameObject1.SetName("GameObject 1");
	//gameObject2.SetName("GameObject 2");
	//gameObject3.SetName("GameObject 3");
	//
	//gameObject1.SetX(5);
	//gameObject1.SetY(5);
	//gameObject1.SetZ(5);
	//
	//gameObject2.SetX(10);
	//gameObject2.SetY(10);
	//gameObject2.SetZ(10);
	//
	//gameObject3.SetX(300);
	//gameObject3.SetY(300);
	//gameObject3.SetZ(300);
	//
	//gameObject1.ShowCoord();
	//gameObject2.ShowCoord();
	//gameObject3.ShowCoord();
	//
	//cout << "GameObject's size : " << sizeof(GameObject) << "Byte";
#pragma endregion

#pragma region 과제 정적멤버 함수

	// 정적 멤버 함수 : 클래스에 속하지만 객체에는 속하지 않는 함수
	// 클래스 이름을 통해 호출할 수 있음
	// 클래스 전체에 관련된 동작을 수행 할때 사용

	// 전체 객체의 공통값을 처리할 때
	// 클래스 자체의 유틸리티 함수를 처리할 때
	// 특정 동작을 객체 없이 호출할때 사용
	//GameObject::Increase();
	//GameObject::Increase();
	//GameObject::Increase();
	//GameObject::ShowCount();

#pragma endregion



	return 0;
}


