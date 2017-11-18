#include "Decorator.h"

Decorator::Decorator()
{
}

Decorator::~Decorator()
{
}


#include "Drinks.h"


Drinks::Drinks()
{
}

Drinks::Drinks(Merchandise* B)
{
	newBurger = B;
}

Drinks::~Drinks()
{
}

int Drinks::getPrice()
{
	return (newBurger->getPrice()) + 1000;
}

vector<int> Drinks::getDescription()
{
	vector<int> Temp = newBurger->getDescription();
	Temp.push_back(5);
	return Temp;
}


#include "Fries.h"


Fries::Fries()
{
}

Fries::Fries(Merchandise* B)
{
	newBurger = B;
}

Fries::~Fries()
{
}

int Fries::getPrice()
{
	return newBurger->getPrice() + 1000;
}

vector<int> Fries::getDescription()
{
	vector<int> Temp = newBurger->getDescription();
	Temp.push_back(4);
	return Temp;
}