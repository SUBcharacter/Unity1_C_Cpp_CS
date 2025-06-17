#include "UsingLibrary.h"
#include "Player.h"
#include "Game.h"
int main()
{
    Deck deck;
    Player player("플레이어",3000);
    Player dealer("딜러", 15000);
    Game gameManager(player, dealer);

    gameManager.Round();

    

}
