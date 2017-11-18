#pragma once
#include "Merchandise.h"
#include <string>
using namespace std;

class Transaction
{
public:
	Transaction();
	~Transaction();

	int getType();
	Merchandise* getOrderedProduct();
	void setTransaction(int T, Merchandise* M);

private:
	int type;
	Merchandise* orderedProduct;
};

