#include "BaseCoffee.h"

BaseCoffee::BaseCoffee()
{

}

BaseCoffee::~BaseCoffee()
{

}

int BaseCoffee::getCost()
{
	return 3000;
}

vector<int> BaseCoffee::GetIngredientsID()
{
	vector<int> BaseCoffee;
	BaseCoffee.push_back(1);
	return BaseCoffee;
}