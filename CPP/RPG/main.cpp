#include "Title.h"

void main()
{
	while (true)
	{
		system('cls');

		cout << "1_ 게임 시작" << endl << endl;
		cout << "2_ 게임 종료" << endl << endl;

		int input = 0;

		cin >> input;

		if (input == 1)
		{

		}
		else if (input == 2)
		{
			cout << "게임을 종료 합니다. (Y/N)" << endl << endl;

			int input = _getch();

			if (input == 'Y' || input == 'y')
			{
				return;
			}
			else if (input == 'N' || input == 'n')
			{
				continue;
			}
			else
			{
				cout << "잘못 된 입력입니다. 다시 시도해 주십시오." << endl << endl;
				_getch();
			}
		}
	}

	
}