#include "BaseBurger.h"

BaseBurger::BaseBurger()
{
}

BaseBurger::~BaseBurger()
{
}

int BaseBurger::getPrice()
{
	return 0;
}

vector<int> BaseBurger::getDescription()
{
	vector<int> Temp;
	return Temp;
}

//----------------------------------

#include "CheeseBurger.h"

CheeseBurger::CheeseBurger()
{
}

CheeseBurger::CheeseBurger(BaseBurger* B)
{
	
}

CheeseBurger::~CheeseBurger()
{
}

int CheeseBurger::getPrice()
{
	return 3000;
}

vector<int> CheeseBurger::getDescription()
{
	vector<int> Temp;
	Temp.push_back(1);
	return Temp;
}

//----------------------------------

#include "BLTBurger.h"

BLTBurger::BLTBurger()
{
}

BLTBurger::~BLTBurger()
{
}

int BLTBurger::getPrice()
{
	return 0;
}

vector<int> BLTBurger::getDescription()
{
	vector<int> Temp;
	return Temp;
}