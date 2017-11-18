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
	cout << "┌─────────────────┐" << endl;
	cout << "│┌───────────────┐│" << endl;
	cout << "││≪커피숍 매니지먼트 프로그램≫││" << endl;
	cout << "│└───────────────┘│" << endl;
	cout << "└─────────────────┘" << endl;
	while (true)
	{
		cout << "1. 점원 메뉴" << endl;
		cout << "2. 점장 메뉴" << endl;
		cout << "───────────────────" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			CounterMode = true;
			while (CounterMode)
			{
				cout << "┌─────────────────┐" << endl;
				cout << "│            점원 메뉴             │" << endl;
				cout << "└─────────────────┘" << endl;
				cout << "1. 주문 받기" << endl;
				cout << "2. 커피 제공" << endl;
				cout << "3. 주문 취소" << endl;
				cout << "4. 되돌아가기" << endl;
				cout << "───────────────────" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1: // 주문 받기
					cf->order();
					break;
				case 2: // 커피 제공
					cf->serveCoffee();
					break;
				case 3: // 주문 취소
					cf->cancel();
					break;
				case 4: // 되돌아가기
					CounterMode = false;
					break;
				default: // 잘못된 입력 예외 처리
					if (cin.fail())
					{
						cout << "Error : 올바르지 않은 선택입니다." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						break;
					}
					cout << "Error : 올바르지 않은 선택입니다." << endl;

					break;
				}
			}
			break;
		case 2:
			ManagerMode = true;
			while (ManagerMode)
			{
				cout << "┌─────────────────┐" << endl;
				cout << "│            점장 메뉴             │" << endl;
				cout << "└─────────────────┘" << endl;
				cout << "현재 자본금 : " << mf->getslm()->getPrice() << "원" << endl;
				cout << "1. 재료 발주" << endl;
				cout << "2. 재고 확인" << endl;
				cout << "3. 주문 내역 확인" << endl;
				cout << "4. 되돌아가기" << endl;
				cin >> choice;
				cout << "───────────────────" << endl;
				switch (choice)
				{
				case 1: // 재료 발주
					mf->orderIngredients();
					break;
				case 2: // 재고 확인
					mf->printStockStatus();
					break;
				case 3: // 주문 내역 확인
					mf->printTransactionStatus();
					break;
				case 4: // 되돌아가기
					ManagerMode = false;
					break;
				default: // 잘못된 입력 예외 처리
					if (cin.fail())
					{
						cout << "Error : 올바르지 않은 선택입니다." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						break;
					}
					cout << "Error : 올바르지 않은 선택입니다." << endl;
					break;
				}
			}
			break;
		default: // 잘못된 입력 예외 처리
			if (cin.fail())
			{
				cout << "Error : 올바르지 않은 선택입니다." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : 올바르지 않은 선택입니다." << endl;
			break;
		}
	}
}