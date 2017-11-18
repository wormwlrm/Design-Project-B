#pragma once
#include "BaseBurger.h"

class CheeseBurger : public BaseBurger
{
public:
	CheeseBurger();
	CheeseBurger(BaseBurger* B);
	~CheeseBurger();

	int getPrice();
	vector<int> getDescription();
};
