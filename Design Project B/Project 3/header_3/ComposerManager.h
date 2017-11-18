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
	bool addComposerToFile(Composer addedComposer); // ���ο� ���ǰ��� ������ ���Ͽ� ����
	Composer searchComposerByName(string _name); // �־��� �˻���� ��ġ�ϴ� �̸��� ���� ���ǰ��� ��ȯ
	Composer searchComposerById(int _id); // �־��� ���̵�� ��ġ�ϴ� ���̵� ���� ���ǰ��� ��ȯ
	vector<Composer> getAllComposerList(); // ��� ���ǰ� ������ �о� ����� ��ȯ

};

