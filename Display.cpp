#include "Display.h"  

void Display::showCardsOnePlayer(std::vector<std::pair<Card,int>> cards,int x,int y,int card_height)
{
    int card_width = cards[0].first.getWidth();
    for(int i = 0; i < cards.size(); i++)
    {
        for(auto line: cards[i].first.getAppearance())
        {
            Cursor::move(x,y++);
            std::cout << line;;
        }
        x = card_width * (i + 1);
        y = card_height;
    }
}
    
void Display::showCardsTwoPlayers(std::vector<std::pair<Card,int>> player_cards,std::vector<std::pair<Card,int>> dealer_cards)
{
    int card_height = 1,x = 0,y = 1;
    std::cout << "Player:";
    showCardsOnePlayer(player_cards,x,y,card_height);
    std::cout << "\nDealer";
    card_height = player_cards[0].first.getHeight() + 2;
    y = card_height;
    x = 0;
    showCardsOnePlayer(dealer_cards,x,y,card_height);
}
