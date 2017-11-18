#include "Pokemon.h"

Pokemon::Pokemon()
{

}

Pokemon::~Pokemon()
{

}

void Pokemon::printStatus()
{

}

int Pokemon::getType1()
{
	return type1;
}

string Pokemon::getName()
{
	return name;
}

int Pokemon::getMaximumHealthPoint()
{
	return maximum_health_point;
}

int Pokemon::getHealthPoint()
{
	return health_point;
}

int Pokemon::getAttackPoint()
{
	return attack_point;
}

int Pokemon::getDefensePoint()
{
	return defense_point;
}

int Pokemon::getSkillCnt()
{
	return skill_cnt;
}

void Pokemon::setType1(int N)
{
	type1 = N;
}

void Pokemon::setName(string Name)
{
	name = Name;
}

void Pokemon::setMaximumHealthPoint(int N)
{
	maximum_health_point = N;
}

void Pokemon::setHealthPoint(int N)
{
	health_point = N;
}

void Pokemon::setAttackPoint(int N)
{
	attack_point = N;
}

void Pokemon::setDefensePoint(int N)
{
	defense_point = N;
}

void Pokemon::setSkillCnt(int N)
{
	skill_cnt = N;
}