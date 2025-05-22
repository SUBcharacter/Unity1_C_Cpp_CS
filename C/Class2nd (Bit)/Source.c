#include <stdio.h>

//진입점
void main()
{
#pragma region 비트
	// 데이터를 나타내는 최소의 단위이며, 0 또는 1의
	// 조합으로 논리 계산을 수행하는 단위

	// 메모리는 비트 단위로 데이터를 저장할 수 잇으며,
	// 1개의 비트에는 0 또는 1의 값만 저장할 수 있음.

#pragma region (10)진수 -> (2)진수
	// 10진수를 1이 될 때까지 계속 2로 나누어 준다음
	// 나눈 위치의 나머지 값을 아래에서 위로 순서대로 정렬

	// 00001111
#pragma endregion

#pragma region (2)진수 -> (10)진수
	// 1byte에 2진수로 저장된 값을 2의 제곱으로 나타낸다.

	// 각각의 비트에 1이 있다면 1과 2의 제곱의 위치를 계산한 다음
	// 각각의 비트를 모두 더하여 10진수로 나타냅니다.


#pragma endregion

#pragma region Overflow

	// 특정한 자료형이 표현할 수 있는 최댓값의 범위를
	// 넘어서 연산을 수행하는 과정입니다.

	//float byte = 1;
	//
	//for (int i = 1; i < 1000; i++)
	//{
	//	system("cls");
	//	byte += i;
	//	printf("%f", byte);
	//	Sleep(10);
	//	
	//}

	// 오버플로우는 부호 없는 자료형에서도 똑같이 발생하며,
	// 실수일 때 오버플로우가 발생하면 infinity라는 값으로 출력됨.

#pragma endregion

#pragma region Underflow

	// 특정한 자료형이 표현할 수 있는 최솟값의 범위를 넘어서
	// 연산을 수행하는 과정

	//char byte = -129;
	//
	//printf("%d", byte);



	// 언더플로우는 부호 없는 자료형에서도 똑같이 발생하며,
	// 실수일 때 언더플로우가 발생하면 0이라는 값으로 출력.

#pragma endregion

#pragma region Unsigned

	// 정수 값을 저장할 수 있는 자료형 중에서
	// 부호 비트 없이 양의 정수와 0만을 표현할 수 있는 자료형

	//unsigned int exp = -1;
	//printf("%u", exp);
	//
	//int exp1 = 4294967296/2;
	//printf("%d", exp1);
	// 실수는 IEEE 754 구조가 부호 비트를 포함하고 있으므로,
	// 부호 없이 사용할 수 없음.

#pragma endregion

#pragma region 실수

	//double attack = 1.0f;
	//printf("Attack : %.100f", attack);

#pragma endregion

#pragma region 고정 소수점

	// 소수점의 위치를 고정하여 소수점의 위치를 나타내는 방법

	// 고정 소수점은 정수부와 소수부의 크기가 작음
	// 따라서 표현할 수 있는 범위가 한정되어 있음

#pragma endregion

#pragma region 부동 소수점

	// 소수점의 위치를 고정하지 않고 소수점의 위치를 나타내는 방법

	//가수부에 있는 비트 중 가장 왼쪽에 있는 수는 표현 하지 않음

#pragma endregion


#pragma region 비트 연산자

	// 비트 단위로 논리 연산을 수행하기 위해 사용하는 연산자

#pragma endregion

#pragma region AND 연산자
	// 두 개의 피연산자가 모두 1이면 1을 반환하는 연산자.

	//int x1 = 10; // 0000 1010
	//int y1 = 6;  // 0000 0110
	//			   // ----------- and
	//             // 0000 0010
	//printf("%d", x1 & y1);

#pragma endregion

#pragma region OR 연산자
	// 두 개의 피연산자 중에 하나라도 1이 있다면 1을 반환하는 연산자.

	//int x = 8; // 0000 1000
	//int y = 12; // 0000 1100
	//			// -------- or
	//			// 0000 1100
	//printf("%d", x | y);

#pragma endregion

#pragma region XOR 연산자 

	// 두 개의 피연산자가 서로 같으면 0을 반환하고
	// 서로 다르면 1을 반환 하는 연산자.

	// ^

	//int x = 3; // 0000 0011
	//int y = 8; // 0000 1000
	//		   // ---------- xor
	//		   // 0000 1011
	//
	//printf("%d", x ^ y);

#pragma endregion

#pragma region NOT 연산자

	// 비트를 반전시키는 연산자, ~
	//unsigned int packet = 14; // 0000 1110
	//						   // 1111 0001
	//printf("%d",~packet);

	// 비트의 경우 가장 앞에 있는 비트는 부호를 나타내며,
	// 1이 있다면 값은 음수가 된다.

#pragma endregion

#pragma region  시프트 연산자

	// 값의 모든 비트를 지정한 수 만큼 특정 위치로 이동시키는 연산자
	// << Lshift, >> Rshift
	//char data = 127; // 0000 1010
	//
	//for (int i = 0; i < 100; i += 2)
	//{
	//	printf("%d\n", data >> i);
	//	Sleep(100);
	//	system("cls");
	//}
#pragma endregion



#pragma endregion
}