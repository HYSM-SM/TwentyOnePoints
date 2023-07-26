#include "Dealer.h"

void Dealer::clearSumCardsAmount()
{
    sum_cards_amount = 0;
}
    
void Dealer::getCard()
{
    std::pair<Card,int> card = cards.back();
    sum_cards_amount += card.second;
    cards.pop_back();
    cards_per_round.push_back(card);
}
    
bool Dealer::isEnoughCards()
{
    if(sum_cards_amount >= MAX_COST)
        return true;
    else if(sum_cards_amount >= SAFE_COST_LIMIT)
    {
	int need_cost = MAX_COST - sum_cards_amount;
	for(auto el: cards)
	{
		if(el.second <= need_cost)
			return false;
	}
        return true;
    }
    return false;
}
    
std::pair<Card,int> Dealer::passOutCard()
{
    std::pair<Card,int> card = cards.back();
    cards.pop_back();
    return card;
}
    
void Dealer::pickUpCards(std::vector<std::pair<Card,int>> player_cards)
{
    for(auto card: player_cards)
        cards.push_back(card);
            
    for(auto card: cards_per_round)
        cards.push_back(card);
           
    cards_per_round.clear();
}
    
void Dealer::shuffleCards()
{
     long long seed;
     int amount_shuffle = 1 + rand() % (10 - 1);
     for(int i = 0; i < amount_shuffle; i++)
     {
        seed = rand();
        std::shuffle(cards.begin(),cards.end(), std::default_random_engine(seed));
     }
}
    
int Dealer::getWinner(int player_cost)
{
    std::cout << "\nplayer cost: " << player_cost << " dealer cost: " << sum_cards_amount << std::endl;
    if(player_cost > MAX_COST)
        return DEALER;
    else if(sum_cards_amount > MAX_COST)
        return PLAYER;
    else if(sum_cards_amount == player_cost)
	return NOBODY;
    int winner = player_cost > sum_cards_amount ? PLAYER : DEALER;
    return winner;
}
    
std::vector<std::pair<Card,int>> Dealer::getCards()
{
    return cards_per_round;
}
