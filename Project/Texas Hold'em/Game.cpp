#include "Game.h"

int Game::Input()
{
	int input = 0;

	while (true)
	{
		cin >> input;
		if (input < 1 || input >3)
		{
			cout << "잘못된 입력입니다. 다시 시도 하십시오.\n\n";
			_getch();
		}
		else
			break;
	}


	return input;
}

void Game::StartNewRound()
{
	pot = 0;
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
	PlayerCard();
}

void Game::ShowCommunityCard()
{
	cout << "커뮤니티 카드" << endl << endl;
	for (int i = 0; i < communityCard.size(); i++)
	{
		cout << communityCard[i].GetCardString() << "  ";
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
	ShowPlayerCard();
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
	cout << "[스타트 베팅]" << endl << endl;

	BetFromPlayer(player, entry / 2);
	BetFromPlayer(dealer, entry);
	cout << "플레이어의 차례" << endl;
	cout << "1_ 레이즈  2_ 콜  3_ 다이" << endl << endl;
	int choice = 0;

	choice = Input();

	if (choice == 1) // 레이즈
	{
		actPlayer = RAISE;
		cout << "레이즈 금액을 입력해 주십시오. 현재 소지금 : " << player.GetMoney() << endl << endl;

		int raise = 0;
		cin >> raise;
		bettingPlayer = raise + entry;
		cout << player.GetName()+ " " << raise << " 레이즈 | -" << raise + (entry / 2) << endl << endl;
		BetFromPlayer(player, raise + (entry / 2));
	}
	else if (choice == 2) // 콜
	{
		actPlayer = CALL;
		BetFromPlayer(player, entry / 2);
		cout << player.GetName() << " 콜 | -" << entry / 2 << endl << endl;
	}
	else if (choice == 3) // 다이
	{
		actPlayer = DIE;
		cout << player.GetName() << " 다이" << endl << endl;
	}

	DealerDecision(actPlayer,entry);

	cout << "현재 베팅액 : " << pot << endl << endl;
	cout << "----------------------------------------------------------------" << endl << endl << endl;

}

void Game::DefaultBet()
{

	if(isAllin)
	{
		return;
	}

	bettingDealer = 0;
	bettingPlayer = 0;

	cout << "[베팅 타임]" << endl << endl;

	cout << "플레이어의 차례" << endl;
	cout << "1_ 레이즈  2_ 체크  3_ 다이" << endl << endl;

	int choice = 0;

	choice = Input();

	if (choice == 1) // 레이즈
	{
		actPlayer = RAISE;
		cout << "레이즈 금액을 입력해 주십시오. 현재 소지금 : " << player.GetMoney() << endl << endl;

		int raise = 0;
		cin >> raise;
		bettingPlayer = raise;
		cout << player.GetName() + " " << raise << " 레이즈 | -" << raise << endl << endl;
		BetFromPlayer(player, raise);
	}
	else if (choice == 2) // 체크
	{
		actPlayer = CHECK;
		cout << player.GetName() << " 체크! 당신은 천천히 생각해보기로 했습니다. \n\n";
	}
	else if (choice == 3) // 다이
	{
		actPlayer = DIE;
		cout << player.GetName() << " 다이" << endl << endl;
	}

	DealerDecision(actPlayer);
		
	cout << "현재 베팅액 : " << pot << endl << endl;
	cout << "----------------------------------------------------------------" << endl << endl << endl;
}

void Game::DealerDecision(Acting actPlayer, int entry)
{
	if (actPlayer == DIE)
	{
		return;
	}

	cout << "딜러 결정중 ...." << endl << endl << endl;

	Sleep(1000);

	int dealerChoice = (rand() % 2) + 1;
	switch (actPlayer)
	{
	case RAISE:
		if (dealerChoice == 1) // 콜
		{
			actDealer = CALL;
			BetFromPlayer(dealer, bettingPlayer - entry);// raise 금액 만큼 더 베팅
			cout << "딜러 콜! 콜 금액 : " << bettingPlayer - entry << endl << endl;
		}
		else if (dealerChoice == 2) // 다이
		{
			actDealer = DIE;
			return;
		}
		break;
	case CALL :
		if (dealerChoice == 1) // 체크
		{
			actDealer = CHECK;
			cout << "딜러 체크!" << endl << endl;
		}
		else if (dealerChoice == 2) // 다이
		{
			actDealer = DIE;
			return;
		}
		break;
	case CHECK:
		actDealer = CHECK;
		cout << "딜러 체크!\n\n";
		break;
	}
}

bool Game::DecisionCheck()
{
	if (actPlayer == DIE)
	{
		dealer.ChangeMoney(pot);
		cout << player.GetName() << " 다이.... 딜러가 상금을 수령합니다.\n\n";
	}
	else if(actDealer == DIE)
	{
		player.ChangeMoney(pot);
		cout << "딜러 다이! 상금을 수령합니다!  상금 : " << pot << endl << endl;
	}
	else
	{
		actPlayer = DEFAULT;
		actDealer = DEFAULT;
		return false;
	}

	actPlayer = DEFAULT;
	actDealer = DEFAULT;
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
	dealerCard.insert(dealerCard.end(), player.GetHand().begin(), player.GetHand().end());

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

void Game::EvaluateCard(Player& p, vector<Card> playerCard)
{
#pragma region 하이 카드
	{
		for (auto& card : playerCard)
		{
			if (card.FromHand())
			{
				p.SetHR(HIGHCARD);
				p.SetHC(card);
			}
		}
	}
#pragma endregion

#pragma region 원 페어 & 투 페어

	{
		map<Number, vector<Card>> numMap;

		for (auto& card : playerCard)
		{
			numMap[card.GetNumber()].push_back(card);
		}

		int pairCount = 0;
		vector<Number> pairNum;
		for (auto& [num, cards] : numMap)
		{
			if (cards.size() == 2)
			{
				pairNum.push_back(num);
			}
		}
		sort(pairNum.begin(), pairNum.end());
		
		if (!pairNum.empty())
		{
			pairCount = pairNum.size();
		
			if (pairCount == 1)
			{
				p.SetHR(ONEPAIR);
		
				vector<Card> pairCard =numMap[pairNum[0]];
				
				sort(pairCard.begin(), pairCard.end());
				
				vector<Card> handPairCard;
				
				for (auto& card : pairCard)
				{
					if (card.FromHand())
					{
						handPairCard.push_back(card);
					}
				}

				if (!handPairCard.empty())
				{
					sort(handPairCard.begin(), handPairCard.end());
					p.SetHC(handPairCard.back());
				}
				else
				{
					p.SetHC(pairCard.back());
				}
			}
			else if (pairCount >= 2)
			{
				p.SetHR(TWOPAIR);

				vector<Card> pairCards;

				for (int i = pairNum.size()-2; i < pairNum.size(); i++)
				{
					Number num = pairNum[i];
					
					vector<Card> handPairCard;
					vector<Card> pairCard;
					for (auto& card : numMap[num])
					{
						pairCard.push_back(card);
					}
					sort(pairCard.begin(), pairCard.end());
					for (auto& card : pairCard)
					{
						if (card.FromHand())
						{
							handPairCard.push_back(card);
						}
					}
					if (!handPairCard.empty())
					{
						sort(handPairCard.begin(), handPairCard.end());
						pairCards.push_back(handPairCard.back());
					}
					else
					{
						pairCards.push_back(pairCard.back());
					}
				}
				p.SetHC(pairCards);
			}
		}

	}

#pragma endregion

#pragma region 트리플

	{
		map<Number, vector<Card>> numMap;

		for (auto& card : playerCard)
		{
			numMap[card.GetNumber()].push_back(card);
		}

		vector<Number> triNum;
		for (auto& [num, card] : numMap)
		{
			if (card.size() == 3)
			{
				triNum.push_back(num);
			}
		}

		if (triNum.size() == 1)
		{
			p.SetHR(TRIPLE);

			vector<Card> triCards;

			for (auto& num : triNum)
			{
				for (auto& card : numMap[num])
				{
					triCards.push_back(card);
				}
			}
			vector<Card> handCard;
			for (auto& card : triCards)
			{
				if (card.FromHand())
				{
					handCard.push_back(card);
				}
			}
			if (!handCard.empty())
			{
				sort(handCard.begin(), handCard.end());
				p.SetHC(handCard.back());
			}
			else
			{
				sort(triCards.begin(), triCards.end());
				p.SetHC(triCards.back());
			}
		}
	}

#pragma endregion


#pragma region 스트레이트
	{
		int combo = 1;

		for (int i = 1; i < playerCard.size(); i++)
		{

			if (playerCard[i].GetNumber() == playerCard[i - 1].GetNumber())
			{
				continue;
			}

			if (playerCard[i].GetNumber() == playerCard[i - 1].GetNumber() + 1)
			{
				combo++;
				p.SetHC(playerCard[i-1]);
				if (combo >= 5)
				{
					p.SetHR(STRAIGHT);
				}
			}
			else
			{
				combo = 1;
				p.ClearHC();
			}
		}
	}
#pragma endregion

#pragma region 플러쉬
	{
		map<Mark, vector<Card>> markMap;

		for (int i = 0; i < playerCard.size(); i++)
		{
			markMap[playerCard[i].GetMark()].push_back(playerCard[i]);
		}

		for (auto& [mark, cards] : markMap)
		{
			if (cards.size() >= 5)
			{
				sort(cards.begin(), cards.end());
				p.SetHR(FLUSH);
				p.SetHC(cards.back());
				break;
			}
		}
	}
#pragma endregion



#pragma region 스트레이트 플러쉬

	{
		map<Mark, vector<Card>> markMap;

		for (int i = 0; i < playerCard.size(); i++)
		{
			markMap[playerCard[i].GetMark()].push_back(playerCard[i]);
		}

		for (auto& [mark, cards] : markMap)
		{
			if (cards.size() < 5)
				continue;

			sort(cards.begin(), cards.end());

			int combo = 1;

			for (int i = 1; i < cards.size(); i++)
			{
				if (cards[i].GetNumber() == cards[i - 1].GetNumber())
				{
					continue;
				}

				if (cards[i].GetNumber() == cards[i - 1].GetNumber() + 1)
				{
					combo++;
					if (combo >= 5)
					{
						p.SetHR(STRAIGHTFLUSH);
						p.SetHC(cards[i]);
						
					}
				}
				else
				{
					combo = 1;
				}
			}
		}
	}

#pragma endregion

#pragma region 로티플

	{
		map<Mark, vector<Card>> markMap;

		for (int i = 0; i < playerCard.size(); i++)
		{
			markMap[playerCard[i].GetMark()].push_back(playerCard[i]);
		}

		for (auto& [mark, cards] : markMap)
		{
			if (cards.size() < 5)
			{
				continue;
			}

			sort(cards.begin(), cards.end());

			vector<Number> royalNum = { TEN,J,Q,K,A };

			int combo = 0;

			for (auto& c : cards)
			{
				if (c.GetNumber() == royalNum[combo])
				{
					combo++;
				}
				else if (c.GetNumber() > royalNum[combo])
					break;

				if (combo == 5)
				{
					p.SetHR(ROYALSTRAIGHTFLUSH);
					p.SetHC(Card(mark, A, true));
					break;
				}

				if (combo == 5)
					break;
			}
		}
	}

#pragma endregion



}



void Game::Round()
{
	

	int round = 0;
	while (dealer.GetMoney()>0) // 딜러 소지금 확인
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

		// 1차 베팅
		FirstBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		

		DealCommunityCard(3);

		ShowGameState();

		// 족보 확인

		// 2차 베팅
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState();

		// 족보 확인
		
		// 3차 베팅
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState();

		// 족보 확인

		// 라스트 베팅
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		
		// 쇼다운

		ShowGameState(true);
		
		// 우위 확인

		_getch();

		// 상금 수령



		// 딜러 소지금 확인 
	}
	

}
