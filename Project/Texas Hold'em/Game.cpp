#include "Game.h"

int Game::Input()
{
	ShowCursor();
	string input;
	int choice = 0;
	int x = 28 + player.GetName().length();
	while (true)
	{
		GotoXY(x, 21);
		getline(cin, input);
		

		if (!input.empty())
		{
			choice = stoi(input);
			if (choice < 1 || choice >3)
			{
				GotoXY(x, 22);
				cout << "잘못된 입력입니다. 다시 시도 하십시오.\n\n";
				_getch();
				GotoXY(x, 21);
				cout << "       ";
				cout << "                                               ";

			}
			else
				break;
		}
	}
	

	GotoXY(x, 21);
	cout << "       ";
	HideCursor();
	return choice;
}

void Game::StartNewRound()
{
	pot = 0;
	isAllin = false;
	communityCard.clear();
	player.ClearHand();
	dealer.ClearHand();

	deck.ShuffleDeck();

	player.AddCard(deck.DrawCard(true));
	dealer.AddCard(deck.DrawCard(true));
	player.AddCard(deck.DrawCard(true));
	dealer.AddCard(deck.DrawCard(true));

	PlayerCard();
}

void Game::DealCommunityCard(int count)
{
	deck.DrawCard();
	for (int i = 0; i < count; i++)
	{
		communityCard.push_back(deck.DrawCard());
	}
}

void Game::ShowCommunityCard()
{
	int x = 10;
	for (int i = 0; i < communityCard.size(); i++)
	{
		
		communityCard[i].PrintCard(x,8);
		x += 8;
	}
	
}

void Game::ShowGameState(int round, bool showDown)
{
	system("cls");
	GotoXY(0, 0);
	cout << round << " 라운드" << endl << endl;
	GotoXY(90, 0);
	cout << "[딜러]"; 
	GotoXY(97, 0);
	cout << "소지금 : " << dealer.GetMoney();
	if (showDown)
	{
		GotoXY(85, 2);
		dealer.ShowHand(85, 2);
	}
	else
	{
		GotoXY(85, 3);
		cout << "(비공개)" << endl << endl << endl;
	}
	
	GotoXY(27, 7);
	cout << "[커뮤니티 카드]  " << endl << endl;
	if (communityCard.empty())
	{
		GotoXY(28, 12);
		cout << "(카드 공개 전)" << endl << endl << endl;
	}
	else
	{
		ShowCommunityCard();
	}
	
	GotoXY(0, 19);
	cout << "[" << player.GetName() << "]  소지금 : " << player.GetMoney();
	
	player.ShowHand(3,22);
	
}

void Game::ShowHand()
{
	GotoXY(80, 13);
	dealer.ShowHighRank();
	GotoXY(80, 16);
	player.ShowHighRank();
}

bool Game::CheckPlayerMoney(Player& pd)
{
	if (pd.GetMoney() <= 0)
	{
		return true;
	}

	return false;
}

void Game::BetFromPlayer(Player& p, int chip)
{
	int bettingChip = 0;
	
	if (chip >= p.GetMoney())
	{
		bettingChip = p.GetMoney();
		GotoXY(80, 9);
		cout << "소지금 보다 많이 베팅하셨습니다.";
		GotoXY(80, 10);
		cout << "자동으로 올인 처리됩니다.";
		GotoXY(80, 11);
		cout <<"올인 금액 : " << bettingChip;
		isAllin = true;
	}
	else
	{
		bettingChip = chip;
	}

	p.ChangeMoney(-bettingChip);
	pot += bettingChip;
	
	
}

void Game::FirstBet()
{
	GotoXY(80, 7);
	cout << "[스타트 베팅]" << endl << endl;
	int x = 28 + player.GetName().length();
	BetFromPlayer(player, entry / 2);
	BetFromPlayer(dealer, entry);
	GotoXY(x, 19);
	cout << "플레이어의 차례";
	GotoXY(x, 20);
	cout << "1_ 레이즈  2_ 콜  3_ 다이" << endl << endl;
	
	int choice = 0;

	choice = Input();

	if (choice == 1) // 레이즈
	{
		ShowCursor();
		actPlayer = RAISE;
		GotoXY(x, 23);
		cout << "레이즈 금액을 입력해 주십시오. 현재 소지금 : " << player.GetMoney() << endl << endl;
		string input;
		int raise = 0;
		while (true)
		{
			GotoXY(x, 24);
			raise = 0;
			getline(cin, input);

			if (input.empty())
				continue;

			raise = stoi(input);
			break;
		}
		HideCursor();
		bettingPlayer = raise + entry;
		GotoXY(x, 23);
		cout << "                                                                ";
		GotoXY(x, 24);
		cout << "                             ";
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		cout << player.GetName()+ " " << raise << " 레이즈 | -" << raise + (entry / 2) << endl << endl;
		BetFromPlayer(player, raise + (entry / 2));
	}
	else if (choice == 2) // 콜
	{
		actPlayer = CALL;
		BetFromPlayer(player, entry / 2);
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		cout << player.GetName() << " 콜 | -" << entry / 2 << endl << endl;
	}
	else if (choice == 3) // 다이
	{
		actPlayer = DIE;
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		cout << player.GetName() << " 다이" << endl << endl;
	}

	DealerDecision(actPlayer,entry);
	GotoXY(80, 17);
	cout << "현재 베팅액 : " << pot << endl << endl;
	
	
}

