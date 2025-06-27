#include "EvaluateManager.h"

void EvaluateCard(Player& p, vector<Card> playerCard)
{
	if (RSF(p, playerCard)) return;
	if (SF(p, playerCard)) return;
	if (FC(p, playerCard)) return;
	if (FH(p, playerCard)) return;
	if (FL(p, playerCard)) return;
	if (STR(p, playerCard)) return;
	if (TRI(p, playerCard)) return;
	if (OTP(p, playerCard)) return;
	if (HC(p, playerCard)) return;
}

bool RSF(Player& p, vector<Card> playerCard)
{
#pragma region 로티플

	{
		map<Mark, vector<Card>> markMap;

		for (auto& card : playerCard)
		{
			markMap[card.GetMark()].push_back(card);
		}

		for (auto& [mark, cards] : markMap)
		{
			if (cards.size() < 5)
				continue;

			sort(cards.begin(), cards.end());

			vector<Number> royalNum = { TEN,J,Q,K,A };
			vector<Card> highCards;

			int combo = 0;

			for (auto& c : cards)
			{
				if (c.GetNumber() == royalNum[combo])
				{
					combo++;
					highCards.push_back(c);
				}
				else if (c.GetNumber() > royalNum[combo])
				{
					break;
				}
			}
			if (highCards.size() == 5)
			{
				sort(highCards.begin(), highCards.end());
				p.SetHR(ROYALSTRAIGHTFLUSH);
				p.SetHC(highCards); // 로티플 카드 5장 오름차순
				return true;
			}
		}
		return false;
	}

#pragma endregion
}

bool SF(Player& p, vector<Card> playerCard)
{
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

			vector<Card> highCards;

			vector<Card> straightFlushCards;
			straightFlushCards.push_back(cards[0]);
			for (int i = 1; i < cards.size(); i++)
			{
				if (cards[i].GetNumber() == cards[i - 1].GetNumber())
				{
					continue;
				}

				if (cards[i].GetNumber() == cards[i - 1].GetNumber() + 1)
				{
					straightFlushCards.push_back(cards[i]);
				}
				else
				{
					straightFlushCards.clear();
					straightFlushCards.push_back(cards[i]);
				}
			}
			if (straightFlushCards.size() >= 5)
			{
				sort(straightFlushCards.begin(), straightFlushCards.end());
				highCards.insert(highCards.end(), straightFlushCards.end() - 5, straightFlushCards.end());
				p.SetHR(STRAIGHTFLUSH);
				p.SetHC(highCards); // 최상 스티플 5장 오름차순
				return true;
			}
		}
		return false;
	}

#pragma endregion
}

bool FC(Player& p, vector<Card> playerCard)
{
#pragma region 포카드

	{
		map<Number, vector<Card>> numMap;

		for (auto& cards : playerCard)
		{
			numMap[cards.GetNumber()].push_back(cards);
		}

		vector<Number> fourNum;
		for (auto& [num, cards] : numMap)
		{
			if (cards.size() == 4)
			{
				fourNum.push_back(num);
			}
		}

		if (fourNum.size() == 1)
		{
			vector<Card>& fourCards = numMap[fourNum[0]];
			vector<Card> highCards;

			sort(fourCards.begin(), fourCards.end());

			highCards.push_back(fourCards.back());

			vector<Card> kickers;
			for (auto& card : playerCard)
			{
				if (card.GetNumber() != fourNum[0])
				{
					kickers.push_back(card);
				}
			}
			sort(kickers.begin(), kickers.end());

			highCards.push_back(kickers.back());

			p.SetHR(FOURCARD);
			p.SetHC(highCards); // { 포카드 카드 , 킥커 }
			return true;
		}
		else
		{
			return false;
		}
	}

#pragma endregion
}

bool FH(Player& p, vector<Card> playerCard)
{
#pragma region 풀 하우스

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

		sort(triNum.begin(), triNum.end());

		if (triNum.size() == 1)
		{
			vector<Card>& triCard = numMap[triNum[0]];
			vector<Card> highCards;
			sort(triCard.begin(), triCard.end());

			highCards.push_back(triCard.back());

			vector<Number> pairNum;
			for (auto& [num, card] : numMap)
			{
				if (card.size() == 2 && num != triNum[0])
				{
					pairNum.push_back(num);
				}
			}
			sort(pairNum.begin(), pairNum.end());

			if (pairNum.size() == 1)
			{
				vector<Card>& pairCard = numMap[pairNum[0]];
				sort(pairCard.begin(), pairCard.end());

				highCards.push_back(pairCard.back());

				p.SetHR(FULLHOUSE);
				p.SetHC(highCards); // { 트리플 카드, 페어 카드}
				return true;
			}
			else if (pairNum.size() == 2)
			{
				vector<Card>& pairCard = numMap[pairNum[1]];
				sort(pairCard.begin(), pairCard.end());

				highCards.push_back(pairCard.back());

				p.SetHR(FULLHOUSE);
				p.SetHC(highCards); // { 트리플 카드, 페어 카드}
				return true;
			}
		}
		else if (triNum.size() == 2)
		{
			vector<Card> highCards;
			vector<Card>& triCard = numMap[triNum[1]];
			vector<Card>& pairCard = numMap[triNum[0]];

			sort(triCard.begin(), triCard.end());
			sort(pairCard.begin(), pairCard.end());

			highCards.push_back(triCard.back());
			highCards.push_back(pairCard.back());

			p.SetHR(FULLHOUSE);
			p.SetHC(highCards); // { 트리플 카드, 페어 카드 }
			return true;
		}
		else
		{
			return false;
		}
	}

