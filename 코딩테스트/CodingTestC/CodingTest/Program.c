#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* Solution(const char* question)
{

	int x1, y1, z1;
	float x2, y2, z2;
	char op;
	
	if (sscanf(question, "%d %c %d = %d", &x1, &op, &y1, &z1) == 4)
	{
		switch (op)
		{
		case '+': return (x1 + y1 == z1) ? "O" : "X"; break;
		case '-': return (x1 - y1 == z1) ? "O" : "X"; break;
		case '*': return (x1 * y1 == z1) ? "O" : "X"; break;
		case '/': return (y1 != 0 && x1 / y1 == z1) ? "O" : "X"; break;
		}
	}
	else if (sscanf(question, "%d %c %f = %f", &x1, &op, &y2, &z2) == 4)
	{
		switch (op)
		{
		case '+': return (x1 + y2 == z2) ? "O" : "X"; break;
		case '-': return (x1 - y2 == z2) ? "O" : "X"; break;
		case '*': return (x1 * y2 == z2) ? "O" : "X"; break;
		case '/': return (y2 != 0 && x1 / y2 == z2) ? "O" : "X"; break;
		}
	}
	else if (sscanf(question, "%f %c %d = %f", &x2, &op, &y1, &z2) == 4)
	{
		switch (op)
		{
		case '+': return (x2 + y1 == z2) ? "O" : "X"; break;
		case '-': return (x2 - y1 == z2) ? "O" : "X"; break;
		case '*': return (x2 * y1 == z2) ? "O" : "X"; break;
		case '/': return (y1 != 0 && x2 / y1 == z2) ? "O" : "X"; break;
		}
	}
	else if (sscanf(question, "%f %c %f = %f", &x2, &op, &y2, &z2) == 4)
	{
		switch (op)
		{
		case '+': return (x2 + y2 == z2) ? "O" : "X"; break;
		case '-': return (x2 - y2 == z2) ? "O" : "X"; break;
		case '*': return (x2 * y2 == z2) ? "O" : "X"; break;
		case '/': return (y2 != 0 && x2 / y2 == z2) ? "O" : "X"; break;
		}
	}

	return "X";
}
int main()
{
	printf("%s", Solution("10 / 2 = 4"));

	return 0;
}