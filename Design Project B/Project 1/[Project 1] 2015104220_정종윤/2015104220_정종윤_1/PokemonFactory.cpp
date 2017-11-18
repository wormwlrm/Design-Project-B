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
	case 1: // ���ڸ�
		Unit = new Charizard;
		Unit->setType1(2);
		Unit->setName("���ڸ�");
		Unit->setMaximumHealthPoint(150);
		Unit->setHealthPoint(150);
		Unit->setAttackPoint(7);
		Unit->setDefensePoint(3);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 2: // �̻��ؾ�
		Unit = new Bulbasaur;
		Unit->setType1(1);
		Unit->setName("�̻��ؾ�");
		Unit->setMaximumHealthPoint(150);
		Unit->setHealthPoint(150);
		Unit->setAttackPoint(7);
		Unit->setDefensePoint(4);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 3: // �źϿ�
		Unit = new Blastoise;
		Unit->setType1(1);
		Unit->setName("�źϿ�");
		Unit->setMaximumHealthPoint(200);
		Unit->setHealthPoint(200);
		Unit->setAttackPoint(6);
		Unit->setDefensePoint(5);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 4: // �ܵ���
		Unit = new Metapod;
		Unit->setType1(1);
		Unit->setName("�ܵ���");
		Unit->setMaximumHealthPoint(100);
		Unit->setHealthPoint(100);
		Unit->setAttackPoint(0);
		Unit->setDefensePoint(10);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 5: // ����
		Unit = new Pidgey;
		Unit->setType1(2);
		Unit->setName("����");
		Unit->setMaximumHealthPoint(50);
		Unit->setHealthPoint(50);
		Unit->setAttackPoint(5);
		Unit->setDefensePoint(3);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	case 6: // �׾�ŷ
		Unit = new Magikarp;
		Unit->setType1(1);
		Unit->setName("�׾�ŷ");
		Unit->setMaximumHealthPoint(50);
		Unit->setHealthPoint(50);
		Unit->setAttackPoint(0);
		Unit->setDefensePoint(3);
		Unit->setSkillCnt(2);
		return Unit;
		break;

	default: // �߸��� �Է�
		cout << "Error : �߸��� �Է��Դϴ�." << endl;
		return 0;
		break;
	}
	return 0;
}