void Game::DefaultBet()
{

	if(isAllin)
	{
		return;
	}

	bettingDealer = 0;
	bettingPlayer = 0;

	int x = 28 + player.GetName().length();
	GotoXY(80, 7);
	cout << "[베팅 타임]" << endl << endl;
	GotoXY(x, 19);
	cout << "플레이어의 차례" << endl;
	GotoXY(x, 20);
	cout << "1_ 레이즈  2_ 체크  3_ 다이" << endl << endl;
	GotoXY(x, 21);
	int choice = 0;

	choice = Input();

	if (choice == 1) // 레이즈
	{
		GotoXY(x, 23);
		actPlayer = RAISE;
		cout << "레이즈 금액을 입력해 주십시오. 현재 소지금 : " << player.GetMoney() << endl << endl;
		GotoXY(x, 24);
		int raise = 0;
		string input;
		ShowCursor();
		while (true)
		{
			GotoXY(x, 24);
			raise = 0;
			getline(cin, input);

			if (input.empty())
				continue;

			raise = stoi(input);
			break;
		}
		HideCursor();
		GotoXY(x, 23);
		cout << "                                                                ";
		GotoXY(x, 24);
		cout << "                   ";
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		bettingPlayer = raise;
		GotoXY(80, 9);
		cout << player.GetName() + " " << raise << " 레이즈 | -" << raise << endl << endl;
		BetFromPlayer(player, raise);
	}
	else if (choice == 2) // 체크
	{
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		actPlayer = CHECK;
		cout << player.GetName() << " 체크!";
	}
	else if (choice == 3) // 다이
	{
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		actPlayer = DIE;
		cout << player.GetName() << " 다이" << endl << endl;
	}

	DealerDecision(actPlayer);
	GotoXY(80, 17);
	cout << "현재 베팅액 : " << pot << endl << endl;
	
}

void Game::DealerDecision(Acting actPlayer, int entry)
{
	if (actPlayer == DIE)
	{
		return;
	}
	GotoXY(80, 13);
	cout << "딜러 결정중 ...." << endl << endl << endl;

	Sleep(2500);

	GotoXY(80, 13);
	cout << "                           ";
	int dealerChoice = (rand() % 100) + 1;
	switch (actPlayer)
	{
	case RAISE:
		if (dealerChoice >= 30) // 콜
		{
			actDealer = CALL;
			BetFromPlayer(dealer, bettingPlayer - entry);// raise 금액 만큼 더 베팅
			GotoXY(80, 13);
			cout << "딜러 콜! 콜 금액 : " << bettingPlayer - entry << endl << endl;
		}
		else if (dealerChoice < 30) // 다이
		{
			actDealer = DIE;
			return;
		}
		break;
	case CALL :
		if (dealerChoice >= 30) // 체크
		{
			actDealer = CHECK;
			GotoXY(80, 13);
			cout << "딜러 체크!" << endl << endl;
		}
		else if (dealerChoice < 30) // 다이
		{
			actDealer = DIE;
			return;
		}
		break;
	case CHECK:
		actDealer = CHECK;
		GotoXY(80, 13);
		cout << "딜러 체크!\n\n";
		break;
	}
}

bool Game::DecisionCheck()
{
	if (actPlayer == DIE)
	{
		dealer.ChangeMoney(pot);
		GotoXY(80, 9);
		cout << player.GetName() << " 다이.... 딜러가 상금을 수령합니다.\n\n";
	}
	else if(actDealer == DIE)
	{
		player.ChangeMoney(pot);
		GotoXY(80, 13);
		cout << "딜러 다이! 상금을 수령합니다!";
		GotoXY(80, 14);
		cout << "상금: " << pot;
	}
	else
	{
		actPlayer = DEFAULT;
		actDealer = DEFAULT;
		return false;
	}

	actPlayer = DEFAULT;
	actDealer = DEFAULT;
	GotoXY(80, 16);
	cout << "다음 라운드로 넘어갑니다.\n\n" << endl;
	_getch();

	return true;
}

