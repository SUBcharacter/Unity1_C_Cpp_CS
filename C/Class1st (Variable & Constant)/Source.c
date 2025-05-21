#include <stdio.h>

//진입점
void main()
{
	// main 함수는 프로그램의 진입점 역할을 하는 함수입니다.
	//printf("I need Monster Energy...");

#pragma region 자료형
	// 데이터를 저장하기 위해 데이터의 형태를 정해주는 것입니다.


	// 자료형은 각각의 자료형 마다 크기가 정해져 있으며, 자료형의 크기는
	// 바이트 단위로 이루어집니다.


	//자료형의 경우 자료형에 따라 저장가능 값의 종류와 범위가 결정됩니다.

#pragma endregion

#pragma region 변수
	// 데이터를 저장할 수 있는 메모리 공간을 
	// 생성하는 것 입니다.

	//char alphabet = 'A';
	//int integer = 100;
	//float realNum = 36.5f;
	//
	//// 변수의 메모리 공간은 프로그램이 실행될 때마다 바뀐다.
	//
	///*
	//* 형식 지정자
	//* 단일 문자 %c
	//* 정수 %d, %ld, %lld
	//* 실수 %f, %lf
	//*/
	//
	//printf("alphabet 변수의 값 : %c\n", alphabet);
	//printf("integer 변수의 값 : %d\n", integer);
	//printf("realNum 변수의 값 : %.2f\n\n", realNum);
	//
	//
	//// 변수는 프로그램이 실행되는 동안 값을 바꿀 수 있으며,
	//// 원래 저장되어 있는 값은 새로 저장된 값에 의해 지워집니다.
	//
	//alphabet += 2;
	//integer *= 2;
	//realNum *= 2;
	//
	//printf("변경된 alphabet 변수의 값 : %c\n", alphabet);
	//printf("변경된 integer 변수의 값 : %d\n", integer);
	//printf("변경된 realNum 변수의 값 : %.2f\n", realNum);

#pragma endregion

#pragma region 변수 이름 규칙

	// 네이밍 컨벤션
	// 
	// camel 표기법
	// 첫단 小, 뒷단 大, 변수 이름에 주로 사용
	// ex) underScore
	// 
	// pascal 표기법
	// 단어 첫글자 大, 함수 표기에 주로 사용
	// ex) GameManager
	// 
	// snake 표기법
	// 단어 사이에 '_' 끼워 넣기, 매크로에 주로 사용
	// ex) MAX_SIZE
	// 

	// 1.변수의 이름은 대문자와 소문자를 구별하여 사용할 수 있음.
	// ex)
	// int score = 100;
	// int Score = 50;
	// 
	// 2. 변수의 이름으로 예약어를 사용할 수 없음.
	// 
	// ex) int int = 0;
	// 
	// 3. 변수의 이름에 공백이 포함될 수 없음.
	// ex) int value  = 30;
	// 
	// 4. 변수의 이름으로 특수기호는 "_"와 "$"만 사용 가능
	// ex)
	// int x_value = 20;
	// int y$value = 30;
	// 
	// 5. 변수의 이름은 숫자로 시작 불가
	// ex)
	// int 5day = 5; (X)
	// int minute1 = 30; (O)
	//





#pragma endregion

#pragma region 상수

// 프로그램 실행 중에 더이상 값이 변경되지 않는 메모리
// 

	const float pi = 3.141592f;

	// 상수의 경우 메모리 공간을 가지고 있지 않은 상수를 리터럴 상수라고 하며,
	// 메모리 공간을 가지고 있는 상수를 심볼릭 상수라고 한다.

#pragma endregion

#pragma region 연산자
// 산술 연산자
// +,-,*(곱),/(나누기),%(나머지)
// 
// 대입 연산자
// =,+=,-=,*=,/=,%=
// 
// 가산 연산자
// ++,--
// 
// 비교 연산자
// >,<,>=,<=,!=,==
// 
// 논리 연산자
// ||, &&, !

/*
* 과제
* 1. 변수 = 변수 + 리터럴 상수
* 2. 변수 = 리터럴 상수 - 심볼릭 상수
* 3. 변수 = 변수 * 심볼릭 상수
* 4. 변수 = 변수 / 리터럴 상수
* 5. 변수 = 리터럴 상수 % 리터럴 상수
*/

	int result = 200;
	const int TEN = 10;

	printf("변수 : %d , 심볼릭 상수 : %d\n\n", result, TEN);

	// 1. 변수 = 변수 + 리터럴 상수
	printf("1. 변수 = 변수 + 리터럴 상수(10)\n\n");
	result = result + 10;
	printf("결과 : %d\n\n\n", result);
	result = 200;

	// 2. 변수 = 리터럴 상수 - 심볼릭 상수;
	printf("2. 변수 = 리터럴 상수(300) - 심볼릭 상수\n\n");
	result = 300 - TEN;
	printf("결과 : %d\n\n\n", result);
	result = 200;

	// 3. 변수 = 변수 * 심볼릭 상수
	printf("3. 변수 = 변수 * 심볼릭 상수\n\n");
	result = result * TEN;
	printf("결과 : %d\n\n\n", result);
	result = 200;

	// 4. 변수 = 변수 / 리터럴 상수
	printf("4. 변수 = 변수 / 리터럴 상수(50)\n\n");
	result = result / 50;
	printf("결과 : %d\n\n\n", result);
	result = 200;

	// 5. 변수 = 리터럴 상수 % 리터럴 상수
	printf("5. 변수 = 리터럴 상수 % 리터럴 상수\n\n");
	result = 500 % 17;
	printf("결과 : %d\n\n\n", result);
	result = 200;


#pragma endregion

}