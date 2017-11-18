#include "ManagerFacade.h"

ManagerFacade::ManagerFacade()
{

}

ManagerFacade::~ManagerFacade()
{

}

ManagerFacade::ManagerFacade(OrderTransactionManager * _otm, StockManager* _sm, SaleManager* _slm)
{
	otm = _otm;
	sm = _sm;
	slm = _slm;
}

void ManagerFacade::orderIngredients()
{
	printStockStatus();
	cout << "┌─────────────────┐" << endl;
	cout << "│             재료 발주            │" << endl;
	cout << "└─────────────────┘" << endl;
	vector<int> Order;
	int num;
	int price = 0;

	cout << "커피 개수 : ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		Order.push_back(1);
	}
	price += num * 2000;

	cout << "우유 개수 : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(2);
	price += num * 500;

	cout << "모카 개수 : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(3);
	price += num * 200;

	cout << "샷 개수 : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(4);
	price += num * 200;

	cout << "휘핑크림 개수 : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(5);
	price += num * 100;
	cout << "───────────────────" << endl;
	cout << "총 발주 금액은 " << price << "원 입니다." << endl; // 총 금액 출력

	if (slm->reduceMoney(price)) // 자본금이 충분할 경우
	{
		sm->addStockByIngredientsID(Order); // 재고를 추가
	}
	else
	{
		cout << "Error : 자본금이 부족합니다." << endl;
		return;
	}

	cout << "재료 발주에 성공했습니다." << endl;
	printStockStatus();
}

void ManagerFacade::printStockStatus()
{
	cout << "┌─────────────────┐" << endl;
	cout << "│             재고 확인            │" << endl;
	cout << "└─────────────────┘" << endl;
	sm->printStock();
}

void ManagerFacade::printTransactionStatus()
{
	cout << "┌─────────────────┐" << endl;
	cout << "│         주문 내역 확인           │" << endl;
	cout << "└─────────────────┘" << endl;
	if (otm->getOrderTransactionsNum() == 0)
	{
		cout << "Error : 주문 내역이 없습니다." << endl;
		return;
	}
	otm->printTransactions();
	cout << endl;
}