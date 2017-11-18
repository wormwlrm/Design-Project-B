#pragma once
#include <iostream>
#include "CounterFacade.h"
#include "ManagerFacade.h"
using namespace std;

class App
{
public:
	App();
	~App();

	void run();
private:
	CounterFacade* cf;
	ManagerFacade* mf;
};

