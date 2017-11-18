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
	bool addMusicAlbumToFile(MusicAlbum addedMusicAlbum); // 새로운 앨범의 정보를 파일에 저장
	MusicAlbum searchMusicAlbumByName(string _name); // 주어진 검색어와 일치하는 이름을 가진 앨범을 반환
	MusicAlbum searchMusicAlbumById(int _id); // 주어진 아이디와 일치하는 아이디를 가진 앨범을 반환
	bool updateMusicAlbumSellCount(int albumId); // 앨범의 아이디를 받아 앨범의 구매 횟수를 갱신 및 파일에 재작성
	vector<MusicAlbum> getAllAlbumList(); // 모든 앨범의 정보를 읽어 목록을 반환
};

