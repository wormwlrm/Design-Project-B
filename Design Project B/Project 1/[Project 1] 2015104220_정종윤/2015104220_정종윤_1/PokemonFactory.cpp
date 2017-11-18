#include "PokemonFactory.h"

PokemonFactory::PokemonFactory()
{

}

PokemonFactory::~PokemonFactory()
{

}

Pokemon* PokemonFactory::create_pokemon(int pokemon_id)
{
	Pokemon* Unit;
	switch (pokemon_id)
	{
	case 1: // 리자몽
		Unit = new Charizard;
		Unit->setType1(2);
		Unit->setName("리자몽");
		Unit->setMaximumHealthPoint(150);
		Unit->setHealthPoint(150);
		Unit->setAttackPoint(7);
		Unit->setDefensePoint(3);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 2: // 이상해씨
		Unit = new Bulbasaur;
		Unit->setType1(1);
		Unit->setName("이상해씨");
		Unit->setMaximumHealthPoint(150);
		Unit->setHealthPoint(150);
		Unit->setAttackPoint(7);
		Unit->setDefensePoint(4);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 3: // 거북왕
		Unit = new Blastoise;
		Unit->setType1(1);
		Unit->setName("거북왕");
		Unit->setMaximumHealthPoint(200);
		Unit->setHealthPoint(200);
		Unit->setAttackPoint(6);
		Unit->setDefensePoint(5);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 4: // 단데기
		Unit = new Metapod;
		Unit->setType1(1);
		Unit->setName("단데기");
		Unit->setMaximumHealthPoint(100);
		Unit->setHealthPoint(100);
		Unit->setAttackPoint(0);
		Unit->setDefensePoint(10);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 5: // 구구
		Unit = new Pidgey;
		Unit->setType1(2);
		Unit->setName("구구");
		Unit->setMaximumHealthPoint(50);
		Unit->setHealthPoint(50);
		Unit->setAttackPoint(5);
		Unit->setDefensePoint(3);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 6: // 잉어킹
		Unit = new Magikarp;
		Unit->setType1(1);
		Unit->setName("잉어킹");
		Unit->setMaximumHealthPoint(50);
		Unit->setHealthPoint(50);
		Unit->setAttackPoint(0);
		Unit->setDefensePoint(3);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	default: // 잘못된 입력
		cout << "Error : 잘못된 입력입니다." << endl;
		return 0;
		break;
	}
	return 0;
}