#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <random>
#include <ctime>
#include "Card.h"
#include "Constants.h"

class Dealer
{
    private:
    
    std::vector<std::pair<Card,int>> cards = 
    {
        { Card("J"),2 },{ Card("Q"),3  },{ Card("K"),4  },
        { Card("6"),6 },{ Card("7"),7  },{ Card("8"),8  },
        { Card("9"),9 },{ Card("T"),10 },{ Card("A"),11 }
    };
    
    std::vector<std::pair<Card,int>> cards_per_round;
    
    int sum_cards_amount = 0;
    
    public:

    inline Dealer()
    {
	    srand(time(NULL));
    }
    
    void clearSumCardsAmount();
    
    void getCard();
    
    bool isEnoughCards();
    
    std::pair<Card,int> passOutCard();
    
    void pickUpCards(std::vector<std::pair<Card,int>> player_cards);
    
    void shuffleCards();
    
    int getWinner(int player_cost);
    
    std::vector<std::pair<Card,int>> getCards();
};
