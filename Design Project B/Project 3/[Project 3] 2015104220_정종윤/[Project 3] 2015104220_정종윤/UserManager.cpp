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
	//초기값 설정

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
	//	fsOut.write((char*)&size, sizeof(int)); // 패스워드 사이즈
	//	fsOut.write(PW.c_str(), PW.size()); // 패스워드
	//	fsOut.write((char*)&albumListSize, sizeof(int)); // 구매 목록 개수
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
		fsIn.read((char*)&ID, sizeof(int)); // 아이디
		if (fsIn.eof())
			break;
		fsIn.read((char*)&size, sizeof(int)); // 비밀번호 길이
		PW.resize(size);
		fsIn.read(&PW[0], size); // 비밀번호
		fsIn.read((char*)&albumListSize, sizeof(int)); // 구매 목록 개수
	
		newUser.setUser(ID, PW);
		
		if (albumListSize > 0)
		{
			for (int j = 0; j < albumListSize; j++)
			{
				fsIn.read((char*)&purchasedAlbumID, sizeof(int)); // 구매한 음반 아이디
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

bool UserManager::addUserToFile(User addedUser) // 새로운 사용자의 정보를 파일에 저장
{
	userList.push_back(addedUser);
	int newID = addedUser.getID();
	int newPWsize = addedUser.getPW().size();
	string newPW = addedUser.getPW();
	int albumListSize = 0;

	ofstream fsOut("User.dat", ios::binary | ios::out | ios::app);
	fsOut.seekp(0, ios::end);

	fsOut.write((char*)&newID, sizeof(int)); // ID
	fsOut.write((char*)&newPWsize, sizeof(int)); // 패스워드 사이즈
	fsOut.write(newPW.c_str(), newPWsize); // 패스워드
	fsOut.write((char*)&albumListSize, sizeof(int)); // 구매 목록 개수

	fsOut.close();

	return true;
}

int UserManager::authenticateUser(int _id, string _pw) // 사용자가 로그인 시 아이디와 비밀번호가 맞는지 확인
{
	for (int i = 0; (unsigned)i < userList.size(); i++) // 아이디 탐색
	{
		if (userList.at(i).getID() == _id) // 아이디 확인
		{
			if (userList.at(i).getPW() == _pw) // 비밀번호 확인
			{
				return 1;
			}
			return 2;
		}
	}
	return 3;
}

vector<int> UserManager::getPurchasedListByUserId(int _id) // 아이디를 통해 구매한 앨범 목록을 반환
{
	return *userList.at(_id).getPurchasedList();
}

vector<User> UserManager::getAllUserList()	// 모든 사용자의 목록을 반환
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
		fsOut.write((char*)&size, sizeof(int)); // 패스워드 사이즈
		fsOut.write(PW.c_str(), PW.size()); // 패스워드
		fsOut.write((char*)&albumListSize, sizeof(int)); // 구매 목록 개수

		if (albumListSize > 0)
		{
			for (int j = 0; j < albumListSize; j++)
			{
				purchasedAlbumID = (userList.at(i).getPurchasedList())->at(j);
				fsOut.write((char*)&purchasedAlbumID, sizeof(int)); // 구매한 음반 아이디
			}
		}
	}

	fsOut.close();
	return true;
}

void UserManager::printUserManager()
{
	cout << "아이디     비밀번호" << endl;
	cout << "─────────────────────" << endl;
	for (int i = 0; (unsigned)i < userList.size(); i++)
	{
		userList.at(i).printInfo();
	}
}