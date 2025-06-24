#include "Player.h"

Player::Player()
{
    hand.reserve(2);
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
    if (card.FromHand())
    {
        highCard = card;
    }
    else
        return;
}

Card Player::GetHC()
{
    return highCard;
}


