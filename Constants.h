#pragma once

#include <string>

enum MenuCode {MAIN_MENU_WORKING,PLAY,INFO,SHOW_TABLE_OF_WINNERS,EXIT};
enum Winner {PLAYER,DEALER,NOBODY};
const int MAX_COST = 21;
const int MAX_RECORDS = 10;
const int PLAYER_LIFE = 3;
const int SAFE_COST_LIMIT = 15;
static std::string DB_NAME = "Winners";
static std::string DB_TABLE_NAME = "Records";
