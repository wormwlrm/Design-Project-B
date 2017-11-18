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
	case 1: // �Ƹ޸�ī��
		return orderedCoffee;
		break;
	case 2: // īǪġ��
		orderedCoffee = new MilkDecorator(orderedCoffee);
		return orderedCoffee;
		break;
	case 3: // ��īĿ��
		orderedCoffee = new MochaDecorator(orderedCoffee);
		return orderedCoffee;
		break;
	default:
		break;
	}
	return orderedCoffee;
}