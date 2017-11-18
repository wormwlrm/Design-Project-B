#include "CoffeeFactory.h"

CoffeeFactory::CoffeeFactory()
{

}

CoffeeFactory::~CoffeeFactory()
{

}

Coffee* CoffeeFactory::makeCoffee(int coffeeID)
{
	Coffee* orderedCoffee = new BaseCoffee();
	switch (coffeeID)
	{
	case 1: // 아메리카노
		return orderedCoffee;
		break;
	case 2: // 카푸치노
		orderedCoffee = new MilkDecorator(orderedCoffee);
		return orderedCoffee;
		break;
	case 3: // 모카커피
		orderedCoffee = new MochaDecorator(orderedCoffee);
		return orderedCoffee;
		break;
	default:
		break;
	}
	return orderedCoffee;
}