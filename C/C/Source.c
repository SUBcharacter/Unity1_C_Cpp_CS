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

#pragma region 비트 연산자

	// 비트 단위로 논리 연산을 수행하기 위해 사용하는 연산자

#pragma endregion

#pragma region AND 연산자
	// 두 개의 피연산자가 모두 1이면 1을 반환하는 연산자.

	//int x1 = 10;
	//int y1 = 6;
	//
	//printf("%d", x1 & y1);
	
#pragma endregion
#pragma region OR 연산자
	// 두 개의 피연산자 중에 하나라도 1이 있다면 1을 반환하는 연산자.

	int x = 8; // 0000 1000
	int y = 12; // 0000 1100
				// --------
				// 0000 1100
	printf("%d", x | y);

#pragma endregion


#pragma endregion

}