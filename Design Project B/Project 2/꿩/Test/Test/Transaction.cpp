#include "Transaction.h"


Transaction::Transaction()
{
}

void Transaction::setTransaction(int T, Merchandise* M)
{
	type = T;
	orderedProduct = M;
}

Transaction::~Transaction()
{
}

int Transaction::getType()
{
	return type;
}

Merchandise* Transaction::getOrderedProduct()
{
	return orderedProduct;
}