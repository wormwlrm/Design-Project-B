#include "Transaction.h"

Transaction::Transaction()
{

}

Transaction::~Transaction()
{

}

void Transaction::printCoffeeInfo()
{
	string coffeeName;
	bool shot = false, whip = false;
	for (int i = 0; i < orderedCoffeeInfo.size(); i++)
	{
		switch (orderedCoffeeInfo.at(i))
		{
		case 1:
			coffeeName = "아메리카노 ";
			break;
		case 2:
			coffeeName = "카푸치노 ";
			break;
		case 3:
			coffeeName = "모카커피 ";
			break;
		case 4:
			shot = true;
			break;
		case 5:
			whip = true;
			break;
		default:
			return;
		}
	}

	cout << coffeeName; 
	if (shot)
		cout << ", 샷 추가";
	if (whip)
		cout << ", 휘핑크림 추가";
	
}