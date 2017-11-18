#include "OrderTransactionManager.h"

OrderTransactionManager::OrderTransactionManager()
{

}

OrderTransactionManager::~OrderTransactionManager()
{

}

void OrderTransactionManager::addTransaction(Transaction t)
{
	orderTransactions.push_back(t);
}

Transaction OrderTransactionManager::getFrontTransaction()
{
	if (orderTransactions.size() != 0)
	{
		return orderTransactions.at(0);
	}
	return Transaction();
}

void OrderTransactionManager::deleteTransactionFromFront()
{
	if (orderTransactions.size() != 0)
	{
		orderTransactions.erase(orderTransactions.begin());
	}
}

void OrderTransactionManager::deleteTransactionByIndex(int idx)
{
	orderTransactions.erase(orderTransactions.begin() + idx);
}

void OrderTransactionManager::printTransactions()
{
	for (int i = 0; i < orderTransactions.size(); i++)
	{
		cout << i << ". ";
		orderTransactions.at(i).printCoffeeInfo();
		cout << endl;
	}
}