#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>



int main()
{
	int tasks[6] = { 20, 40, 30, 15, 10, 60 };
	int size = sizeof(tasks) / sizeof(int);

	int groupCount = 0;
	int taskTime = 0;
	int taskCount = 0;

	for (int i = 0; i < size; i++)
	{
		if (taskTime + tasks[i] <= 60 && taskCount < 3)
		{
			taskTime += tasks[i];
			taskCount++;
		}
		else
		{
			groupCount++;
			taskTime = tasks[i];
			taskCount = 1;
		}
	}
	if (taskTime > 0)
	{
		groupCount++;
	}

	printf("%d", groupCount);

	return 0;
}