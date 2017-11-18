#include "MusicAlbum.h"

MusicAlbum::MusicAlbum()
{

}

MusicAlbum::~MusicAlbum()
{

}

string MusicAlbum::getGenreName()
{
	switch (genre)
	{
	case 0:
		return "�ε�";
	case 1:
		return "��";
	case 2:
		return "�߶��";
	case 3:
		return "����";
	case 4:
		return "OST";
	default:
		break;
	}
	return "";
}


#include "AlbumManager.h"

AlbumManager::AlbumManager()
{
	//setFileName("MusicAlbum.dat");
	//ofstream fsOut(fileName, ios::binary | ios::out);
	//cout << "�� �����(���,���ǰ�,�帣)" << endl;
	//for (int i = 0; i < 20; i++)
	//{
	//	int ID = i;
	//	string Name; cin >> Name;
	//	int size = Name.size();
	//	int MusicianID; cin >> MusicianID;
	//	int Genre; cin >> Genre;
	//	int PurchasedNum = 0;

	//	fsOut.write((char*)&ID, sizeof(int)); // �ٹ� ID
	//	fsOut.write((char*)&size, sizeof(int)); // �̸� ����
	//	fsOut.write(Name.c_str(), Name.size()); // �̸�
	//	fsOut.write((char*)&MusicianID, sizeof(int)); // ���ǰ� ID
	//	fsOut.write((char*)&Genre, sizeof(int)); // �帣
	//	fsOut.write((char*)&PurchasedNum, sizeof(int)); // ���� Ƚ��
	//}

	//fsOut.close();
}

AlbumManager::~AlbumManager()
{
	
}

bool AlbumManager::addMusicAlbumToFile(MusicAlbum addedMusicAlbum)
{
	setFileName("MusicAlbum.dat");
	string newName = addedMusicAlbum.getName();
	int newID;
	int newNameSize;
	int newMusicianID = addedMusicAlbum.getComposerId();
	int newGenre = addedMusicAlbum.getGenre();
	int newPurchasedNum = 0;

	ifstream fsIn(fileName, ios::binary | ios::in); // �� �� ° ID���� ��ϵǾ����� Ȯ��
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // �ٹ� ���̵�
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ����
		fsIn.seekg(newNameSize, ios::cur); // �̸� ���̸�ŭ �ǳ� ��
		fsIn.seekg(12, ios::cur); // ���ǰ� ID, �帣, ����Ƚ�� �ǳ� ��
	}
	fsIn.close();
	newID++; // ���� ����� ID
	newNameSize = newName.size();

	ofstream fsOut(fileName, ios::binary | ios::out | ios::app); // dat�� ���
	fsOut.seekp(0, ios::end);
	fsOut.write((char*)&newID, sizeof(int)); // ID
	fsOut.write((char*)&newNameSize, sizeof(int)); // �̸� ������
	fsOut.write(newName.c_str(), newNameSize); // �̸�
	fsOut.write((char*)&newMusicianID, sizeof(int)); // ���ǰ� ID
	fsOut.write((char*)&newGenre, sizeof(int)); // �帣
	fsOut.write((char*)&newPurchasedNum, sizeof(int)); // ���� Ƚ��
	fsOut.close();
	return true;
}

MusicAlbum AlbumManager::searchMusicAlbumByName(string _name) 
{
	setFileName("MusicAlbum.dat");
	int newID;
	int newNameSize;
	string newName;
	int newMusicianID;
	int newGenre;
	int newPurchasedNum;

	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�
		fsIn.read((char*)&newMusicianID, sizeof(int)); // ���ǰ� ID
		fsIn.read((char*)&newGenre, sizeof(int)); // �帣
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // ����Ƚ��

		if (newName == _name) // �̸��� ���� �ٹ� �߰� ��
		{
			fsIn.close();
			MusicAlbum newAlbum;
			newAlbum.setId(newID);
			newAlbum.setName(newName);
			newAlbum.setComposerId(newMusicianID);
			newAlbum.setGenre(newGenre);
			newAlbum.setPurchasedCount(newPurchasedNum);
			return newAlbum;
		}		
	}
	//�� ã���� ���
	cout << "Error : �˻� ����� �������� �ʽ��ϴ�." << endl;
	fsIn.close();
	return MusicAlbum();
}

