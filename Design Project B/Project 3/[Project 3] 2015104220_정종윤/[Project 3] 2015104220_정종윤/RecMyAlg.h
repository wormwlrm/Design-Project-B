#pragma once
#include "BaseRecAlg.h"
class RecMyAlg :
	public BaseRecAlg
{
public:
	RecMyAlg();
	~RecMyAlg();

	virtual vector<MusicAlbum> recommend(int id);
};

