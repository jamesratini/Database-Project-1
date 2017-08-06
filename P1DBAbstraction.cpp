#include <iostream>
#include "P1DBAbstraction.h"

using namespace std;

P1DBAbstraction::P1DBAbstraction(string path)
	: DBAbstract(path)
{
	
}
void P1DBAbstraction::executeQuery1()
{
	string sql = "SELECT COUNT(*) FROM Customers WHERE Customers.Country = 'USA' OR Customers.Country = 'UK' OR Customers.Country = 'Spain'";
	sqlite3_stmt* myStatement;
	cout << "1. How many companies are in the UK, USA, and Spain?" << endl;
	if (executeSqlQuery(sql, myStatement))
	{
		
		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			//int id = sqlite3_column_int(myStatement, 0);
			int countResult = sqlite3_column_int(myStatement, 0);

			cout << countResult << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}
void P1DBAbstraction::executeQuery2()
{
	string sql = "SELECT CompanyName, Phone FROM Suppliers WHERE Suppliers.Phone LIKE '%514%'";
	sqlite3_stmt* myStatement;
	cout << "2. What are the names and phone numbers of suppliers who are in the 514 area code?" << endl;
	if (executeSqlQuery(sql, myStatement))
	{

		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			//int id = sqlite3_column_int(myStatement, 0);
			string compName((char*)sqlite3_column_text(myStatement, 0));
			string compPhone((char*)sqlite3_column_text(myStatement, 1));

			cout << compName << " " << compPhone << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}
void P1DBAbstraction::executeQuery3()
{
	string sql = "SELECT COUNT(*) FROM Products WHERE Products.UnitsInStock > Products.UnitsOnOrder";
	sqlite3_stmt* myStatement;
	cout << "3. How many products have a greater value of in-stock items compared to the value of items on order?" << endl;
	if (executeSqlQuery(sql, myStatement))
	{

		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			//int id = sqlite3_column_int(myStatement, 0);
			int countResult = sqlite3_column_int(myStatement, 0);

			cout << countResult << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}
void P1DBAbstraction::executeQuery4()
{
	string sql = "SELECT ProductName FROM Products, [Order Details] WHERE[Order Details].OrderID = '10275' AND[Order Details].ProductID = Products.ProductID";
	sqlite3_stmt* myStatement;
	cout << "4. What are the names of the products in order #10275?" << endl;
	if (executeSqlQuery(sql, myStatement))
	{

		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			//int id = sqlite3_column_int(myStatement, 0);
			string compName((char*)sqlite3_column_text(myStatement, 0));

			cout << compName << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}
void P1DBAbstraction::executeQuery5()
{

}
void P1DBAbstraction::executeQuery6()
{
	string sql = "SELECT Products.ProductName FROM Customers, Orders, [Order Details], Products WHERE Customers.CompanyName = 'The Big Cheese' AND Customers.CustomerID = Orders.CustomerID AND Orders.OrderID = [Order Details].OrderID AND[Order Details].ProductID = Products.ProductID AND[Order Details].Quantity >= 10";
	sqlite3_stmt* myStatement;
	cout << "6. What are the names of the products that were ever ordered by the customer 'The Big Cheese' in quantities of 10 or more?" << endl;
	if (executeSqlQuery(sql, myStatement))
	{

		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			//int id = sqlite3_column_int(myStatement, 0);
			string prodName((char*)sqlite3_column_text(myStatement, 0));

			cout << prodName << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}
void P1DBAbstraction::executeQuery7()
{
	string sql = "SELECT SUM(([Order Details].UnitPrice * (1 - [Order Details].Discount)) * [Order Details].Quantity) AS totalPrice FROM Customers, Orders, [Order Details] WHERE Customers.CompanyName = 'Simons bistro' AND Customers.CustomerID = Orders.CustomerID AND Orders.OrderID = [Order Details].OrderID AND Orders.OrderDate = '1/16/1997 12:00:00 AM'";
	sqlite3_stmt* myStatement;
	cout << "7. What was the final order price for all items ordered by the customer 'Simons bistro' on January 16th 1997?" << endl;
	if (executeSqlQuery(sql, myStatement))
	{

		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			//int id = sqlite3_column_int(myStatement, 0);
			int finalResult = sqlite3_column_int(myStatement, 0);

			cout << "$" << finalResult << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}
void P1DBAbstraction::executeQuery8()
{
	string sql = "SELECT MAX(Products.UnitsInStock) FROM Products, [Order Details] WHERE Products.ProductID = [Order Details].ProductID AND[Order Details].Discount >= 0.25";
	sqlite3_stmt* myStatement;
	cout << "8. Which product that was ever sold at a discount of 25% or more has the most units in stock (and how many units are in stock)?" << endl;
	if (executeSqlQuery(sql, myStatement))
	{

		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			//int id = sqlite3_column_int(myStatement, 0);
			int finalResult = sqlite3_column_int(myStatement, 0);

			cout << finalResult << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}
void P1DBAbstraction::executeQuery9()
{
	
}
void P1DBAbstraction::executeQuery10()
{
	//query written with the help of Hayden
	string sql = "SELECT Suppliers.CompanyName, SUM(Products.UnitsOnOrder) AS totalOrders FROM Suppliers, Products WHERE Suppliers.SupplierID = Products.SupplierID GROUP BY Products.SupplierID HAVING SUM(Products.UnitsOnOrder) > 100";
	sqlite3_stmt* myStatement;
	cout << "10. Who are the suppliers whose products have more than 100 units on order." << endl;
	if (executeSqlQuery(sql, myStatement))
	{

		int statusStep = sqlite3_step(myStatement);

		while (statusStep == SQLITE_ROW)
		{
			string compName((char*)sqlite3_column_text(myStatement, 0));
			int finalResult = sqlite3_column_int(myStatement, 1);

			cout << compName << " " << finalResult << endl;
			statusStep = sqlite3_step(myStatement);
		}

		sqlite3_finalize(myStatement);
	}
}