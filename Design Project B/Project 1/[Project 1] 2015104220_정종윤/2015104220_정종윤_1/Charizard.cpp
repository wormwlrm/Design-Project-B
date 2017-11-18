#include "Charizard.h"	

Charizard::Charizard()
{

}

Charizard::~Charizard()
{

}

int Charizard::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "리자몽의 불대문자!" << endl;
	enemy->health_point -= 25;
	return 0;
}