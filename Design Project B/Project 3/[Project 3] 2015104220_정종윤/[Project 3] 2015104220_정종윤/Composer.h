#pragma once
#include <string>
using namespace std;

class Composer
{
public:
	Composer();
	~Composer();

	void setId(int _id) { id = _id; };
	void setName(string _name){ name = _name; };
	int getId() { return id; };
	string getName() { return name; };

private:
	int id;
	string name;
};

