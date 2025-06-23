#include "UsingLibrary.h"
#include "Player.h"
#include "Game.h"



int main()
{
    srand((unsigned int)time(NULL));
    Deck deck;
    Card init(CLOVER, TWO);
    Player player("플레이어",3000);
    Player dealer("딜러", 15000);
    Game gameManager(player, dealer);

    gameManager.Round();

    

}
