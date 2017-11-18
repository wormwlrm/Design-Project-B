#pragma once
#include "Composer.h"
#include "BaseManager.h"
#include <fstream>
class ComposerManager :
	public BaseManager
{
public:
	ComposerManager();
	~ComposerManager();

public:
	bool addComposerToFile(Composer addedComposer); // 새로운 음악가의 정보를 파일에 저장
	Composer searchComposerByName(string _name); // 주어진 검색어와 일치하는 이름을 가진 음악가를 반환
	Composer searchComposerById(int _id); // 주어진 아이디와 일치하는 아이디를 가진 음악가를 반환
	vector<Composer> getAllComposerList(); // 모든 음악가 정보를 읽어 목록을 반환

};

