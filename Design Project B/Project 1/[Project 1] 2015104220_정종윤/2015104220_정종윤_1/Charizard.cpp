#include "Charizard.h"	

Charizard::Charizard()
{

}

Charizard::~Charizard()
{

}

int Charizard::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "���ڸ��� �Ҵ빮��!" << endl;
	enemy->health_point -= 25;
	return 0;
}