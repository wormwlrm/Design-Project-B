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

	//get 함수
	int getType1();
	string getName();
	int getMaximumHealthPoint();
	int getHealthPoint();
	int getAttackPoint();
	int getDefensePoint();
	int getSkillCnt();

	//set 함수
	void setType1(int N);
	void setName(string Name);
	void setMaximumHealthPoint(int N);
	void setHealthPoint(int N);
	void setAttackPoint(int N);
	void setDefensePoint(int N);
	void setSkillCnt(int N);

public:
	int type1; // 지상 1, 비행 2
	string name;
	int maximum_health_point;
	int health_point;
	int attack_point;
	int defense_point;
	int skill_cnt;
};

