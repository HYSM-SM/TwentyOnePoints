#pragma once

#include <iostream>
#include <algorithm>
#include <string>

class InputProcessing
{
    public:

    static char getChar()
    {
        std::string input;
	std::cin >> input;
	input.resize(1);
	return input[0];
    }
    
    static int getInteger()
    {
        std::string input;
        std::cin >> input;
        auto p_end = std::remove_if(input.begin(),input.end(),[](char ch){ return ch < '0' || ch > '9'; });
        input.erase(p_end,input.end());
        int numb = -1;// -1 error code
        if(input.size() > 0 && input.size() < 10)
             numb = std::stoi(input);
        return numb;
    }
};
