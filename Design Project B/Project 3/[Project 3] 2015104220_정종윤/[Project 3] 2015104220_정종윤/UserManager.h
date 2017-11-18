#pragma once
#include "User.h"
#include "BaseManager.h"
#include <fstream>
class UserManager :
	public BaseManager
{
public:
	UserManager();
	~UserManager();

public:
	bool addUserToFile(User addedUser); // 새로운 사용자의 정보를 파일에 저장
	int authenticateUser(int _id, string _pw); // 사용자가 로그인 시 아이디와 비밀번호가 맞는지 확인
	vector<int> getPurchasedListByUserId(int _id); // 아이디를 통해 구매한 앨범 목록을 반환
	vector<User> getAllUserList();	// 모든 사용자의 목록을 반환
	bool addAlbumIdToPurchaseList(int _userId, int _albumId); // 주어진 아이디의 사용자의 구매목록에 앨범 아이디를 추가하고파일을 재작성

	void printUserManager();
private:
	vector<User> userList;
};

