#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User();
	~User();

private:
	int id;
	string password;
	vector<int> purcahsedList;
};

