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
			coffeeName = "�Ƹ޸�ī�� ";
			break;
		case 2:
			coffeeName = "īǪġ�� ";
			break;
		case 3:
			coffeeName = "��īĿ�� ";
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
		cout << ", �� �߰�";
	if (whip)
		cout << ", ����ũ�� �߰�";
	
}