#pragma once
#include "DiscountCalculator.h"

class ComboDiscount : public DiscountCalculator
{
public:
	ComboDiscount();
	~ComboDiscount();

	int discount(int price) = 0;
};

