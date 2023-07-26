#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <utility>
#include "Constants.h"

class DataBase
{
    private:
    
    sqlite3* db;

    void executeRequest(std::string request);
    
    public:
    
    DataBase();
    
    void addToDataBase(std::string name,int records);

    std::vector<std::pair<std::string,std::string>> getContents();

    sqlite3* getSQL();

    void deleteDublicate(int number);

    void remove(std::pair<std::string,std::string> record);
    
    ~DataBase();
};

class TableWinners
{
    private:
    
    static DataBase db;
    
    public:
    
    static void show();
    
    static void add(std::string name,int records);

    static void changeWinner(std::string name,int records);

    static bool tableNotFilled();
};
