#include "MochaDecorator.h"

MochaDecorator::MochaDecorator(Coffee* c)
{
	pCoffee = c;
}

MochaDecorator::~MochaDecorator()
{

}

int MochaDecorator::getCost()
{
	return 500 + pCoffee->getCost();
}

vector<int> MochaDecorator::GetIngredientsID()
{
	vector<int> Mocha = pCoffee->GetIngredientsID();
	Mocha.push_back(3);
	return Mocha;
}