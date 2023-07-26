#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include "Card.h"

class Cursor
{
    public:
    inline static void move(int x,int y) 
    { 
        std::cout << "\033[" << y + 1 << ";" << x + 1 << "H"; 
    }
};

class Display
{
    public:
    
    static void showCardsOnePlayer(std::vector<std::pair<Card,int>> cards,int x = 0,int y = 0,int card_height = 0);
    
    static void showCardsTwoPlayers(std::vector<std::pair<Card,int>> player_cards,std::vector<std::pair<Card,int>> dealer_cards);
};
