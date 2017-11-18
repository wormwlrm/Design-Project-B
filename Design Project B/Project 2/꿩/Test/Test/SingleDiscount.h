#pragma once
#include "DiscountCalculator.h"

class SingleDiscount : public DiscountCalculator
{
public:
	SingleDiscount();
	~SingleDiscount();

	int discount(int price) = 0;
};