void Game::PlayerCard()
{
	// 초기화
	playerCard.clear();
	dealerCard.clear();

	// 핸드 삽입
	playerCard.insert(playerCard.end(), player.GetHand().begin(), player.GetHand().end());
	dealerCard.insert(dealerCard.end(), dealer.GetHand().begin(), dealer.GetHand().end());

	// 커뮤니티 카드 삽입
	playerCard.insert(playerCard.end(), communityCard.begin(), communityCard.end());
	dealerCard.insert(dealerCard.end(), communityCard.begin(), communityCard.end());

	// 배열 정렬
	sort(playerCard.begin(), playerCard.end());
	sort(dealerCard.begin(), dealerCard.end());

}

void Game::ShowPlayerCard()
{
	if (!playerCard.empty())
	{
		cout << "감지된 카드들\n\n";
		for (int i = 0; i < playerCard.size(); i++)
		{
			cout << playerCard[i].GetCardString() << "  ";
		}
		cout << "\n\n";
	}
	else
		return;
}

void Game::Rewarding(Player& p, Player& d)
{
	int y = 18;
	GotoXY(80, y);
	if (p.GetHR() > d.GetHR())
	{
		if (p.GetHR() == ROYALSTRAIGHTFLUSH)
		{
			cout << "축하드립니다! 로얄 스트레이트 플러쉬 달성!";
			GotoXY(80, y+1);
			cout << "상금: " << pot;
			p.ChangeMoney(pot);
		}
		else
		{
			cout << p.GetName() << "가 승리 하였습니다!";
			GotoXY(80, y + 1);
			cout << "상금 : " << pot;
			p.ChangeMoney(pot);
			
		}
		
	}
	else if (p.GetHR() < d.GetHR())
	{
		if (d.GetHR() == ROYALSTRAIGHTFLUSH)
		{
			cout << "이런... 딜러가 로얄 스트레이트 플러쉬를 달성했습니다...";
			GotoXY(80, y + 1);
			cout << "딜러 상금 : " << pot;
			d.ChangeMoney(pot);
		}
		else
		{
			cout << "딜러가 승리 하였습니다...";
			GotoXY(80, y + 1);
			cout << "딜러 상금 : " << pot;
			d.ChangeMoney(pot);
		}
	}
	else if (p.GetHR() == d.GetHR())
	{
		switch (p.GetHR())
		{
		case HIGHCARD:
			for (int i = p.GetHC().size()-1;i >= 0 ;i--)
			{
				if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << p.GetName() << "의 하이카드! 승리 하였습니다!";
					GotoXY(80, y + 1);
					cout << "상금 : " << pot;
					p.ChangeMoney(pot);
					return;
					
				}
				else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << "딜러의 하이카드.... 아쉽습니다....";
					GotoXY(80, y + 1);
					cout << "딜러 상금 : " << pot;
					d.ChangeMoney(pot);
					return;
				}
				else
					continue;
			}
			cout << "스플릿 팟! 판돈을 나눠 갖습니다.";
			GotoXY(80, y + 1);
			cout << "상금 : " << pot / 2;
			p.ChangeMoney(pot / 2);
			d.ChangeMoney(pot / 2);

			break;

		case ONEPAIR:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "가 승리 하였습니다!";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot;
				p.ChangeMoney(pot);
				
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "딜러가 승리 하였습니다...";
				GotoXY(80, y + 1);
				cout << "딜러 상금 : " << pot;
				d.ChangeMoney(pot);
			}
			else
			{
				for (int i = 3; i >= 1; i--)
				{
					if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << p.GetName() << "의 하이카드! 승리 하였습니다!";
						GotoXY(80, y + 1);
						cout << "상금 : " << pot;
						p.ChangeMoney(pot);
						return;
					}
					else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << "딜러의 하이카드.... 아쉽습니다...";
						GotoXY(80, y + 1);
						cout<< "딜러 상금 : " << pot;
						d.ChangeMoney(pot);
						return;
					}
					else
						continue;
				}
				cout << "스플릿 팟! 판돈을 나눠 갖습니다."; 
				GotoXY(80, y + 1);
				cout<< "상금 : " << pot / 2;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
				break;
			}
			break;

		case TWOPAIR:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "가 승리 하였습니다!";
				GotoXY(80, 14);
				cout << "상금 : " << pot;
				p.ChangeMoney(pot);
				
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "딜러가 승리 하였습니다..";
				GotoXY(80, y + 1);
				cout<< "딜러 상금 : " << pot;
				d.ChangeMoney(pot);
			}
			else
			{
				if (Card::CompareNumber1(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << p.GetName() << "가 승리 하였습니다!";
					GotoXY(80, y + 1);
					cout << "상금: " << pot;
					p.ChangeMoney(pot);
					
				}
				else if (Card::CompareNumber2(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << "딜러가 승리 하였습니다...";
					GotoXY(80, y + 1);
					cout << "딜러 상금 : " << pot;
					d.ChangeMoney(pot);
				}
				else
				{
					if (Card::CompareNumber1(p.GetHC()[2], d.GetHC()[2]))
					{
						cout << p.GetName() << "의 하이카드! 승리 하였습니다!";
						GotoXY(80, y + 1);
						cout << "상금 : " << pot;
						p.ChangeMoney(pot);
					}
					else if (Card::CompareNumber2(p.GetHC()[2], d.GetHC()[2]))
					{
						cout << "딜러의 하이카드... 승리 하였습니다..";
						GotoXY(80, y + 1);
						cout << "딜러 상금 : " << pot;
						d.ChangeMoney(pot);
					}
					else
					{
						cout << "스플릿 팟! 판돈을 나눠 갖습니다.";
						GotoXY(80, y + 1);
						cout << "상금 : " << pot / 2;
						p.ChangeMoney(pot / 2);
						d.ChangeMoney(pot / 2);
					}
				}
			}
			break;
		case TRIPLE:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "가 승리 하였습니다!";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "딜러가 승리 하였습니다...";
				GotoXY(80, y + 1);
				cout << "딜러 상금 : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				for (int i = 2; i >= 1; i--)
				{
					if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << p.GetName() << "의 하이카드! 승리 하였습니다";
						GotoXY(80, y + 1);
						cout << "상금 : " << pot << endl << endl << endl;
						p.ChangeMoney(pot);
						return;
					}
					else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << "딜러의 하이카드.... 아쉽습니다...."; 
						GotoXY(80, y + 1);
						cout << "딜러 상금 : " << pot << endl << endl << endl;
						d.ChangeMoney(pot);
						return;
					}
					else
						continue;
				}
				cout << "스플릿 팟! 판돈을 나눠 갖습니다";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot / 2 << endl << endl << endl;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
			}
			break;
		case STRAIGHT:
			if (Card::CompareNumber1(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << p.GetName() << "가 승리 하였습니다!"; 
				GotoXY(80, y + 1);
				cout << "상금 : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << "딜러가 승리 하였습니다...";
				GotoXY(80, y + 1);
				cout << "딜러 상금 : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				cout << "스플릿 팟! 판돈을 나눠 갖습니다";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot / 2 << endl << endl << endl;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
			}
			break;
		case FLUSH:
			for (int i = 4; i >= 0; i--)
			{
				if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << p.GetName() << "가 승리 하였습니다!";
					GotoXY(80, y + 1);
					cout << "상금 : " << pot << endl << endl << endl;
					p.ChangeMoney(pot);
					return;
				}
				else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << "딜러가 승리 하였습니다..";
					GotoXY(80, y + 1);
					cout << "딜러 상금 : " << pot << endl << endl << endl;
					d.ChangeMoney(pot);
					return;
				}
				else
					continue;
			}
			cout << "스플릿 팟! 판돈을 나눠 갖습니다.";
			GotoXY(80, y + 1);
			cout << "상금 : " << pot / 2 << endl << endl << endl;
			p.ChangeMoney(pot / 2);
			d.ChangeMoney(pot / 2);
			break;
		case FULLHOUSE:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "가 승리 하였습니다!";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "딜러가 승리 하였습니다...";
				GotoXY(80, y + 1);
				cout << "딜러 상금 : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				if (Card::CompareNumber1(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << p.GetName() << "가 승리 하였습니다!";
					GotoXY(80, y + 1);
					cout << "상금 : " << pot << endl << endl << endl;
					p.ChangeMoney(pot);
				}
				else if (Card::CompareNumber2(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << "딜러가 승리 하였습니다...";
					GotoXY(80, y + 1);
					cout << "딜러 상금 : " << pot << endl << endl << endl;
					d.ChangeMoney(pot);
				}
				else
				{
					cout << "스플릿 팟! 판돈을 나눠 갖습니다.";
					GotoXY(80, y + 1);
					cout << "상금 : " << pot / 2 << endl << endl << endl;
					p.ChangeMoney(pot / 2);
					d.ChangeMoney(pot / 2);
				}
			}
			break;
		case FOURCARD:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "가 승리 하였습니다!";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "딜러가 승리 하였습니다...";
				GotoXY(80, y + 1);
				cout << "딜러 상금 : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				if (Card::CompareNumber1(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << p.GetName() << "가 승리 하였습니다!";
					GotoXY(80, y + 1);
					cout << "상금 : " << pot << endl << endl << endl;
					p.ChangeMoney(pot);
				}
				else if (Card::CompareNumber2(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << "딜러가 승리 하였습니다...";
					GotoXY(80, y + 1);
					cout << "딜러 상금 : " << pot << endl << endl << endl;
					d.ChangeMoney(pot);
				}
				else
				{
					cout << "스플릿 팟! 판돈을 나눠 갖습니다.";
					GotoXY(80, y + 1);
					cout << "상금 : " << pot / 2 << endl << endl << endl;
					p.ChangeMoney(pot / 2);
					d.ChangeMoney(pot / 2);
				}
			}
			break;
		case STRAIGHTFLUSH:
			if (Card::CompareNumber1(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << p.GetName() << "가 승리 하였습니다!";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << "딜러가 승리 하였습니다...";
				GotoXY(80, y + 1);
				cout << "딜러 상금 : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				cout << "스플릿 팟! 판돈을 나눠 갖습니다.";
				GotoXY(80, y + 1);
				cout << "상금 : " << pot / 2 << endl << endl << endl;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
			}
			break;
		}
		return;
	}
}

