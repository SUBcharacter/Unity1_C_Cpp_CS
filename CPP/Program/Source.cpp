#include <iostream>
using namespace std;

namespace Module
{
	float time = 5.12412f;

	void Function()
	{
		cout << "Module Function" << endl;
	}
}

namespace Library
{
	const char* manual = "";
	void Function()
	{
		cout << "Library Function" << endl;
	}
}

using namespace Library;
using namespace Module;

int data = 20;

int main()
{
#pragma region 스트림
	
	// 시간의 흐름에 따라 연속적으로 발생하는 데이터의 흐름
	// 스트림은 운영체제의 의해 생성되며,
	// 스트림 자체에 버퍼라는 임시 메모리 공간이 존재

	int series = 5;

	//cout << series << " Stream" << endl;
	//cout << "Program 프로그램" << endl;
	//int count = 0;
	//cin >> count;
	//for (int i = 1; i <= count; i++)
	//{
	//	
	//	cout << "PlayStation " << i << endl << endl;
	//}
#pragma endregion

#pragma region 범위 지정 연산자
	
	// 여러 범위에서 사용되는 식별자를 구분하는데 사용되는 연산자
	// 범위 지정 연산자는 전역 변수와 같은 이름의 지역 변수가 선언되었을때
	// 가장 가까운 범위에 선언된 변수의 이름을 사용하는 범위 규칙이 존재해
	// 전역 변수가 호출되지 않음

	//int data = 10;
	//
	//cout << "Data 지역 : " << data << endl;
	//cout << "Data 전역 : " << ::data << endl;
#pragma endregion

#pragma region 이름 공간

	// 속성을 구분할 수 있도록 유효 범위를 설정하는 영역
	//Module::Function();
	//Library::Function();
	//manual = "매뉴얼";
	//cout << manual << endl;
	//cout << Module::time << endl;
#pragma endregion

#pragma region 동적 할당

	//int* pointer = new int;
	//*pointer = 100;
	//
	//cout << "pointer : " << *pointer << endl;
	//cout << "pointer : " << pointer << endl;
	//
	//delete pointer;
	//pointer = nullptr;

#pragma region 동적 배열

	//pointer = new int[5];
	//
	//for (int i = 0; i < 5; i++)
	//{
	//	pointer[i] = (i + 1) * 10;
	//	cout << "pointer[" << i << "] : " << pointer[i] << endl;
	//}
	//
	//delete[] pointer;
	//pointer = nullptr;

#pragma endregion


#pragma endregion

#pragma region 시퀀스 포인트

	// 시퀀스 포인트 : 다음 코드로 넘어가기전, 이전 코드의 행동들이 메모리에 완전히 반영되는 시점
	// 종류 : ';', ',', '&&,||', '?:', 함수의 리턴

	int a = 1;

	a = a + 3 - 5 + 10; // <- 세미 콜론을 기준으로 코드가 종료(시퀀스 포인트)

	cout << "a의 값 : " << a << endl;
	a = 1;
	a = a++ + 3 - 5 + 10; // 시퀀스 포인트 전에 값이 두번 바뀜(정의되지 않은 행동)
	// a++를 언제 저장하는지 명확하지 않아 어떤 값이 저장 될지 예상 불가

	cout << "a의 값 : " << a << endl;
	
	// 실행은 되지만 코드가 복잡해질수록 오류가 나기 쉽고, 가독성에 문제가 생김

#pragma endregion

}


