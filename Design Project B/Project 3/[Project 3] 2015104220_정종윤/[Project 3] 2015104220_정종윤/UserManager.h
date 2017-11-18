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
	bool addUserToFile(User addedUser); // ���ο� ������� ������ ���Ͽ� ����
	int authenticateUser(int _id, string _pw); // ����ڰ� �α��� �� ���̵�� ��й�ȣ�� �´��� Ȯ��
	vector<int> getPurchasedListByUserId(int _id); // ���̵� ���� ������ �ٹ� ����� ��ȯ
	vector<User> getAllUserList();	// ��� ������� ����� ��ȯ
	bool addAlbumIdToPurchaseList(int _userId, int _albumId); // �־��� ���̵��� ������� ���Ÿ�Ͽ� �ٹ� ���̵� �߰��ϰ������� ���ۼ�

	void printUserManager();
private:
	vector<User> userList;
};

