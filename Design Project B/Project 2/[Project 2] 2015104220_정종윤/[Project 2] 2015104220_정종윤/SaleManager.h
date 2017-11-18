#pragma once
class SaleManager
{
public:
	SaleManager();
	~SaleManager();

	void addMoney(int money);
	bool reduceMoney(int money);
	int getPrice();

private:
	int price;
};

