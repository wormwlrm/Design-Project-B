#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class User
{
public:
	User();
	~User();
	void setUser(int _ID, string _PW);
	void addPurchasedAlbumID(int _ID);
	
	void printInfo() { cout << id << "	" << password << endl; };
	int getID() { return id; };
	string getPW() { return password; };

	vector<int>* getPurchasedList() { return &purchasedList; };
	void setID(int ID) { id = ID; }
	void setPW(string PW) { password = PW; };
	
private:
	int id;
	string password;
	vector<int> purchasedList;
};

