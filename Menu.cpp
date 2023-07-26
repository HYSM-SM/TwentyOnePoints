#include "Menu.h"

void MenuCommands::exitFromSubMenu()
{
    std::cout << "\n1)Back to main menu" << std::endl;
    while(InputProcessing::getInteger() != 1);
}

int Play::execute()
{
    return PLAY;
}
  
int Info::execute()
{
    std::cout << "Card cost:" << std::endl;
    for(auto cost: card_cost)
        std::cout << cost << std::endl;
    exitFromSubMenu();
    return INFO;
}

int ShowTableOfWinners::execute()
{
    std::cout << "Name-Record" << std::endl;
    TableWinners::show();
    exitFromSubMenu();
    return SHOW_TABLE_OF_WINNERS;
}

int Exit::execute()
{
    std::cout << "GoodBye" << std::endl;
    return EXIT;
}

void Menu::showMenuCommands() 
{
    for(int i = 0; i < s_commands.size(); i++)
        std::cout << i + 1 << ")" << s_commands[i] << std::endl;
}

int Menu::run()
{
    system("clear");
    showMenuCommands();
    int selected_command = InputProcessing::getInteger();
    selected_command--;
    if(selected_command >= 0 && selected_command < p_commands.size())
    {
        system("clear");
        return p_commands[selected_command]->execute();
    }
    return MAIN_MENU_WORKING;
}
