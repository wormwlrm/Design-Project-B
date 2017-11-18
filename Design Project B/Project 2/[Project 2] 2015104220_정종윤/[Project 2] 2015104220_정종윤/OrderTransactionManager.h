#pragma once
#include "Transaction.h"
#include <vector>
#include <iostream>
using namespace std;
class OrderTransactionManager
{
public:
	OrderTransactionManager();
	~OrderTransactionManager();

	void addTransaction(Transaction t);
	Transaction getFrontTransaction();
	void deleteTransactionFromFront();
	void deleteTransactionByIndex(int idx);
	void printTransactions();

	int getOrderTransactionsNum(){ return orderTransactions.size(); };
	Transaction* getOrderTransactionsAt(int index) {return &orderTransactions.at(index);};

private:
	vector<Transaction> orderTransactions;
};

