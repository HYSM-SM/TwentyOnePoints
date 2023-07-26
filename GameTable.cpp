#include "GameTable.h"
  
void GameTable::startRound()
{
    dealer.shuffleCards();
    while(!player.isEnoughCards())
    {
        std::pair<Card,int> player_card = dealer.passOutCard();
        player.receiveCard(player_card);
        system("clear");
        Display::showCardsOnePlayer(player.getCards());
    }
      
    while(!dealer.isEnoughCards())
    {
        dealer.getCard();
    }
        
    system("clear");
    Display::showCardsTwoPlayers(player.getCards(),dealer.getCards());
        
    dealer.pickUpCards(player.returnCards());
    winner =  dealer.getWinner(player.getCost());
    player.clearSumCardsAmount();
    dealer.clearSumCardsAmount();
}

int GameTable::getWinner()
{
    int win = winner;
    winner = NOBODY;
    return win;
}
