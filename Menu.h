#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "InputProcessing.h"
#include "TableWinners.h"
#include "Constants.h"

class Commands
{
    public:
    
    virtual int execute() = 0;
};

class MenuCommands: public Commands
{
    public :
    
    void exitFromSubMenu();
};

class Play: public MenuCommands
{
    public:

    int execute() override;
};

class Info: public MenuCommands
{
    private:
    
    std::vector<std::string> card_cost = {"J - 2\nQ - 3\nK - 4\nT - 10\nA - 11\nThe rest of the cards correspond to their face value."};
    
    public:

    int execute() override;
};

class ShowTableOfWinners: public MenuCommands
{
    public:

    int execute() override;
};

class Exit: public MenuCommands
{
    public:

    int execute() override;
};

class Menu
{
    private:

    std::vector<MenuCommands*> p_commands = {new Play,new Info, new ShowTableOfWinners,new Exit};
    std::vector<std::string> s_commands = {"Play","Info","Table of winners","Exit"};

    void showMenuCommands();
    

    public:

    int run();
};
