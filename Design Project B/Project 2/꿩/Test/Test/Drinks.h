#pragma once
#include "Decorator.h"

class Drinks : public Decorator
{
public:
	Drinks();
	Drinks(Merchandise* B);
	~Drinks();

	int getPrice();
	vector<int> getDescription();
};
