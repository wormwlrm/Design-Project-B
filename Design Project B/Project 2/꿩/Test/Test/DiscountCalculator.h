#pragma once
#include <vector>
#include <string>

using namespace std;

class DiscountCalculator
{
public:
	DiscountCalculator();
	~DiscountCalculator();

	virtual int discount(int price) = 0;
};

