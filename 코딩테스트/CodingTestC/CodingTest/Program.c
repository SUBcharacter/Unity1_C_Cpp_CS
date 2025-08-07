#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int start;
	int finish;
	int difficult;
}Schedule;

float Solution(Schedule schedule[], int size)
{
	int startTime = 10000;
	int finishTime = 0;

	for (int i = 0; i < size; i++)
	{
		if (schedule[i].start < startTime)
		{
			startTime = schedule[i].start;
		}
		if (schedule[i].finish > finishTime)
		{
			finishTime = schedule[i].finish;
		}
	}

	int timeLine[25] = {0};

	for (int i = 0; i < size; i++)
	{
		for (int t = schedule[i].start; t < schedule[i].finish; t++)
		{
			if (timeLine[t] < schedule[i].difficult)
			{
				timeLine[t] = schedule[i].difficult;
			}
		}
	}

	int totalDiff = 0;
	int totalTime = 0;

	for (int t = startTime; t < finishTime; t++)
	{
		if (timeLine[t] > 0)
		{
			totalDiff += timeLine[t];
			totalTime++;
		}
	}

	return (float)totalDiff / totalTime;

}
int main()
{
	Schedule schedule[] = { {9, 11, 2}, {10, 12, 5}, {13, 14, 1} };
	printf("%.2f", Solution(schedule, sizeof(schedule)/sizeof(Schedule)));

	return 0;
}