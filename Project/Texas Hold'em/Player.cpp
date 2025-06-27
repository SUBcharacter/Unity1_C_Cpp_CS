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
    system("cls");
    hand.reserve(3);
    highCard.reserve(7);
    handRank = NONE;
    
    name = SetName();

}

string Player::SetName()
{
    ShowCursor();
    GotoXY(75, 4);
    cout << R"(
                                
                            _   __                        _____      __  __  _            
                           / | / /___ _____ ___  ___     / ___/___  / /_/ /_(_)___  ____ _
                          /  |/ / __ `/ __ `__ \/ _ \    \__ \/ _ \/ __/ __/ / __ \/ __ `/
                         / /|  / /_/ / / / / / /  __/   ___/ /  __/ /_/ /_/ / / / / /_/ / 
                        /_/ |_/\__,_/_/ /_/ /_/\___/   /____/\___/\__/\__/_/_/ /_/\__, /  
                                                                                 /____/   
                        
        )";

    string name;
    while (true)
    {
        GotoXY(30, 14);
        cout << "플레이어의 이름을 설정해 주세요. : ";

        getline(cin, name);

        if (!name.empty())
        {
            HideCursor();
            return name;
        }
        else
        {
            GotoXY(30, 14);
            cout << "                                  ";
        }
    }
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

void Player::ShowHand(int x, int y)
{
    int X = x;
    for (int i = 0; i < hand.size(); i++)
    {
        hand[i].PrintCard(X, y);
        X += 8;
    }
}

void Player::ShowHighRank()
{
    cout << "<" << name << ">" << "[" << GetStringHandRank() << "]\n\n";
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


