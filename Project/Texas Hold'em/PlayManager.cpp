#include "PlayManager.h"

void Title()
{
	HideCursor();
	while (true)
	{
		system("cls");
		GotoXY(75, 6);
		cout << R"(
			
		      _    _       _     _   _ _   _     _    _       _     _ _                _ 
		     | |  | |     | |   | | (_) | | |   | |  | |     | |   | ( )              | |
		     | |__| | ___ | | __| |  _| |_| |   | |__| | ___ | | __| |/  ___ _ __ ___ | |
		     |  __  |/ _ \| |/ _` | | | __| |   |  __  |/ _ \| |/ _` |  / _ \ '_ ` _ \| |
		     | |  | | (_) | | (_| | | | |_|_|   | |  | | (_) | | (_| | |  __/ | | | | |_|
		     |_|  |_|\___/|_|\__,_| |_|\__(_)   |_|  |_|\___/|_|\__,_|  \___|_| |_| |_(_)
		                                                                                 
                                                                             

		)";
		GotoXY(50, 18);
		cout << "1_ 게임 시작\n\n";
		GotoXY(50, 20);
		cout << "2_ 게임 종료\n\n";

		GotoXY(50, 22);
		int input;
		input = _getch();

		if (input == '1')
		{
			Play();
		}
		else if(input == '2')
		{
			cout << "게임을 종료합니까? (Y/N)\n\n";
			int yesOrNo;
			yesOrNo = _getch();

			if (yesOrNo == 'y' || yesOrNo == 'Y')
			{
				return;
			}
			else if (yesOrNo == 'n' || yesOrNo == 'N')
			{
				continue;
			}
			else
			{
				cout << "잘못된 입력입니다. 다시 시도 하십시오.\n\n";
				_getch();
			}
		}
		else
		{
			cout << "잘못된 입력입니다. 다시 시도 하십시오.\n\n";
			_getch();
		}
	}
}

void Play()
{
	GameDescription();
	srand((unsigned int)time(NULL));
	Deck deck;
	Card init(CLOVER, TWO);
	Player player;
	Player dealer("딜러", 20000);

	DifficultySet(player);

	Game gameManager(player, dealer);

	ShowCursor();
	gameManager.Round();
}

void GameDescription()
{
	system("cls");
	int input;
	GotoXY(40, 6);
	cout << "Hold it! Hold'em에 오신 걸 환영합니다.                (1번을 누르면 스킵)\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(30, 8);
	cout << "Hold it! Hold'em은 텍사스 홀덤 규칙을 따르는 포커 게임 입니다.\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(35, 10);
	cout << "승리 조건은 딜러를 파산시키면 게임이 종료 됩니다.\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(40, 12);
	cout << "난이도에 따라 시작자금이 결정됩니다.\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(40, 14);
	cout << "당신의 운을 시험 해보시길 바랍니다.\n\n";
	_getch();
	

}

void DifficultySet(Player& p)
{
	while (true)
	{
		system("cls");
		GotoXY(75, 4);
		cout << R"(
				         __                                __          __ 
				   _____/ /_____ _____ ____     ________  / /__  _____/ /_
				  / ___/ __/ __ `/ __ `/ _ \   / ___/ _ \/ / _ \/ ___/ __/
				 (__  ) /_/ /_/ / /_/ /  __/  (__  )  __/ /  __/ /__/ /_  
				/____/\__/\__,_/\__, /\___/  /____/\___/_/\___/\___/\__/  
				               /____/                                     
)";
		GotoXY(40, 14);
		cout << "난이도를 선택해 주십시오.\n\n\n";
		GotoXY(40, 17);
		cout << "1_ 대부(쉬움 | 시작자금 : 10000)\n\n";
		GotoXY(40, 19);
		cout << "2_ 일반인(보통 | 시작자금 : 5000)\n\n";
		GotoXY(40, 21);
		cout << "3_ 한량(어려움 | 시작자금 : 2000)\n\n";


		int input = 0;
		GotoXY(40, 22);
		input = _getch();

		if (input == '1')
		{
			GotoXY(40, 25);
			cout << "대부 난이도를 선택하셨습니다. 계속하시겠습니까? (Y/N)\n\n";
			int easy = _getch();
			
			if (easy == 'y' || easy == 'Y')
			{
				p.ChangeMoney(10000);
				return;
			}
			else if (easy == 'n' || easy == 'N')
			{
				continue;
			}
			else
			{
				cout << "잘못된 입력입니다. 다시 시도하십시오.\n\n";
				_getch();
			}
		}
		else if (input == '2')
		{
			GotoXY(40, 25);
			cout << "일반인 난이도를 선택하셨습니다. 계속하시겠습니까? (Y/N)\n\n";
			int normal = _getch();
		
			if (normal == 'y' || normal == 'Y')
			{
				p.ChangeMoney(5000);
				return;
			}
			else if (normal == 'n' || normal == 'N')
			{
				continue;
			}
			else
			{
				cout << "잘못된 입력입니다. 다시 시도하십시오.\n\n";
				_getch();
			}
		}
		else if (input == '3')
		{
			GotoXY(40, 25);
			cout << "한량 난이도를 선택하셨습니다. 계속하시겠습니까? (Y/N)\n\n";
			int hard = _getch();
			if (hard == 'y' || hard == 'Y')
			{
				p.ChangeMoney(2000);
				return;
			}
			else if (hard == 'n' || hard == 'N')
			{
				continue;
			}
			else
			{
				cout << "잘못된 입력입니다. 다시 시도하십시오.\n\n";
				_getch();
			}
		}
		else
		{
			cout << "잘못된 입력입니다. 다시 시도하십시오.\n\n";
			_getch();
		}
	}
}

