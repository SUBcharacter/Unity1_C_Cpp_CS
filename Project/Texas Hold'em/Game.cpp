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

void Game::FirstBet()
{
	cout << "[퍼스트 베팅]" << endl << endl;



}

void Game::Round()
{
	int round = 0;
	while (dealer.GetMoney()>0)
	{
		round++;

		cout << round << " 라운드" << endl << endl;

		StartNewRound();

		ShowGameState();

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
