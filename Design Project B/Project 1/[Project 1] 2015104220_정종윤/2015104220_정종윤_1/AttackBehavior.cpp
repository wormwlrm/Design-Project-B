#include "AttackBehavior.h"	

AttackBehavior::AttackBehavior()
{

}

AttackBehavior::~AttackBehavior()
{

}

int AttackBehavior::executeTurn(Pokemon* subjet, Pokemon* target)
{
	float typeDamage; // �� ���
	if (subjet->getType1() > target->getType1())
	{
		typeDamage = 2;
	}
	else if (subjet->getType1() == target->getType1())
	{
		typeDamage = 1;
	}
	else
	{
		typeDamage = 0.5;
	}

	int damage = (subjet->getAttackPoint() - target->getDefensePoint()) * 6 * typeDamage; // ���� ������ ���
	if (subjet->getAttackPoint() < target->getDefensePoint())
	{
		damage = 1;
	}
	
	target->setHealthPoint(target->getHealthPoint() - damage);

	return typeDamage;
}