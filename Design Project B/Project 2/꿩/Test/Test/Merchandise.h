#pragma once
#include <vector>
#include <string>
using namespace std;

class Merchandise
{
public:
	Merchandise();
	~Merchandise();

	virtual int getPrice() = 0;
	virtual vector<int> getDescription() = 0;
};

