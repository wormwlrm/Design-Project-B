#pragma once
#include <string>
#include <iomanip>
using namespace std;

class MusicAlbum
{
public:
	MusicAlbum();
	~MusicAlbum();

	void setId(int _id) { id = _id; };
	void setName(string _name) { name = _name; };
	void setComposerId(int _id){ composerId = _id; };
	void setGenre(int _genre) { genre = _genre; };
	void setPurchasedCount(int _count) { purchasedCount = _count; };

	int getId(){ return id; };
	string getName() { return name; };
	int getComposerId() { return composerId; };
	int getGenre() { return genre; };
	int getPurchasedCount() { return purchasedCount; };

	string getGenreName();

private:
	int id;
	string name;
	int composerId;
	int genre;
	int purchasedCount;
};

