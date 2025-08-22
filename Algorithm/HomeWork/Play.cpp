#include "Play.h"

void Play::DamageReport(Player& p, Card& c)
{
	int prevHP = p.getHealth();
	int damage = 0;
	switch (c.GetCardRank())
	{
	case ACE: damage = -20 * ((int)c.GetCardMark()); break;
	case KING: damage = -10 * ((int)c.GetCardMark()); break;
	case QUEEN: damage = -5 * ((int)c.GetCardMark()); break;
	case JACK: damage = -2 * ((int)c.GetCardMark()); break;
	default: break;
	}

	switch (c.GetCardRank())
	{
	case TEN: damage = 20; break;
	case NINE: damage = 15; break;
	case EIGHT: damage = 10; break;
	case SEVEN: damage = 5; break;
	default: break;
	}

	p.setHealth(p.getHealth() + damage);

	if (p.getHealth() > prevHP)
	{
		cout << "체력 회복!	:  " << damage << " 회복" << endl;
	}
	else if (p.getHealth() < prevHP)
	{
		cout << "딱밤 한대!	:  " << -damage << " 데미지" << endl;
	}
	else
	{
		cout << "아무 일도 일어나지 않았습니다...." << endl;
	}

	if (p.getHealth() <= 0)
	{
		cout << "현재 체력 : " << 0 << endl << endl;
	}
	else
	{
		cout << "현재 체력 : " << p.getHealth() << endl << endl;
	}
	
	
}

void Play::CheckCard(Player& p, Card& card)
{
	cout << "카드 확인중 ...." << endl;

	Sleep(500);

	DamageReport(p, card);
}


bool Play::CheckSomeOneDied()
{
	if (you.getHealth() < 0)
	{
		cout << "이마에 자국이 남았습니다... GAME OVER" << endl;
		_getch();
		return true;
	}
	else if (your_Friend.getHealth() < 0)
	{
		cout << "친구의 이마를 반갈죽 내버렸습니다ㅋㅋㅋ GAME OVER" << endl;
		_getch();
		return true;
	}
	else
		return false;
}

void Play::start()
{
	deck.ShuffleDeck();

	while (!CheckSomeOneDied())
	{
		system("cls");

		cout << "당신의 턴!" << endl;
		// 플레이어 턴
		
		// 드로우
		// 카드확인 및 데미지 계산
		CheckCard(you, deck.Draw());
		
		_getch();

		cout << "친구의 턴!" << endl;
		// 상대 턴

		// 드로우
		// 카드 확인 및 데미지 계산
		CheckCard(your_Friend, deck.Draw());

		_getch();
	}

}
