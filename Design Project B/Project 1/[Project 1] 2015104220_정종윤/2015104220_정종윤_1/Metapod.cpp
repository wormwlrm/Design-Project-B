#include "Metapod.h"	

Metapod::Metapod()
{

}

Metapod::~Metapod()
{

}

int Metapod::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "�ܵ����� �ܴ�������!" << endl;
	ally->defense_point += 2;
	cout << "�ܵ�����(��) ������ ũ�� ����ߴ�!" << endl;
	return 0;
}