#include "Player.h"
    
int Player::getCost()
{
    return sum_cards_amount;
}
    
std::vector<std::pair<Card,int>> Player::getCards()
{
    return cards;
}
    
bool Player::isEnoughCards()
{
    if(cards.size() == 0)
        return false;
    char ans;
    std::cout << "\nstop receiving cards?(y/n)\n>";
    do
    {
        ans = InputProcessing::getChar();
    }
    while(ans != 'y' && ans != 'n');

    if(sum_cards_amount >= MAX_COST)
        return true;
    return ans == 'y' ? true : false ;
}
    
void Player::receiveCard(std::pair<Card,int> card)
{
    sum_cards_amount += card.second;
    cards.push_back(card);
}
    
void Player::clearSumCardsAmount()
{
    sum_cards_amount = 0;
}
    
std::vector<std::pair<Card,int>> Player::returnCards()
{
    std::vector<std::pair<Card,int>> copy = cards;
    cards.clear();
    return copy;
}