MusicAlbum AlbumManager::searchMusicAlbumById(int _id)
{
	setFileName("MusicAlbum.dat");
	int newID;
	int newNameSize;
	string newName;
	int newMusicianID;
	int newGenre;
	int newPurchasedNum;

	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�
		fsIn.read((char*)&newMusicianID, sizeof(int)); // ���ǰ� ID
		fsIn.read((char*)&newGenre, sizeof(int)); // �帣
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // ����Ƚ��

		if (newID == _id) // ID�� ���� �ٹ� �߰� ��
		{
			fsIn.close();
			MusicAlbum newAlbum;
			newAlbum.setId(newID);
			newAlbum.setName(newName);
			newAlbum.setComposerId(newMusicianID);
			newAlbum.setGenre(newGenre);
			newAlbum.setPurchasedCount(newPurchasedNum);
			return newAlbum;
		}

	}
	//�� ã���� ���
	cout << "Error : �˻� ����� �������� �ʽ��ϴ�." << endl;
	fsIn.close();
	return MusicAlbum();
}

bool AlbumManager::updateMusicAlbumSellCount(int albumId) 
{
	setFileName("MusicAlbum.dat");
	int newID;
	int newNameSize;
	string newName;
	int newMusicianID;
	int newGenre;
	int newPurchasedNum;

	fstream fsIO(fileName, ios::binary | ios::in | ios::out);
	while (true)
	{
		fsIO.read((char*)&newID, sizeof(int)); // ID
		if (fsIO.eof())
			break;
		fsIO.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIO.read(&newName[0], newNameSize); // �̸�
		fsIO.read((char*)&newMusicianID, sizeof(int)); // ���ǰ� ID
		fsIO.read((char*)&newGenre, sizeof(int)); // �帣
		fsIO.read((char*)&newPurchasedNum, sizeof(int)); // ����Ƚ��
		
		if (newID == albumId) // ID�� ���� �ٹ� �߰� �� ���� Ƚ�� �ٲٰ� ����
		{
			fsIO.seekp(-4, ios::cur);
			newPurchasedNum++; // ���� Ƚ�� ++
			fsIO.write((char*)&newPurchasedNum, sizeof(int)); // �����
			fsIO.close();
			return true;
		}
	}
	fsIO.close();
	return false;
}

vector<MusicAlbum> AlbumManager::getAllAlbumList()
{
	vector<MusicAlbum> AlbumList; // ��ȯ�� ��ü �ٹ� ����Ʈ ����

	setFileName("MusicAlbum.dat");
	int newID;
	int newNameSize;
	string newName;
	int newMusicianID;
	int newGenre;
	int newPurchasedNum;

	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�
		fsIn.read((char*)&newMusicianID, sizeof(int)); // ���ǰ� ID
		fsIn.read((char*)&newGenre, sizeof(int)); // �帣
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // ����Ƚ��
		
		MusicAlbum newAlbum; // �ٹ� ����
		newAlbum.setId(newID);
		newAlbum.setName(newName);
		newAlbum.setComposerId(newMusicianID);
		newAlbum.setGenre(newGenre);
		newAlbum.setPurchasedCount(newPurchasedNum);

		AlbumList.push_back(newAlbum);
	}
	return AlbumList;
}

void AlbumManager::printAlbumManager()
{
	setFileName("MusicAlbum.dat");
	int newID;
	int newNameSize;
	string newName;
	int newMusicianID;
	int newGenre;
	int newPurchasedNum;
	string newGenreString;
	ComposerManager Musician;

	ifstream fsIn(fileName, ios::binary | ios::in);
	cout << "���̵�        ���    ���ǰ�     �帣  ����Ƚ�� " << endl;
	cout << "������������������������������������������" << endl;
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�
		fsIn.read((char*)&newMusicianID, sizeof(int)); // ���ǰ� ID
		fsIn.read((char*)&newGenre, sizeof(int)); // �帣
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // ����Ƚ��

		switch (newGenre)
		{
		case 0:
			newGenreString = "�ε�"; 
			break;
		case 1:
			newGenreString = "��";
			break;
		case 2:
			newGenreString = "�߶��";
			break;
		case 3:
			newGenreString = "����";
			break;
		case 4:
			newGenreString = "OST";
			break;
		default:
			break;
		}		
		cout << setw(2) << newID << " " << setw(16) << newName << " " << setw(12) << Musician.searchComposerById(newMusicianID).getName() << " " << setw(6) << newGenreString <<" " << setw(3) << newPurchasedNum << endl;
	}	
}