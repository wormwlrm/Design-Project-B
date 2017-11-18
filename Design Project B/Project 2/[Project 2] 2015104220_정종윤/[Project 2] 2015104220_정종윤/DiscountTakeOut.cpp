#include "DiscountTakeOut.h"

DiscountTakeOut::DiscountTakeOut()
{

}

DiscountTakeOut::~DiscountTakeOut()
{

}

int DiscountTakeOut::discount(int price)
{
	return price - price * 0.1;
}