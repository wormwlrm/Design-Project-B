#pragma once
//#include "BaseRecAlg.h"
#include "RecTopTen.h"
#include "RecMyAlg.h"
#include <iostream>
using namespace std;

class App
{
public:
	App();
	~App();

	void run();
	
	UserManager* getUserManager() { return um; };
	ComposerManager* getComposerManager() { return cm; };
	AlbumManager* getAlbumManager() { return am; };

private:
	void printUserMenu(); // ����� �޴� ���
	void printUserLoginMenu(); // ����� �α��� �޴� ���
	void printManagerMenu(); // ������ �޴� ���

	void userRegisteration(); // ���� ���
	void login(); // �α���
	void buyAlbum(); // �ٹ� ����
	void printPurchasedList(); // ���� ��� ���
	void recommend(); // ��õ

	void addComposer(); // ���ǰ� ���
	void addAlbum();// �ٹ� ���

	void searchById(); // ID�� �˻�
	void searchByName(); // �̸����� �˻�

private:
	BaseRecAlg* rcdAlg; // ��õ �˰��� Ŭ���� ������
	UserManager* um; // ����� �Ŵ��� ������
	ComposerManager* cm; // ���ǰ� �Ŵ��� ������
	AlbumManager* am; // �ٹ� �Ŵ��� ������
	int currentUserId; // ���� �α��� �� ����� ���̵�
};

