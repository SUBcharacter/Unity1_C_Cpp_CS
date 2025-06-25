#include "Player.h"

string Player::GetStringHandRank()
{
    switch (handRank)
    {
    case HIGHCARD:return "하이 카드"; break;
    case ONEPAIR:return "원 페어"; break;
    case TWOPAIR:return "투 페어"; break;
    case TRIPLE:return "트리플"; break;
    case STRAIGHT:return "스트레이트"; break;
    case FLUSH:return "플러쉬"; break;
    case FULLHOUSE:return "풀 하우스"; break;
    case FOURCARD:return "포 카드"; break;
    case STRAIGHTFLUSH:return "스트레이트 플러쉬"; break;
    case ROYALSTRAIGHTFLUSH:return "로얄 스트레이트 플러쉬"; break;
    }
}

Player::Player()
{
    hand.reserve(3);
    highCard.reserve(7);
    handRank = NONE;
    name = SetName();

}

string Player::SetName()
{
    cout << "플레이어의 이름을 설정해 주세요." << endl << endl;

    string name;
    cin >> name;

    return name;
}

void Player::SetMoney(int seedMoney)
{
    money = seedMoney;
}

void Player::AddCard(Card card)
{
    hand.push_back(card);
}

void Player::ClearHand()
{
    hand.clear();
}

void Player::ShowHand()
{
    cout << name << " 패" << endl << endl;
    for (int i = 0; i < hand.size(); i++)
    {
        cout << hand[i].GetCardString() << "  ";
    }
    cout << endl << endl;
}

void Player::ShowHighCard()
{
    cout << "<" << name << ">" << "[" << GetStringHandRank() << "]\n\n";
    for (auto& card : highCard)
    {
        cout << card.GetCardString() << "  ";
    }
    cout << endl << endl << endl;
}

void Player::ChangeMoney(int chip)
{
    money += chip;
}

void Player::SetHR(HandRank hr)
{
    handRank = hr;
}

void Player::SetHC(const Card& card)
{
    highCard.clear();
    highCard.push_back(card);
    sort(highCard.begin(), highCard.end());
}

void Player::SetHC(const vector<Card>& card)
{
    highCard.clear();
    highCard = card;
    sort(highCard.begin(), highCard.end());
}

void Player::ClearHC()
{
    highCard.clear();
}

vector<Card> Player::GetHC()
{
    return highCard;
}


