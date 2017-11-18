#include "ShotDecorator.h"

ShotDecorator::ShotDecorator(Coffee* c)
{
	pCoffee = c;
}

ShotDecorator::~ShotDecorator()
{

}

int ShotDecorator::getCost()
{
	return 500 + pCoffee->getCost();
}

vector<int> ShotDecorator::GetIngredientsID()
{
	vector<int> Shot = pCoffee->GetIngredientsID();
	Shot.push_back(4);
	return Shot;
}