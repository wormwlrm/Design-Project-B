#include "Pidgey.h"	

Pidgey::Pidgey()
{

}

Pidgey::~Pidgey()
{

}

int Pidgey::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "������ �� �Ѹ���!" << endl;
	enemy->attack_point -= 1;
	cout << "�𷡻Ѹ����� ȿ���� ������ ���ݷ��� ���� �����ߴ�!" << endl;
	return 0;
}