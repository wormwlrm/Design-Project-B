#pragma once
#include "Merchandise.h"
#include "DiscountCalculator.h"
#include "Transaction.h"
#include "CheeseBurger.h"
#include "Drinks.h"
#include "Fries.h"
#include "SetDiscount.h"
#include "BLTBurger.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class App
{
public:
	App();
	~App();

	void run();
	void setDC(int i);

private:
	vector<Transaction> orderedList;
	DiscountCalculator* DC;
};

