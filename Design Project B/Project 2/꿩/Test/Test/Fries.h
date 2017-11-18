#pragma once
#include "Decorator.h"

class Fries : public Decorator
{
public:
	Fries();
	Fries(Merchandise* B);
	~Fries();

	int getPrice();
	vector<int> getDescription();
};
