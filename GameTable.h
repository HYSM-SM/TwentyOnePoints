#pragma once

#include <iostream>
#include <utility>
#include <string>
#include "Dealer.h"
#include "Player.h"
#include "Display.h"
#include "Constants.h"

class GameTable
{
    private:
    
    Dealer dealer;
    Player player;
    int winner;
    
    public:

    GameTable()
    {
	    winner = NOBODY;
    }
    
    void startRound();

    int getWinner();
};
