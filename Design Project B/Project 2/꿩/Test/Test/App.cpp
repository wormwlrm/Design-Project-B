#include "App.h"


App::App()
{
}


App::~App()
{
}

void App::run()
{
	int Discount, Burger, Deco;
	Transaction T;
	Merchandise* OrderedBurger = new BaseBurger();
	while (1)
	{
		cout << "�ֹ� �ޱ�" << endl;
		cout << "1. ��Ʈ" << endl;
		cout << "2. ��Ʈ" << endl;
		cout << "3. ��Ʈ" << endl;
		cin >> Discount;

		cout << "���� ����" << endl;
		cout << "1. ġ�����" << endl;
		cout << "2. BLT����" << endl;
		cout << "3. ġŲ����" << endl;
		cin >> Burger;

		switch (Discount)
		{
		case 1:
			OrderedBurger = new CheeseBurger();
			OrderedBurger = new Drinks(OrderedBurger);
			OrderedBurger = new Fries(OrderedBurger);
			DC = new SetDiscount();
			T.setTransaction(1, OrderedBurger);
			cout << OrderedBurger->getPrice() << endl;
			cout << DC->discount(OrderedBurger->getPrice()) << endl;
		case 2:
			OrderedBurger = new BLTBurger();

		case 3:
			Deco = true;



			while (Deco)
			{
				cout << "��ǰ �ֹ�" << endl;
				cout << "1. ����Ƣ��" << endl;
				cout << "2. �����" << endl;
				cout << "3. �׸�" << endl;
			}
		default:
			break;
		}


	}
}

void App::setDC(int i)
{
	switch (i)
	{
	case 1:
		
		break;
	default:
		break;
	}
}