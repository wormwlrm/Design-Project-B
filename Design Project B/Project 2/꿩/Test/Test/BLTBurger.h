#pragma once
#include "BaseBurger.h"

class BLTBurger : public BaseBurger
{
public:
	BLTBurger();
	BLTBurger(BaseBurger* B);
	~BLTBurger();

	int getPrice();
	vector<int> getDescription();
};