#pragma endregion
}

bool FL(Player& p, vector<Card> playerCard)
{
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
				p.SetHR(FLUSH);
				sort(cards.begin(), cards.end());
				vector<Card> highFlush(cards.end() - 5, cards.end());
				p.SetHC(highFlush); // 플러쉬 최상위 5장 오름차순
				break;
			}
		}

		if (p.GetHR() == FLUSH)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
#pragma endregion
}

bool STR(Player& p, vector<Card> playerCard)
{
#pragma region 스트레이트
	{
		vector<Card> straightCards;
		straightCards.push_back(playerCard[0]);

		for (int i = 1; i < playerCard.size(); i++)
		{

			if (playerCard[i].GetNumber() == playerCard[i - 1].GetNumber())
			{
				continue;
			}

			if (playerCard[i].GetNumber() == playerCard[i - 1].GetNumber() + 1)
			{
				straightCards.push_back(playerCard[i]);
			}
			else
			{
				if (straightCards.size() >= 5)
				{
					break;
				}
				else
				{
					straightCards.clear();
					straightCards.push_back(playerCard[i]);
				}
				
			}
		}
		if (straightCards.size() >= 5)
		{
			sort(straightCards.begin(), straightCards.end());
			vector<Card> highStraightCards(straightCards.end() - 5, straightCards.end());
			p.SetHR(STRAIGHT);
			p.SetHC(highStraightCards); // 내 패의 최상위 스트레이트 카드 5장(오름차순)
			return true;
		}
		else
		{
			return false;
		}
	}
#pragma endregion
}

bool TRI(Player& p, vector<Card> playerCard)
{
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

			vector<Card>& triCards = numMap[triNum[0]];
			vector<Card> highCards;

			sort(triCards.begin(), triCards.end());
			highCards.push_back(triCards.back());

			vector<Card> kickers;

			for (auto& cards : playerCard)
			{
				if (cards.GetNumber() != triNum[0])
				{
					kickers.push_back(cards);
				}
			}
			sort(kickers.begin(), kickers.end());

			highCards.insert(highCards.end(), kickers.end() - 2, kickers.end());
			p.SetHC(highCards); // { 트리플 카드, 킥커1,킥커2}
			return true;
		}
		else
		{
		return false;
		}
	}

#pragma endregion
}

bool OTP(Player& p, vector<Card> playerCard)
{
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
		sort(pairNum.rbegin(), pairNum.rend());

		if (!pairNum.empty())
		{
			pairCount = pairNum.size();

			if (pairCount == 1)
			{
				p.SetHR(ONEPAIR);

				vector<Card> highCards;
				vector<Card>& pairCard = numMap[pairNum[0]];

				sort(pairCard.begin(), pairCard.end());

				highCards.push_back(pairCard.back());

				vector<Card> kickers;
				for (auto& cards : playerCard)
				{
					if (cards.GetNumber() != pairNum[0])
					{
						kickers.push_back(cards);
					}
				}
				sort(kickers.begin(), kickers.end());
				highCards.insert(highCards.end(), kickers.end() - 3, kickers.end());

				p.SetHC(highCards);
				return true;// { 원페어 카드, 킥커1, 킥커2, 킥커3 } 
			}
			else if (pairCount >= 2)
			{
				p.SetHR(TWOPAIR);

				vector<Card> highCards;

				for (int i = 0; i < 2; i++)
				{
					Number num = pairNum[i];

					vector<Card> pairCard;
					for (auto& card : numMap[num])
					{
						pairCard.push_back(card);
					}
					sort(pairCard.begin(), pairCard.end());

					highCards.push_back(pairCard.back());
				}

				vector<Card> kickers;
				for (auto& cards : playerCard)
				{
					if (pairNum[0] != cards.GetNumber())
					{
						if (pairNum[1] != cards.GetNumber())
						{
							kickers.push_back(cards);
						}
					}
				}
				sort(kickers.begin(), kickers.end());
				highCards.push_back(kickers.back());
				p.SetHC(highCards); // { 투페어 1위, 투페어 2위, 킥커 }
				return true;
			}
		}
		else
		{
			return false;
		}

	}

#pragma endregion
}

bool HC(Player& p, vector<Card> playerCard)
{
#pragma region 하이 카드
    {
        vector<Card> highCards(playerCard.end() - 5, playerCard.end());
        p.SetHR(HIGHCARD);
        p.SetHC(highCards); // 패 오름차순
        return true;
    }
#pragma endregion
}
