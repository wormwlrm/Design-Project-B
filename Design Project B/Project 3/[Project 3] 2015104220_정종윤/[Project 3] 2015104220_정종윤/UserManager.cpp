#include "User.h"

User::User()
{

}

User::~User()
{

}

void User::setUser(int _ID, string _PW)
{
	id = _ID;
	password = _PW;
}

void User::addPurchasedAlbumID(int _ID)
{
	purchasedList.push_back(_ID);
}

#include "UserManager.h"

UserManager::UserManager()
{
	//�ʱⰪ ����

	//setFileName("User.dat");
	//ofstream fsOut(fileName, ios::binary | ios::out);
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	int ID = i;
	//	string PW = "password";
	//	int size = PW.size();
	//	int albumListSize = 0;

	//	fsOut.write((char*)&ID, sizeof(int)); // ID
	//	fsOut.write((char*)&size, sizeof(int)); // �н����� ������
	//	fsOut.write(PW.c_str(), PW.size()); // �н�����
	//	fsOut.write((char*)&albumListSize, sizeof(int)); // ���� ��� ����
	//}

	/*fsOut.close();*/
	
	setFileName("User.dat");
	ifstream fsIn(fileName, ios::binary | ios::in);

	int ID;
	string PW;
	int size;
	int albumListSize;
	int purchasedAlbumID;

	while (true)
	{
		User newUser;
		fsIn.read((char*)&ID, sizeof(int)); // ���̵�
		if (fsIn.eof())
			break;
		fsIn.read((char*)&size, sizeof(int)); // ��й�ȣ ����
		PW.resize(size);
		fsIn.read(&PW[0], size); // ��й�ȣ
		fsIn.read((char*)&albumListSize, sizeof(int)); // ���� ��� ����
	
		newUser.setUser(ID, PW);
		
		if (albumListSize > 0)
		{
			for (int j = 0; j < albumListSize; j++)
			{
				fsIn.read((char*)&purchasedAlbumID, sizeof(int)); // ������ ���� ���̵�
				newUser.addPurchasedAlbumID(purchasedAlbumID);
			}
		}
		userList.push_back(newUser);		
	}

	fsIn.close();
}

UserManager::~UserManager()
{

}

bool UserManager::addUserToFile(User addedUser) // ���ο� ������� ������ ���Ͽ� ����
{
	userList.push_back(addedUser);
	int newID = addedUser.getID();
	int newPWsize = addedUser.getPW().size();
	string newPW = addedUser.getPW();
	int albumListSize = 0;

	ofstream fsOut("User.dat", ios::binary | ios::out | ios::app);
	fsOut.seekp(0, ios::end);

	fsOut.write((char*)&newID, sizeof(int)); // ID
	fsOut.write((char*)&newPWsize, sizeof(int)); // �н����� ������
	fsOut.write(newPW.c_str(), newPWsize); // �н�����
	fsOut.write((char*)&albumListSize, sizeof(int)); // ���� ��� ����

	fsOut.close();

	return true;
}

int UserManager::authenticateUser(int _id, string _pw) // ����ڰ� �α��� �� ���̵�� ��й�ȣ�� �´��� Ȯ��
{
	for (int i = 0; (unsigned)i < userList.size(); i++) // ���̵� Ž��
	{
		if (userList.at(i).getID() == _id) // ���̵� Ȯ��
		{
			if (userList.at(i).getPW() == _pw) // ��й�ȣ Ȯ��
			{
				return 1;
			}
			return 2;
		}
	}
	return 3;
}

vector<int> UserManager::getPurchasedListByUserId(int _id) // ���̵� ���� ������ �ٹ� ����� ��ȯ
{
	return *userList.at(_id).getPurchasedList();
}

vector<User> UserManager::getAllUserList()	// ��� ������� ����� ��ȯ
{
	return userList;
}

bool UserManager::addAlbumIdToPurchaseList(int _userId, int _albumId)
{
	setFileName("User.dat");
	fstream fsOut(fileName, ios::binary | ios::out | ios::in);

	int ID;
	string PW;
	int size;
	int albumListSize;
	int purchasedAlbumID;
	
	for (int i = 0; (unsigned)i < userList.size(); i++)
	{
		ID = userList.at(i).getID();
		PW = userList.at(i).getPW();
		size = userList.at(i).getPW().size();
		albumListSize = (userList.at(i).getPurchasedList())->size();

		if (ID == _userId)
		{
			(userList.at(i).getPurchasedList())->push_back(_albumId);
			albumListSize = (userList.at(i).getPurchasedList())->size();
		}

		fsOut.write((char*)&ID, sizeof(int)); // ID
		fsOut.write((char*)&size, sizeof(int)); // �н����� ������
		fsOut.write(PW.c_str(), PW.size()); // �н�����
		fsOut.write((char*)&albumListSize, sizeof(int)); // ���� ��� ����

		if (albumListSize > 0)
		{
			for (int j = 0; j < albumListSize; j++)
			{
				purchasedAlbumID = (userList.at(i).getPurchasedList())->at(j);
				fsOut.write((char*)&purchasedAlbumID, sizeof(int)); // ������ ���� ���̵�
			}
		}
	}

	fsOut.close();
	return true;
}

void UserManager::printUserManager()
{
	cout << "���̵�     ��й�ȣ" << endl;
	cout << "������������������������������������������" << endl;
	for (int i = 0; (unsigned)i < userList.size(); i++)
	{
		userList.at(i).printInfo();
	}
}