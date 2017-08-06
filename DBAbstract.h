#pragma once
#include "sqlite3.h"
#include <string>

using namespace std;

class DBAbstract
{
public:
	DBAbstract(string filePath);
	~DBAbstract();

protected:

	sqlite3* db;

	bool executeSqlQuery(string query, sqlite3_stmt*& myStatement);
};
