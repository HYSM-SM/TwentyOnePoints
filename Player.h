#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include "Card.h"
#include "Constants.h"
#include "InputProcessing.h"

class Player
{
    private:
    
    int sum_cards_amount = 0;
    std::vector<std::pair<Card,int>> cards;
    
    public:
    
    int getCost();
    
    std::vector<std::pair<Card,int>> getCards();
    
    bool isEnoughCards();
    
    void receiveCard(std::pair<Card,int> card);
    
    void clearSumCardsAmount();
    
    std::vector<std::pair<Card,int>> returnCards();
};
