#include "DiscountCalculator.h"


DiscountCalculator::DiscountCalculator()
{
}

DiscountCalculator::~DiscountCalculator()
{
}

#include "SetDiscount.h"

SetDiscount::SetDiscount()
{
	
}


SetDiscount::~SetDiscount()
{
}

int SetDiscount::discount(int price)
{
	return price * 0.9;
}


#include "SingleDiscount.h"

SingleDiscount::SingleDiscount()
{
}


SingleDiscount::~SingleDiscount()
{
}

int SingleDiscount::discount(int price)
{
	return price;
}


#include "ComboDiscount.h"

ComboDiscount::ComboDiscount()
{
}


ComboDiscount::~ComboDiscount()
{
}

int ComboDiscount::discount(int price)
{
	return price * 0.95;
}