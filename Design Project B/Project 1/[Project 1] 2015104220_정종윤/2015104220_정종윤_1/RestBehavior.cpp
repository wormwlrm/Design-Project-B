#include "RestBehavior.h"	

RestBehavior::RestBehavior()
{

}

RestBehavior::~RestBehavior()
{

}

int RestBehavior::executeTurn(Pokemon* subjet, Pokemon* target)
{
	if (subjet->getHealthPoint() + 10 > subjet->getMaximumHealthPoint()) // �߰��� ü���� �ִ� ü���� ���� ��� 
	{
		subjet->setHealthPoint(subjet->getMaximumHealthPoint()); // �ִ� ü������ ����
		return 0;
	}
	subjet->setHealthPoint(subjet->getHealthPoint() + 10);
	return 0;
}