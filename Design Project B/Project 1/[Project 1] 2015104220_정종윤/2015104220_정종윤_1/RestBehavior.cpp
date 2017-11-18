#include "RestBehavior.h"	

RestBehavior::RestBehavior()
{

}

RestBehavior::~RestBehavior()
{

}

int RestBehavior::executeTurn(Pokemon* subjet, Pokemon* target)
{
	if (subjet->getHealthPoint() + 10 > subjet->getMaximumHealthPoint()) // 추가된 체력이 최대 체력을 넘을 경우 
	{
		subjet->setHealthPoint(subjet->getMaximumHealthPoint()); // 최대 체력으로 설정
		return 0;
	}
	subjet->setHealthPoint(subjet->getHealthPoint() + 10);
	return 0;
}