#include "Pidgey.h"	

Pidgey::Pidgey()
{

}

Pidgey::~Pidgey()
{

}

int Pidgey::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "구구의 모래 뿌리기!" << endl;
	enemy->attack_point -= 1;
	cout << "모래뿌리기의 효과로 상대방은 공격력이 소폭 감소했다!" << endl;
	return 0;
}