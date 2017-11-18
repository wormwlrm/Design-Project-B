#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pokemon
{
public:
	Pokemon();
	~Pokemon();

	virtual int skill(Pokemon* ally, Pokemon* enemy) = 0;
	void printStatus();
public:
	int type1;
	string name;
	int maximum_health_point;
	int health_point;
	int attack_point;
	int defense_point;
	int skill_cnt;
};

