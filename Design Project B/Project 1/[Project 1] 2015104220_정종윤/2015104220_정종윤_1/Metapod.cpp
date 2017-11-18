#include "Metapod.h"	

Metapod::Metapod()
{

}

Metapod::~Metapod()
{

}

int Metapod::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "단데기의 단단해지기!" << endl;
	ally->defense_point += 2;
	cout << "단데기은(는) 방어력이 크게 상승했다!" << endl;
	return 0;
}