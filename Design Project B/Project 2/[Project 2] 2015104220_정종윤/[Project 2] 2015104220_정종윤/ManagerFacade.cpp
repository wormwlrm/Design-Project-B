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
	cout << "��������������������������������������" << endl;
	cout << "��             ��� ����            ��" << endl;
	cout << "��������������������������������������" << endl;
	vector<int> Order;
	int num;
	int price = 0;

	cout << "Ŀ�� ���� : ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		Order.push_back(1);
	}
	price += num * 2000;

	cout << "���� ���� : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(2);
	price += num * 500;

	cout << "��ī ���� : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(3);
	price += num * 200;

	cout << "�� ���� : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(4);
	price += num * 200;

	cout << "����ũ�� ���� : ";
	cin >> num;
	for (int i = 0; i < num; i++)
		Order.push_back(5);
	price += num * 100;
	cout << "��������������������������������������" << endl;
	cout << "�� ���� �ݾ��� " << price << "�� �Դϴ�." << endl; // �� �ݾ� ���

	if (slm->reduceMoney(price)) // �ں����� ����� ���
	{
		sm->addStockByIngredientsID(Order); // ��� �߰�
	}
	else
	{
		cout << "Error : �ں����� �����մϴ�." << endl;
		return;
	}

	cout << "��� ���ֿ� �����߽��ϴ�." << endl;
	printStockStatus();
}

void ManagerFacade::printStockStatus()
{
	cout << "��������������������������������������" << endl;
	cout << "��             ��� Ȯ��            ��" << endl;
	cout << "��������������������������������������" << endl;
	sm->printStock();
}

void ManagerFacade::printTransactionStatus()
{
	cout << "��������������������������������������" << endl;
	cout << "��         �ֹ� ���� Ȯ��           ��" << endl;
	cout << "��������������������������������������" << endl;
	if (otm->getOrderTransactionsNum() == 0)
	{
		cout << "Error : �ֹ� ������ �����ϴ�." << endl;
		return;
	}
	otm->printTransactions();
	cout << endl;
}