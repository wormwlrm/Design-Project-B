#include "Composer.h"

Composer::Composer()
{

}

Composer::~Composer()
{

}


#include "ComposerManager.h"

ComposerManager::ComposerManager()
{
	//setFileName("Composer.dat");
	//ofstream fsOut(fileName, ios::binary | ios::out);
	//cout << "음악가 만들기(이름)" << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	int ID = i;
	//	string Name; cin >> Name;
	//	int size = Name.size();
	//	
	//	fsOut.write((char*)&ID, sizeof(int)); // 음악가ID
	//	fsOut.write((char*)&size, sizeof(int)); // 이름 길이
	//	fsOut.write(Name.c_str(), Name.size()); // 이름
	//}

	//fsOut.close();
}

ComposerManager::~ComposerManager()
{

}

bool ComposerManager::addComposerToFile(Composer addedComposer)
{
	setFileName("Composer.dat");
	string newName = addedComposer.getName();
	int newID;
	int newNameSize;

	ifstream fsIn(fileName, ios::binary | ios::in); // 몇 번 째 ID까지 등록되었는지 확인
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int));
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int));
		fsIn.seekg(newNameSize, ios::cur);
	}
	fsIn.close();
	newID++; // 새로 등록할 ID
	newNameSize = newName.size();

	ofstream fsOut(fileName, ios::binary | ios::out | ios::app); // dat에 등록
	fsOut.seekp(0, ios::end);
	fsOut.write((char*)&newID, sizeof(int)); // ID
	fsOut.write((char*)&newNameSize, sizeof(int)); // 패스워드 사이즈
	fsOut.write(newName.c_str(), newNameSize); // 패스워드
	fsOut.close();
	return true;
}

Composer ComposerManager::searchComposerByName(string _name)
{
	setFileName("Composer.dat");
	int newID;
	int newNameSize;
	string newName;

	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름

		if (newName == _name) // 이름이 같은 앨범 발견 시
		{
			fsIn.close();
			Composer newComposer;
			newComposer.setId(newID);
			newComposer.setName(newName);
			return newComposer;
		}
	}
	//못 찾았을 경우

	fsIn.close();
	return Composer();
}

Composer ComposerManager::searchComposerById(int _id)
{
	setFileName("Composer.dat");
	int newID;
	int newNameSize;
	string newName;

	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름

		if (newID == _id) // 이름이 같은 앨범 발견 시
		{
			fsIn.close();
			Composer newComposer;
			newComposer.setId(newID);
			newComposer.setName(newName);
			return newComposer;
		}
	}
	//못 찾았을 경우

	fsIn.close();
	return Composer();
}

vector<Composer> ComposerManager::getAllComposerList()
{
	vector<Composer> ComposerList;

	setFileName("Composer.dat");
	int newID;
	int newNameSize;
	string newName;

	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름

		Composer newComposer; // 음악가 생성
		newComposer.setId(newID);
		newComposer.setName(newName);

		ComposerList.push_back(newComposer);
	}
	return ComposerList;
}

void ComposerManager::printComposerManager()
{
	setFileName("Composer.dat");
	int newID;
	int newNameSize;
	string newName;
	cout << "아이디         음악가  " << endl;
	cout << "─────────────────────" << endl;
	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름

		cout << setw(3) <<  newID  << setw(20) << newName << endl;
	}
	fsIn.close();
}