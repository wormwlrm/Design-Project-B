#pragma once
//#include "MusicAlbum.h"
#include "AlbumManager.h"
#include "UserManager.h"
#include "ComposerManager.h"
#include <vector>
#include <iostream>
class BaseRecAlg
{
public:
	BaseRecAlg();
	~BaseRecAlg();

	virtual vector<MusicAlbum> recommend(int id) = 0;

protected:

};

