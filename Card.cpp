#include "Card.h"

int Card::getWidth()
{
    return appearance[1].size();
}
    
int Card::getHeight()
{
    return appearance.size();
}
    
Card::Card(std::string cost)
{
    int first_row_cost  = 1;
    int second_row_cost = appearance.size() - 2;
    int first_column_cost  =  1;
    int second_column_cost = appearance[second_row_cost].size() - 1;
    appearance[first_row_cost].insert(first_column_cost,cost);
    appearance[second_row_cost].insert(second_column_cost,cost);
}
    
std::vector<std::string> Card::getAppearance()
{
    return appearance;
}
