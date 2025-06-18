#include "Game.h"

void Game::StartNewRound()
{
	communityCard.clear();
	player.ClearHand();
	dealer.ClearHand();

	deck.ShuffleDeck();

	player.AddCard(deck.DrawCard());
	dealer.AddCard(deck.DrawCard());
	player.AddCard(deck.DrawCard());
	dealer.AddCard(deck.DrawCard());
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
	cout << "커뮤니티 카드" << endl << endl;
	for (int i = 0; i < communityCard.size(); i++)
	{
		cout << communityCard[i].GetCard() << "  ";
	}
	cout << endl << endl << endl;
}

void Game::ShowGameState(bool showDown)
{
	cout << "[딜러]  " << "소지금 : " << dealer.GetMoney() << endl << endl;
	if (showDown)
	{
		dealer.ShowHand();
	}
	else
	{
		cout << "(비공개)" << endl << endl << endl;
	}
	

	cout << "[커뮤니티 카드]  " << endl << endl;
	if (communityCard.empty())
	{
		cout << "(카드 공개 전)" << endl << endl << endl;
	}
	else
	{
		ShowCommunityCard();
	}
	

	cout << "[" << player.GetName() << "]  " << "소지금 : " << player.GetMoney() << endl << endl;
	player.ShowHand();
	cout << endl << "-----------------------------------------------------" << endl << endl;

}

bool Game::CheckPlayerMoney()
{
	if (player.GetMoney() <= 0)
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
		cout << "소지금 보다 많이 베팅하셨습니다. 자동으로 올인 처리됩니다. 올인 금액 : "<< bettingChip << endl << endl;
	}
	else
	{
		bettingChip = chip;
	}

	p.ChangeMoney(-bettingChip);
	pot += bettingChip;
	
	
}

bool Game::FirstBet()
{
	cout << "[스타트 베팅]" << endl << endl;

	BetFromPlayer(player, entry / 2);
	BetFromPlayer(dealer, entry);
	cout << "플레이어의 차례" << endl;
	cout << "1_ 레이즈  2_ 콜  3_ 다이" << endl << endl;
	int choice = 0;

	cin >> choice;

	if (choice == 1) // 레이즈
	{
		cout << "레이즈 금액을 입력해 주십시오. 현재 소지금 : " << player.GetMoney() << endl << endl;

		int raise = 0;
		cin >> raise;
		bettingPlayer = raise + entry;
		cout << player.GetName()+ " " << raise << " 레이즈 | -" << raise + (entry / 2) << endl << endl;
		BetFromPlayer(player, raise + (entry / 2));
	}
	else if (choice == 2) // 콜
	{
		
		BetFromPlayer(player, entry / 2);
		cout << player.GetName() << " 콜 | -" << entry / 2 << endl << endl;
	}
	else if (choice == 3) // 다이
	{
		cout << player.GetName() << " 다이" << endl << endl;
		return true;
	}

	cout << "딜러 결정중 ...." << endl << endl << endl;

	

	cout << "현재 베팅액 : " << pot << endl << endl;
	cout << "----------------------------------------------------------------" << endl << endl << endl;

	return false;
}

bool Game::DefaultBet()
{
	cout << "[베팅 타임]" << endl << endl;

	cout << "플레이어의 차례" << endl;
	cout << "1_ 레이즈  2_ 콜  3_ 다이" << endl << endl;

	int choice = 0;

	cin >> choice;




	return false;
}

void Game::DealerDecision()
{

}

void Game::Round()
{
	

	int round = 0;
	while (dealer.GetMoney()>0)
	{
		system("cls");

		if (CheckPlayerMoney())
		{
			cout << "게임 오버! 플레이어가 파산했습니다...." << endl << endl;
			_getch();
			return;
		}

		round++;

		cout << round << " 라운드" << endl << endl;

		StartNewRound();

		ShowGameState();
		if (FirstBet())
		{
			cout << "플레이어의 다이, 다음 라운드로 넘어갑니다." << endl;
			_getch();
			continue;
		}
		_getch();
		// 1차 베팅

		DealCommunityCard(3);

		ShowGameState();

		_getch();
		// 족보 확인

		// 2차 베팅

		DealCommunityCard(1);
		
		ShowGameState();

		_getch();
		// 족보 확인

		// 3차 베팅

		DealCommunityCard(1);
		
		ShowGameState();

		_getch();
		// 족보 확인

		// 라스트 베팅

		// 쇼다운
		
		// 우위 확인

		// 상금 수령

		// 딜러 소지금 확인 
	}
	

}
