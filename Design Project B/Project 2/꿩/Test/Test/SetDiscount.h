#pragma once
#include "DiscountCalculator.h"

class SetDiscount : public DiscountCalculator
{
public:
	SetDiscount();
	~SetDiscount();

	int discount(int price);
};

