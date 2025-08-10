#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool ScheduleConflict(int schedule[][2], int size)
{
	int rowSize = size;

	int startTime = 25;
	int finishTime = 0;

	for (int i = 0; i < rowSize; i++)
	{
		if (schedule[i][0] < startTime)
			startTime = schedule[i][0];
		if (schedule[i][1] > finishTime)
			finishTime = schedule[i][1];
	}

	int timeLine[24] = { 0 };

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = schedule[i][0]; j < schedule[i][1]; j++)
		{
			timeLine[j]++;
		}
	}

	for (int i = startTime; i < finishTime; i++)
	{
		if (timeLine[i] > 1)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int schedule[3][2] = { {9, 11}, {13, 15}, {10, 12} };

	int size = sizeof(schedule) / sizeof(schedule[0]);

	if (ScheduleConflict(schedule, size))
	{
		printf("스케쥴 충돌 감지");
	}
	else
	{
		printf("스케쥴 충돌 없음");
	}

	return 0;
}