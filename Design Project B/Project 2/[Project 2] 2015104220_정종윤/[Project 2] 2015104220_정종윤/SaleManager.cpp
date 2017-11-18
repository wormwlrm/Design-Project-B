#include "SaleManager.h"

SaleManager::SaleManager()
{
	price = 10000;
}

SaleManager::~SaleManager()
{

}

void SaleManager::addMoney(int money)
{
	price += money;
}

bool SaleManager::reduceMoney(int money)
{
	if (price < money)
		return false;

	price -= money;
	return true;
}

int SaleManager::getPrice()
{
	return price;
}