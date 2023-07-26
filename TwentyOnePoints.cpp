#include "TwentyOnePoints.h"

void TwentyOnePoints::startGame()
{
    srand(time(NULL));
        
    char play = 'y';
    bool player_want_play = true;
    int menu_code = MAIN_MENU_WORKING;
    int player_life = PLAYER_LIFE;
    int rounds = 0;
    int round_winner = NOBODY;
    std::string player_name;
    while(menu_code != EXIT)
    {
        menu_code = MAIN_MENU_WORKING;
        player_want_play = true; 
        player_life = PLAYER_LIFE;
        rounds = 0;
        while(menu_code != PLAY)
        {
            menu_code = main_menu.run();
            if(menu_code == EXIT) 
		    return;
        }
        while(player_want_play && player_life != 0)
        {
	    game_table.startRound();
	    round_winner = game_table.getWinner();
	    if(round_winner == DEALER)
	    {
		    player_life--;
	    }
	    else if(round_winner == PLAYER)
	    {
		    player_life++;
	    }
            std::cout << "player life: " << player_life << " rounds: " << ++rounds <<  "\nPlay another round?(y/n)\n>";
	    do
	    {
            	play = InputProcessing::getChar();
	    }
	    while(play != 'y' && play != 'n');
            player_want_play = play == 'y' ? true : false ;
        }
	std::cout << "Enter name:\n";
	std::cin >> player_name;
	if(TableWinners::tableNotFilled())
	{
        	TableWinners::add(player_name,rounds);
	}
	else
	{
		TableWinners::changeWinner(player_name,rounds);
	}
    }
}
