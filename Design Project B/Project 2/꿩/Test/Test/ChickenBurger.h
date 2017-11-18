#pragma once
#include "BaseBurger.h"

class ChickenBurger : public BaseBurger
{
public:
	ChickenBurger();
	ChickenBurger(BaseBurger* B);
	~ChickenBurger();

	int getPrice();
	vector<int> getDescription();
};
