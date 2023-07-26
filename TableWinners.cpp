#include "TableWinners.h"

DataBase TableWinners::db;

void DataBase::executeRequest(std::string request)
{
    char* ErrMsg;
    sqlite3_exec(db,request.c_str(),NULL,0,&ErrMsg);
    sqlite3_free(ErrMsg);
}
    
DataBase::DataBase()
{
    std::string name = DB_NAME + ".db";
    sqlite3_open(name.c_str(),&db);
    executeRequest("CREATE TABLE "+ DB_TABLE_NAME + "(Name text,Record int)");
}

std::vector<std::pair<std::string,std::string>> DataBase::getContents()
{
    std::vector<std::pair<std::string,std::string>> data;
    const char* name;
    const char* record;
    sqlite3_stmt *stmt; ////stmt = statement
    std::string request = "SELECT * FROM " + DB_TABLE_NAME + " ORDER BY Record DESC"; 
    int res = sqlite3_prepare_v2(db,request.c_str(), -1, &stmt, NULL); //sort output
    if(res != SQLITE_OK)
    {
        std::cout << "Failed to prepare statement " << sqlite3_errmsg(db) << std::endl;
        return {};
    }
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        record  = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
	data.push_back({name,record});
    }
    sqlite3_finalize(stmt);
    return data;
}
    
void DataBase::addToDataBase(std::string name,int records)
{
    deleteDublicate(records);
    std::string request = "INSERT INTO " + DB_TABLE_NAME + " VALUES('" + name + "'," + std::to_string(records) + ")";
    executeRequest(request);
}

sqlite3* DataBase::getSQL()
{
	return db;
}

void DataBase::deleteDublicate(int number)
{
    std::string request = "DELETE FROM " +  DB_TABLE_NAME + " WHERE record=" + std::to_string(number);
    executeRequest(request);
}

void DataBase::remove(std::pair<std::string,std::string> record)
{
	std::string request = "DELETE FROM " + DB_TABLE_NAME + " WHERE name='" + record.first + "' AND record=" + record.second;
	executeRequest(request);
}

DataBase::~DataBase()
{
    sqlite3_close(db);
}
  
void TableWinners::show()
{
	std::vector<std::pair<std::string,std::string>> records_info = db.getContents();
	for(auto record: records_info)
	{
		std::cout << record.first << " " << record.second << std::endl;
	}
}
    
void TableWinners::add(std::string name,int records)
{
    db.addToDataBase(name,records);
}

/*
   records = 10
   2 < 10 = below_record
   6 < 10 = rewrite below_record
   9 < 10 = rewrite below_record

   record = 6
   2 < 6 = below
   6 == 6 = equal
   9

   record = 1
   2 
   6
   9
 */
void TableWinners::changeWinner(std::string name,int records)
{
    	std::vector<std::pair<std::string,std::string>> records_info = db.getContents();
	std::pair<std::string,std::string> equal_record = {"",""};
	std::pair<std::string,std::string> below_record = {"",""};
	std::pair<std::string,std::string> empty = {"",""};
	int table_record;
	for(auto info: records_info)
	{
		table_record = stoi(info.second);
		if(table_record < records)
		{
			below_record = info;
		}
		else if(table_record == records)
		{
			equal_record = info;
		}
	}
	if(equal_record != empty)
	{
		db.remove(equal_record);
		db.addToDataBase(name,records);
	}
	else if(below_record != empty)
	{
		db.remove(below_record);
		db.addToDataBase(name,records);
	}
}

bool TableWinners::tableNotFilled()
{
	sqlite3_stmt* stmt;
	sqlite3* database = db.getSQL();
	std::string request = "SELECT COUNT(*) FROM " +  DB_TABLE_NAME;
	int rc = sqlite3_prepare_v2(database,request.c_str(),-1,&stmt,NULL);
	if(rc == SQLITE_OK)
	{
		sqlite3_step(stmt);
		int count = sqlite3_column_int(stmt,0);
		return count < MAX_RECORDS;
	}
	return false;	
}
