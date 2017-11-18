#pragma once
#include "Merchandise.h"
using namespace std;

class BaseBurger : public Merchandise
{
public:
	BaseBurger();
	~BaseBurger();

	int getPrice();
	vector<int> getDescription();
};

