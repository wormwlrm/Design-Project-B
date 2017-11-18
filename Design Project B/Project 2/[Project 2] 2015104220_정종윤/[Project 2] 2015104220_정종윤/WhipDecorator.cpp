#include "WhipDecorator.h"

WhipDecorator::WhipDecorator(Coffee* c)
{
	pCoffee = c;
}

WhipDecorator::~WhipDecorator()
{

}

int WhipDecorator::getCost()
{
	return pCoffee->getCost();
}

vector<int> WhipDecorator::GetIngredientsID()
{
	vector<int> Whip = pCoffee->GetIngredientsID();
	Whip.push_back(5);
	return Whip;
}