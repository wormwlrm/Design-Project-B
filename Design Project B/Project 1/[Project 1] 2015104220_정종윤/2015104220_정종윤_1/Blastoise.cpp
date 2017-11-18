#include "Blastoise.h"

Blastoise::Blastoise()
{

}

Blastoise::~Blastoise()
{

}

int Blastoise::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "�źϿ��� ������!" << endl;

	float typeDamage; // �� ���
	if (ally->type1 > enemy->type1) // ���� �켼�� �Ӽ��� ���
	{
		typeDamage = 2;
	}
	else if (ally->type1 == enemy->type1) // ���� �Ӽ�
	{
		typeDamage = 1;
	}
	else // ������ �Ӽ�
	{
		typeDamage = 0.5;
	}

	int damage = (ally->attack_point - enemy->defense_point) * 6 * typeDamage; // ���� ������ ���
	if (ally->getAttackPoint() < enemy->getDefensePoint())
	{
		damage = 1;
	}

	enemy->health_point = enemy->health_point - damage * 1.5;
	return 0;
}