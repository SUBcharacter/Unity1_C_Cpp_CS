#include "UsingLibrary.h"
#include "Player.h"
int main()
{
    Deck deck;
    Player player("플레이어",3000);
    Player dealer("딜러", 15000);
    deck.ShuffleDeck();

    player.AddCard(deck.DrawCard());
    dealer.AddCard(deck.DrawCard());
    player.AddCard(deck.DrawCard());
    dealer.AddCard(deck.DrawCard());

    player.ShowHand();
    dealer.ShowHand();

}
