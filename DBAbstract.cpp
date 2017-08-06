#include <iostream>
#include "DBAbstract.h"
#include "sqlite3.h"
using namespace std;

DBAbstract::DBAbstract(string path)
{
	//open database
	int statusOpen = sqlite3_open(path.c_str(), &db);

	//if it fails, set pointer to NULL
	if (statusOpen != SQLITE_OK)
	{
		
		db = NULL;
	}
}
DBAbstract::~DBAbstract()
{
	if (db != NULL)
	{
		sqlite3_close(db);

		//no hanging pointers!
		db = NULL;
	}
}

bool DBAbstract::executeSqlQuery(string query, sqlite3_stmt*& myStatement)
{
	bool retval = false;
	
	int statusPrep = sqlite3_prepare_v2(db, query.c_str(), -1, &myStatement, NULL);
	
	if (statusPrep == SQLITE_OK)
	{
		
		retval = true;
	}

	return retval;
}