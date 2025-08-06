#include <iostream>
#include <random>

using namespace std;

void sieve(int n)
{
	vector<bool> eratos(n + 1, false);

	eratos[0] = eratos[1] = true;

	for (int i = 2; i * i < n; i++)
	{
		if (!eratos[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				eratos[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!eratos[i])
		{
			cout << i << " ";
		}
	}
}

int main()
{
#pragma region 에라토스테네스의 채

	int mean[50];

	for (int i = 0; i < 50; i++)
	{
		if (i == 0 || i == 1)
		{
			mean[i] = 1;
		}
		else
		{
			mean[i] = 0;
		}
		
	}

	for (int i = 2; i < 50; i++)
	{
		if (mean[i] == 1)
		{
			continue;
		}
		for (int j = i * 2; j < 50; j += i)
		{
			mean[j] = 1;
		}
	}

	for (int i = 0; i < 50; i++)
	{
		if (mean[i] == 0)
		{
			cout << i << " ";
		}
	}

	cout << endl;

	sieve(15);

#pragma endregion


	return 0;
}