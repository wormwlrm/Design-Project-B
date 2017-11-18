#pragma once
#include "BaseRecAlg.h"
class RecTopTen :
	public BaseRecAlg
{
public:
	RecTopTen();
	~RecTopTen();

	virtual vector<MusicAlbum> recommend(int id);
};

