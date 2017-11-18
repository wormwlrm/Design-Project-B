#pragma once
#include "Merchandise.h"

class Decorator : public Merchandise
{
public:
	Decorator();
	~Decorator();

protected:
	Merchandise* newBurger;
};

