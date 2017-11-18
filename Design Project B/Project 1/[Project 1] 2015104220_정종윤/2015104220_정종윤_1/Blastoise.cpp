#include "Blastoise.h"

Blastoise::Blastoise()
{

}

Blastoise::~Blastoise()
{

}

int Blastoise::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "거북왕의 물대포!" << endl;

	float typeDamage; // 상성 계산
	if (ally->type1 > enemy->type1) // 내가 우세한 속성일 경우
	{
		typeDamage = 2;
	}
	else if (ally->type1 == enemy->type1) // 같은 속성
	{
		typeDamage = 1;
	}
	else // 열세한 속성
	{
		typeDamage = 0.5;
	}

	int damage = (ally->attack_point - enemy->defense_point) * 6 * typeDamage; // 실제 데미지 계산
	if (ally->getAttackPoint() < enemy->getDefensePoint())
	{
		damage = 1;
	}

	enemy->health_point = enemy->health_point - damage * 1.5;
	return 0;
}