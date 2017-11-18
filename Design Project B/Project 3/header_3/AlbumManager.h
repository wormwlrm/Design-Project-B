#pragma once
#include "MusicAlbum.h"
#include "BaseManager.h"

class AlbumManager :
	public BaseManager
{
public:
	AlbumManager();
	~AlbumManager();

public:
	bool addMusicAlbumToFile(MusicAlbum addedMusicAlbum); // ���ο� �ٹ��� ������ ���Ͽ� ����
	MusicAlbum searchMusicAlbumByName(string _name); // �־��� �˻���� ��ġ�ϴ� �̸��� ���� �ٹ��� ��ȯ
	MusicAlbum searchMusicAlbumById(int _id); // �־��� ���̵�� ��ġ�ϴ� ���̵� ���� �ٹ��� ��ȯ
	bool updateMusicAlbumSellCount(int albumId); // �ٹ��� ���̵� �޾� �ٹ��� ���� Ƚ���� ���� �� ���Ͽ� ���ۼ�
	vector<MusicAlbum> getAllAlbumList(); // ��� �ٹ��� ������ �о� ����� ��ȯ
};

