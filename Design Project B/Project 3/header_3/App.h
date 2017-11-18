#pragma once
//#include "BaseRecAlg.h"
#include "RecTopTen.h"
class App
{
public:
	App();
	~App();

	void run();
	
private:
	void printUserMenu(); // 사용자 메뉴 출력
	void printManagerMenu(); // 관리자 메뉴 출력

	void userRegisteration(); // 유저 등록
	void login(); // 로그인
	void buyAlbum(); // 앨범 구매
	void printPurchasedList(); // 구매 목록 출력
	void recommend(); // 추천

	void addComposer(); // 음악가 등록
	void addAlbum();// 앨범 등록

private:
	BaseRecAlg* rcdAlg; // 추천 알고리즘 클래스 포인터
	UserManager* um; // 사용자 매니저 포인터
	ComposerManager* cm; // 음악가 매니저 포인터
	AlbumManager* am; // 앨범 매니저 포인터
	int currentUserId; // 현재 로그인 된 사용자 아이디
};