void Game::Round()
{
	
	int round = 0;
	while (true)
	{
		system("cls");
		// 각 플레이어의 재화 확인
		if (CheckPlayerMoney(player))
		{
			GotoXY(75,5);
			cout << R"(
		          ,--,     .--.           ,---.         .---..-.   .-.,---.  ,---.    
		        .' .'     / /\ \ |\    /| | .-'        / .-. )\ \ / / | .-'  | .-.\   
		        |  |  __ / /__\ \|(\  / | | `-.        | | |(_)\ V /  | `-.  | `-'/   
		        \  \ ( _)|  __  |(_)\/  | | .-'        | | | |  ) /   | .-'  |   (    
		         \  `-) )| |  |)|| \  / | |  `--.      \ `-' / (_)    |  `--.| |\ \   
		         )\____/ |_|  (_)| |\/| | /( __.'       )---'         /( __.'|_| \)\  
		        (__)             '-'  '-'(__)          (_)           (__)        (__) 
)";
			GotoXY(40, 14);
			cout << "게임 오버! 플레이어가 파산했습니다...." << endl << endl;
			isPlayerDie = true;
			_getch();
			return;
		}
		else if (CheckPlayerMoney(dealer))
		{
			GotoXY(75, 5);
			cout << R"(
	      _  _   ____    ____  __    ______ .___________.  ______   .______     ____    ____   _  _   
	    _| || |_ \   \  /   / |  |  /      ||           | /  __  \  |   _  \    \   \  /   / _| || |_ 
	   |_  __  _| \   \/   /  |  | |  ,----'`---|  |----`|  |  |  | |  |_)  |    \   \/   / |_  __  _|
	    _| || |_   \      /   |  | |  |         |  |     |  |  |  | |      /      \_    _/   _| || |_ 
	   |_  __  _|   \    /    |  | |  `----.    |  |     |  `--'  | |  |\  \----.   |  |    |_  __  _|
	     |_||_|      \__/     |__|  \______|    |__|      \______/  | _| `._____|   |__|      |_||_|                                                                                             
)";
			GotoXY(30, 15);
			cout << "축하합니다! 딜러를 파산 시키셨습니다. 총 상금 : " << player.GetMoney() << endl << endl;
			isDealerDie = true;
			_getch();
			return;
		}

		round++;
		

		StartNewRound();

		ShowGameState(round);

		// 1차 베팅
		FirstBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		

		DealCommunityCard(3);

		ShowGameState(round);

		// 족보 확인

		// 2차 베팅
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState(round);

		// 족보 확인
		
		// 3차 베팅
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState(round);

		// 족보 확인

		// 라스트 베팅
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		
		// 쇼다운

		ShowGameState(true,round);
		
		_getch();

		
		// 우위 확인

		PlayerCard();
		EvaluateCard(player, playerCard);
		EvaluateCard(dealer, dealerCard);

		ShowHand();

		// 상금 수령
		Rewarding(player, dealer);
		_getch();


		
	}
	

}
