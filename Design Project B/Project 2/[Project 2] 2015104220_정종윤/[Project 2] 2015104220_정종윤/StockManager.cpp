#include "StockManager.h"

StockManager::StockManager()
{
	coffeeStock = 3;
	milkStock = 3;
	mochaStock = 3;
	shotStock = 3;
	whipStock = 3;
}

StockManager::~StockManager()
{

}

bool StockManager::addStockByIngredientsID(vector<int> ingredientsID)
{
	for (int i = 0; i < ingredientsID.size(); i++)
	{
		switch (ingredientsID.at(i))
		{
		case 1:
			coffeeStock++;
			break;
		case 2:
			milkStock++;
			break;
		case 3:
			mochaStock++;
			break;
		case 4:
			shotStock++;
			break;
		case 5:
			whipStock++;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}

bool StockManager::reduceStockByIngredientsID(vector<int> ingredientsID)
{
	bool negative = false;
	for (int i = 0; i < ingredientsID.size(); i++)
	{
		switch (ingredientsID.at(i))
		{
		case 1:
			coffeeStock--;
			if (coffeeStock < 0)
				negative = true;
			break;
		case 2:
			milkStock--;
			if (milkStock < 0)
				negative = true;
			break;
		case 3:
			mochaStock--;
			if (mochaStock < 0)
				negative = true;
			break;
		case 4:
			shotStock--;
			if (shotStock < 0)
				negative = true;
			break;
		case 5:
			whipStock--;
			if (whipStock < 0)
				negative = true;
			break;
		default:
			return false;
		}
	}
	if (negative)
	{
		addStockByIngredientsID(ingredientsID);
		return false;
	}
	return true;
}

void StockManager::setCoffeeStock(int cs)
{
	coffeeStock = cs;
}

void StockManager::setMilkStock(int ms)
{
	milkStock = ms;
}

void StockManager::setMochaStock(int ms)
{
	mochaStock = ms;
}

void StockManager::setShotStock(int ss)
{
	shotStock = ss;
}

void StockManager::setWhipStock(int ws)
{
	whipStock = ws;
}

int StockManager::getCoffeeStock()
{
	return coffeeStock;
}

int StockManager::getMilkStock()
{
	return milkStock;
}

int StockManager::getMochaStock()
{
	return mochaStock;
}

int StockManager::getShotStock()
{
	return shotStock;
}

int StockManager::getWhipStock()
{
	return whipStock;
}

void StockManager::printStock()
{
	cout << "커피 재고 : " << coffeeStock << endl;
	cout << "우유 재고 : " << milkStock << endl;
	cout << "모카 재고 : " << mochaStock << endl;
	cout << "샷 재고 : " << shotStock << endl;
	cout << "휘핑크림 재고 : " << whipStock << endl;
}