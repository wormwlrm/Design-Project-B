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
	cout << "┌─────────────────┐" << endl;
	cout << "│           메뉴 선택              │" << endl;
	cout << "└─────────────────┘" << endl;
	cout << "1. 아메리카노" << endl;
	cout << "2. 카푸치노" << endl;
	cout << "3. 모카커피" << endl;
	cout << "커피 아이디를 선택하세요. : " ; cin >> selectCoffee;
	cout << "───────────────────" << endl;
	if (cin.fail() || selectCoffee < 1 || selectCoffee > 3)
	{
		cout << "Error : 올바르지 않은 선택입니다." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "샷을 추가하시겠습니까? (Y/N) : "; cin >> selectShot;
	if (cin.fail() || (selectShot != 'Y' && selectShot != 'N'))
	{
		cout << "Error : 올바르지 않은 선택입니다." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "휘핑크림을 추가하시겠습니까? (Y/N) : "; cin >> selectWhip;
	cout << "───────────────────" << endl;
	if (cin.fail() || (selectWhip != 'Y' && selectWhip != 'N'))
	{
		cout << "Error : 올바르지 않은 선택입니다." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "┌─────────────────┐" << endl;
	cout << "│             할인 방법            │" << endl;
	cout << "└─────────────────┘" << endl;
	cout << "1. 매장에서 마시고 간다" << endl;
	cout << "2. 테이크 아웃한다" << endl;
	cout << "3. 쿠폰을 사용한다" << endl;
	cout << "할인 방법을 선택해주세요. : "; cin >> selectDiscount;
	cout << "───────────────────" << endl;
	if (cin.fail() || selectDiscount < 1 || selectDiscount > 3)
	{
		cout << "Error : 올바르지 않은 선택입니다." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	
	Coffee* orderdCoffee = cf.makeCoffee(selectCoffee); // 커피 팩토리에서 기본 커피 생성
	if (selectShot == 'Y')
	{
		orderdCoffee = new ShotDecorator(orderdCoffee); // 샷 데코레이터
	}
	
	if (selectWhip == 'Y')
	{
		orderdCoffee = new WhipDecorator(orderdCoffee); // 휘핑크림 데코레이터
	}

	if (!sm->reduceStockByIngredientsID(orderdCoffee->GetIngredientsID())) // 주문할 커피의 재료 재고 확인
	{
		cout << "Error : 재고가 부족합니다." << endl;
		return;
	}

	ppc.setDiscountAlgoritm(selectDiscount); // 할인 방법 선택
	int price = ppc.discountPrice(orderdCoffee->getCost()); // 최종 가격 계산
	cout << "금액 : " << price << endl;
	slm->addMoney(price); // 매니저의 자본금 추가
	Transaction T(orderdCoffee->GetIngredientsID(), price); // 주문 내역 생성
	otm->addTransaction(T);  // 주문 내역 추가
	cout << "주문이 완료되었습니다." << endl;

}

void CounterFacade::serveCoffee()
{
	if (otm->getOrderTransactionsNum() == 0)
	{
		cout << "Error : 주문 내역이 없습니다." << endl;
		return;
	}

	cout << "┌─────────────────┐" << endl;
	cout << "│             커피 제공            │" << endl;
	cout << "└─────────────────┘" << endl;
	cout << "주문하신 ";
	otm->getFrontTransaction().printCoffeeInfo(); // 커피 정보 출력
	cout << "나왔습니다." << endl;
	
	otm->deleteTransactionFromFront(); // 주문 내역에서 삭제
}

void CounterFacade::cancel()
{
	cout << "┌─────────────────┐" << endl;
	cout << "│             주문 취소            │" << endl;
	cout << "└─────────────────┘" << endl;
	if (otm->getOrderTransactionsNum() == 0)
	{
		cout << "Error : 주문 내역이 없습니다." << endl;
		return;
	}
	otm->printTransactions();
	cout << "───────────────────" << endl;
	cout << "취소할 주문 번호를 입력해주세요. : " ;
	int index;
	cin >> index;
	
	if (index + 1 > otm->getOrderTransactionsNum() || index < 0 || cin.fail())
	{
		cout << "Error : 올바르지 않은 선택입니다." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	Transaction* T = otm->getOrderTransactionsAt(index); // 인덱스의 주문 내역을 가리킬 포인터 
	sm->addStockByIngredientsID(T->getOrderedCoffeeInfo()); // 인덱스의 재료들을 다시 추가
	slm->reduceMoney(T->getPrice());  // 매니저의 돈을 감소
	otm->deleteTransactionByIndex(index); // 주문 내역에서 삭제

	cout << "주문 취소되었습니다." << endl;
	cout << "───────────────────" << endl;
	cout << "현재 주문 내역 : " << endl;
	if (otm->getOrderTransactionsNum() == 0) // 주문 내역 출력
	{
		cout << "Error : 주문 내역이 없습니다." << endl;
		return;
	}
	otm->printTransactions();

	return;	
}