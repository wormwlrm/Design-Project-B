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
	//cout << "���ǰ� �����(�̸�)" << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	int ID = i;
	//	string Name; cin >> Name;
	//	int size = Name.size();
	//	
	//	fsOut.write((char*)&ID, sizeof(int)); // ���ǰ�ID
	//	fsOut.write((char*)&size, sizeof(int)); // �̸� ����
	//	fsOut.write(Name.c_str(), Name.size()); // �̸�
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

	ifstream fsIn(fileName, ios::binary | ios::in); // �� �� ° ID���� ��ϵǾ����� Ȯ��
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int));
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int));
		fsIn.seekg(newNameSize, ios::cur);
	}
	fsIn.close();
	newID++; // ���� ����� ID
	newNameSize = newName.size();

	ofstream fsOut(fileName, ios::binary | ios::out | ios::app); // dat�� ���
	fsOut.seekp(0, ios::end);
	fsOut.write((char*)&newID, sizeof(int)); // ID
	fsOut.write((char*)&newNameSize, sizeof(int)); // �н����� ������
	fsOut.write(newName.c_str(), newNameSize); // �н�����
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
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�

		if (newName == _name) // �̸��� ���� �ٹ� �߰� ��
		{
			fsIn.close();
			Composer newComposer;
			newComposer.setId(newID);
			newComposer.setName(newName);
			return newComposer;
		}
	}
	//�� ã���� ���

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
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�

		if (newID == _id) // �̸��� ���� �ٹ� �߰� ��
		{
			fsIn.close();
			Composer newComposer;
			newComposer.setId(newID);
			newComposer.setName(newName);
			return newComposer;
		}
	}
	//�� ã���� ���

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
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�

		Composer newComposer; // ���ǰ� ����
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
	cout << "���̵�         ���ǰ�  " << endl;
	cout << "������������������������������������������" << endl;
	ifstream fsIn(fileName, ios::binary | ios::in);
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // �̸� ������
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // �̸�

		cout << setw(3) <<  newID  << setw(20) << newName << endl;
	}
	fsIn.close();
}