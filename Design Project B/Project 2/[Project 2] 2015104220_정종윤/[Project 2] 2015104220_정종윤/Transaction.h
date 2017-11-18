#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Transaction
{
public:
	Transaction();
	Transaction(vector<int> oc, int _price)
	{
		orderedCoffeeInfo = oc;
		price = _price;
	}
	~Transaction();

	void printCoffeeInfo();
	vector<int> getOrderedCoffeeInfo() { return orderedCoffeeInfo; };
	int getPrice() { return price; };

private:
	vector<int> orderedCoffeeInfo;
	int price;
};

