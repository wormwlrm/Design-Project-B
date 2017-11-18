#pragma once
#include "CoffeeFactory.h"
#include "OrderTransactionManager.h"
#include "StockManager.h"
#include "SaleManager.h"
#include "ProductPriceCalculator.h"
class CounterFacade
{
public:
	CounterFacade();
	CounterFacade(OrderTransactionManager* _otm, StockManager* _sm, SaleManager* _slm);
	~CounterFacade();

	void order();
	void serveCoffee();
	void cancel();

	OrderTransactionManager* getotm() { return otm; };
	StockManager* getsm(){ return sm; };
	SaleManager* getslm() { return slm; };

private:
	CoffeeFactory cf;
	ProductPriceCalculator ppc;
	OrderTransactionManager* otm;
	StockManager* sm;
	SaleManager* slm;
};

