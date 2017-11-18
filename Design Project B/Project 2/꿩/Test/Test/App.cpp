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
		cout << "주문 받기" << endl;
		cout << "1. 세트" << endl;
		cout << "2. 세트" << endl;
		cout << "3. 세트" << endl;
		cin >> Discount;

		cout << "버거 종류" << endl;
		cout << "1. 치즈버거" << endl;
		cout << "2. BLT버거" << endl;
		cout << "3. 치킨버거" << endl;
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
				cout << "단품 주문" << endl;
				cout << "1. 감자튀김" << endl;
				cout << "2. 음료수" << endl;
				cout << "3. 그만" << endl;
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