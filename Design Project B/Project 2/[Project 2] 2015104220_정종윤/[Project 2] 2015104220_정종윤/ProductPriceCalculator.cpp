#include "ProductPriceCalculator.h"

ProductPriceCalculator::ProductPriceCalculator()
{

}

ProductPriceCalculator::~ProductPriceCalculator()
{

}

bool ProductPriceCalculator::setDiscountAlgoritm(int discountAlgorithmID)
{
	switch (discountAlgorithmID)
	{
	case 1:
		dcalg = new DiscountDrinkInStore();
		break;
	case 2:
		dcalg = new DiscountTakeOut();
		break;
	case 3:
		dcalg = new DiscountCoupon();
		break;
	default:
		return false;
		break;
	}
	return true;
}

int ProductPriceCalculator::discountPrice(int price)
{
	return dcalg ->discount(price);
}