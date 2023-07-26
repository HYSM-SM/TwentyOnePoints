#pragma once

#include <iostream>
#include "Menu.h"
#include "GameTable.h"
#include "TableWinners.h"
#include "Constants.h"
#include "InputProcessing.h"

class TwentyOnePoints
{
    private:
    
    Menu main_menu;
    GameTable game_table;
    
    public:

    void startGame();
};
