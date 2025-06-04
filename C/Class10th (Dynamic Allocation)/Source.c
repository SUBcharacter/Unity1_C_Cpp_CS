#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
#pragma region 동적 할당

	// 프로그램을 실행 중에 필요한 만큼 메모리를 할당하는 작업
	// 동적 할당은 실행 시간에 가변적으로 메모리의 크기를 변경시킬 수 있으며,
	// 동적으로 메모리의 크기를 할당할 때 바이트 단위로 지정
	//int x = 50, y = (x + 50) / 20;
	//int* name = malloc(sizeof(int));
	//*name = x+ y;
	//printf("%d", *name);
	//
	//free(name);

	//int* array = malloc(sizeof(int) * 3);
	//
	//for (int i = 1; i <= 3; i++)
	//{
	//	array[i-1] = i * 10;
	//}
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("Address of array[%d] : %p\n", i, &array[i]);
	//	printf("array[%d] : %d\n\n", i, array[i]);
	//}
	//
	//free(array);

#pragma region 과제

	// UAF(Use After Free)
	// HEAP 영역에서 malloc으로 할당한 공간을 free로 해제후
	// 메모리를 다시 할당하면 같은 공간이 재사용 되는 것.

	//int* uaf = malloc(sizeof(int));
	//
	//*uaf = 30;
	//
	//printf("uaf의 값 : %d, uaf의 주소 : %p\n\n", *uaf, uaf);
	//
	//free(uaf);
	//
	//uaf = malloc(sizeof(int));
	//
	//printf("uaf의 주소 : %p\n", uaf);

#pragma endregion


#pragma endregion

#pragma region 허상 포인터

	// 이미 해제된 메모리 영역을 가리키는 포인터

	// int* dangleptr = malloc(sizeof(int));
	// 
	// *dangleptr = 30;
	// 
	// printf("주소 : %p, 값 : %d\n\n", dangleptr, *dangleptr);
	// 
	// free(dangleptr);
	// dangleptr = NULL;

	// printf("주소 : %p, 값 : %d\n\n", dangleptr, *dangleptr);

#pragma endregion

	return 0;
}