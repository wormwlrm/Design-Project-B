#include "Bulbasaur.h"	

Bulbasaur::Bulbasaur()
{

}

Bulbasaur::~Bulbasaur()
{

}

int Bulbasaur::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "�̻��ؾ��� ���ռ�!" << endl;
	ally->attack_point++;
	cout << "�̻��ؾ���(��) ���ݷ��� ���� ����ߴ�!" << endl;
	return 0;
}