#include "Bulbasaur.h"	

Bulbasaur::Bulbasaur()
{

}

Bulbasaur::~Bulbasaur()
{

}

int Bulbasaur::skill(Pokemon* ally, Pokemon* enemy)
{
	cout << "ÀÌ»óÇØ¾¾ÀÇ ±¤ÇÕ¼º!" << endl;
	ally->attack_point++;
	cout << "ÀÌ»óÇØ¾¾Àº(´Â) °ø°Ý·ÂÀÌ ¼ÒÆø »ó½ÂÇß´Ù!" << endl;
	return 0;
}