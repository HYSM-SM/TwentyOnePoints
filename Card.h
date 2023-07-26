#pragma once

#include <vector>
#include <string>

class Card
{
    private:
    std::vector<std::string> appearance =     
    {
      " ----------- ",
      "|          |",
      "|           |",
      "|           |",
      "|           |",
      "|           |",
      "|           |",
      "|          |",
      " ----------- ",
    };
    
    public:
    
    int getWidth();
    
    int getHeight();
    
    Card(std::string cost);
    
    std::vector<std::string> getAppearance();
};
