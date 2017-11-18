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
	void printUserMenu(); // ����� �޴� ���
	void printManagerMenu(); // ������ �޴� ���

	void userRegisteration(); // ���� ���
	void login(); // �α���
	void buyAlbum(); // �ٹ� ����
	void printPurchasedList(); // ���� ��� ���
	void recommend(); // ��õ

	void addComposer(); // ���ǰ� ���
	void addAlbum();// �ٹ� ���

private:
	BaseRecAlg* rcdAlg; // ��õ �˰��� Ŭ���� ������
	UserManager* um; // ����� �Ŵ��� ������
	ComposerManager* cm; // ���ǰ� �Ŵ��� ������
	AlbumManager* am; // �ٹ� �Ŵ��� ������
	int currentUserId; // ���� �α��� �� ����� ���̵�
};

