#include "MilkDecorator.h"

MilkDecorator::MilkDecorator(Coffee* c)
{
	pCoffee = c;
}

MilkDecorator::~MilkDecorator()
{

}

int MilkDecorator::getCost()
{
	return 1000 + pCoffee->getCost();
}

vector<int> MilkDecorator::GetIngredientsID()
{
	vector<int> Milk = pCoffee->GetIngredientsID();
	Milk.push_back(2);
	return Milk;
}