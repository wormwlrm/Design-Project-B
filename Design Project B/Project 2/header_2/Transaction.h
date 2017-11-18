#pragma once
#include <vector>
using namespace std;
class Transaction
{
public:
	Transaction();
	~Transaction();

private:
	vector<int> orderedCoffeeInfo;
	int price;
};

