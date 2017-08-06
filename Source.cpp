#include <iostream>
#include <string>
#include "P1DBAbstraction.h"

using namespace std;

int main()
{
	P1DBAbstraction db("C:/Users/James-Laptop/Desktop/Northwind/Northwind.db");

	int userChoice = 0;

	while (userChoice != -1)
	{
		cout << "Query 1" << endl;
		cout << "Query 2" << endl;
		cout << "Query 3" << endl;
		cout << "Query 4" << endl;
		cout << "Query 5" << endl;
		cout << "Query 6" << endl;
		cout << "Query 7" << endl;
		cout << "Query 8" << endl;
		cout << "Query 9" << endl;
		cout << "Query 10" << endl;
		cout << "Enter -1 to quit" << endl;


		cout << "Enter your option: ";
		cin >> userChoice;

		//this would have been cleaner if I used an array of function pointers
		//whoops
		if (userChoice == 1)
		{
			
			db.executeQuery1();
		}
		else if (userChoice == 2)
		{
			db.executeQuery2();
		}
		else if (userChoice == 3)
		{
			db.executeQuery3();
		}
		else if (userChoice == 4)
		{
			db.executeQuery4();
		}
		else if (userChoice == 5)
		{
			cout << "I was unable to figure out query 5 :(" << endl;
		}
		else if (userChoice == 6)
		{
			db.executeQuery6();
		}
		else if (userChoice == 7)
		{
			db.executeQuery7();
		}
		else if (userChoice == 8)
		{
			db.executeQuery8();
		}
		else if (userChoice == 9)
		{
			cout << "I was unable to figure out query 9 :(" << endl;
		}
		else if (userChoice == 10)
		{
			db.executeQuery10();
		}
		cout << "---------" << endl;
	}
}