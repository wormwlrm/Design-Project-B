#include "App.h"

App::App()
{
	cf = new CounterFacade();
	mf = new ManagerFacade(cf->getotm(), cf->getsm(), cf->getslm());
}

App::~App()
{

}

void App::run()
{
	int choice;
	bool CounterMode, ManagerMode;
	cout << "��������������������������������������" << endl;
	cout << "��������������������������������������" << endl;
	cout << "������Ŀ�Ǽ� �Ŵ�����Ʈ ���α׷�����" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��������������������������������������" << endl;
	while (true)
	{
		cout << "1. ���� �޴�" << endl;
		cout << "2. ���� �޴�" << endl;
		cout << "��������������������������������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			CounterMode = true;
			while (CounterMode)
			{
				cout << "��������������������������������������" << endl;
				cout << "��            ���� �޴�             ��" << endl;
				cout << "��������������������������������������" << endl;
				cout << "1. �ֹ� �ޱ�" << endl;
				cout << "2. Ŀ�� ����" << endl;
				cout << "3. �ֹ� ���" << endl;
				cout << "4. �ǵ��ư���" << endl;
				cout << "��������������������������������������" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1: // �ֹ� �ޱ�
					cf->order();
					break;
				case 2: // Ŀ�� ����
					cf->serveCoffee();
					break;
				case 3: // �ֹ� ���
					cf->cancel();
					break;
				case 4: // �ǵ��ư���
					CounterMode = false;
					break;
				default: // �߸��� �Է� ���� ó��
					if (cin.fail())
					{
						cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						break;
					}
					cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;

					break;
				}
			}
			break;
		case 2:
			ManagerMode = true;
			while (ManagerMode)
			{
				cout << "��������������������������������������" << endl;
				cout << "��            ���� �޴�             ��" << endl;
				cout << "��������������������������������������" << endl;
				cout << "���� �ں��� : " << mf->getslm()->getPrice() << "��" << endl;
				cout << "1. ��� ����" << endl;
				cout << "2. ��� Ȯ��" << endl;
				cout << "3. �ֹ� ���� Ȯ��" << endl;
				cout << "4. �ǵ��ư���" << endl;
				cin >> choice;
				cout << "��������������������������������������" << endl;
				switch (choice)
				{
				case 1: // ��� ����
					mf->orderIngredients();
					break;
				case 2: // ��� Ȯ��
					mf->printStockStatus();
					break;
				case 3: // �ֹ� ���� Ȯ��
					mf->printTransactionStatus();
					break;
				case 4: // �ǵ��ư���
					ManagerMode = false;
					break;
				default: // �߸��� �Է� ���� ó��
					if (cin.fail())
					{
						cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						break;
					}
					cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
					break;
				}
			}
			break;
		default: // �߸��� �Է� ���� ó��
			if (cin.fail())
			{
				cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			break;
		}
	}
}