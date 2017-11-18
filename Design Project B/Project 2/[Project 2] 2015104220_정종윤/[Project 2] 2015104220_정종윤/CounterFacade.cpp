#include "CounterFacade.h"

CounterFacade::CounterFacade()
{
	sm = new StockManager();
	slm = new SaleManager();
	otm = new OrderTransactionManager();
}

CounterFacade::~CounterFacade()
{

}

CounterFacade::CounterFacade(OrderTransactionManager* _otm, StockManager* _sm, SaleManager* _slm)
{
	otm = _otm;
	sm = _sm;
	slm = _slm;
}

void CounterFacade::order()
{
	int selectCoffee, selectDiscount;
	char selectShot, selectWhip;
	cout << "��������������������������������������" << endl;
	cout << "��           �޴� ����              ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "1. �Ƹ޸�ī��" << endl;
	cout << "2. īǪġ��" << endl;
	cout << "3. ��īĿ��" << endl;
	cout << "Ŀ�� ���̵� �����ϼ���. : " ; cin >> selectCoffee;
	cout << "��������������������������������������" << endl;
	if (cin.fail() || selectCoffee < 1 || selectCoffee > 3)
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "���� �߰��Ͻðڽ��ϱ�? (Y/N) : "; cin >> selectShot;
	if (cin.fail() || (selectShot != 'Y' && selectShot != 'N'))
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "����ũ���� �߰��Ͻðڽ��ϱ�? (Y/N) : "; cin >> selectWhip;
	cout << "��������������������������������������" << endl;
	if (cin.fail() || (selectWhip != 'Y' && selectWhip != 'N'))
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "��������������������������������������" << endl;
	cout << "��             ���� ���            ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "1. ���忡�� ���ð� ����" << endl;
	cout << "2. ����ũ �ƿ��Ѵ�" << endl;
	cout << "3. ������ ����Ѵ�" << endl;
	cout << "���� ����� �������ּ���. : "; cin >> selectDiscount;
	cout << "��������������������������������������" << endl;
	if (cin.fail() || selectDiscount < 1 || selectDiscount > 3)
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	
	Coffee* orderdCoffee = cf.makeCoffee(selectCoffee); // Ŀ�� ���丮���� �⺻ Ŀ�� ����
	if (selectShot == 'Y')
	{
		orderdCoffee = new ShotDecorator(orderdCoffee); // �� ���ڷ�����
	}
	
	if (selectWhip == 'Y')
	{
		orderdCoffee = new WhipDecorator(orderdCoffee); // ����ũ�� ���ڷ�����
	}

	if (!sm->reduceStockByIngredientsID(orderdCoffee->GetIngredientsID())) // �ֹ��� Ŀ���� ��� ��� Ȯ��
	{
		cout << "Error : ��� �����մϴ�." << endl;
		return;
	}

	ppc.setDiscountAlgoritm(selectDiscount); // ���� ��� ����
	int price = ppc.discountPrice(orderdCoffee->getCost()); // ���� ���� ���
	cout << "�ݾ� : " << price << endl;
	slm->addMoney(price); // �Ŵ����� �ں��� �߰�
	Transaction T(orderdCoffee->GetIngredientsID(), price); // �ֹ� ���� ����
	otm->addTransaction(T);  // �ֹ� ���� �߰�
	cout << "�ֹ��� �Ϸ�Ǿ����ϴ�." << endl;

}

void CounterFacade::serveCoffee()
{
	if (otm->getOrderTransactionsNum() == 0)
	{
		cout << "Error : �ֹ� ������ �����ϴ�." << endl;
		return;
	}

	cout << "��������������������������������������" << endl;
	cout << "��             Ŀ�� ����            ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "�ֹ��Ͻ� ";
	otm->getFrontTransaction().printCoffeeInfo(); // Ŀ�� ���� ���
	cout << "���Խ��ϴ�." << endl;
	
	otm->deleteTransactionFromFront(); // �ֹ� �������� ����
}

void CounterFacade::cancel()
{
	cout << "��������������������������������������" << endl;
	cout << "��             �ֹ� ���            ��" << endl;
	cout << "��������������������������������������" << endl;
	if (otm->getOrderTransactionsNum() == 0)
	{
		cout << "Error : �ֹ� ������ �����ϴ�." << endl;
		return;
	}
	otm->printTransactions();
	cout << "��������������������������������������" << endl;
	cout << "����� �ֹ� ��ȣ�� �Է����ּ���. : " ;
	int index;
	cin >> index;
	
	if (index + 1 > otm->getOrderTransactionsNum() || index < 0 || cin.fail())
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	Transaction* T = otm->getOrderTransactionsAt(index); // �ε����� �ֹ� ������ ����ų ������ 
	sm->addStockByIngredientsID(T->getOrderedCoffeeInfo()); // �ε����� ������ �ٽ� �߰�
	slm->reduceMoney(T->getPrice());  // �Ŵ����� ���� ����
	otm->deleteTransactionByIndex(index); // �ֹ� �������� ����

	cout << "�ֹ� ��ҵǾ����ϴ�." << endl;
	cout << "��������������������������������������" << endl;
	cout << "���� �ֹ� ���� : " << endl;
	if (otm->getOrderTransactionsNum() == 0) // �ֹ� ���� ���
	{
		cout << "Error : �ֹ� ������ �����ϴ�." << endl;
		return;
	}
	otm->printTransactions();

	return;	
}