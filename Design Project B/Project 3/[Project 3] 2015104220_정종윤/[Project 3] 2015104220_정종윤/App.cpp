#include "App.h"

App::App()
{
	um = new UserManager();
	cm = new ComposerManager();
	am = new AlbumManager();
	currentUserId = -1;
}

App::~App()
{

}

void App::run()
{
	int choice;
	bool exitProgram = false;
	cout << "������������������������������������������" << endl;
	cout << "������������������������������������������" << endl;
	cout << "����   ������� ���� ���� ���α׷���  ����" << endl;
	cout << "������������������������������������������" << endl;
	cout << "������������������������������������������" << endl;
	while (!exitProgram)
	{
		cout << "������������������������������������������" << endl;
		cout << "1. ����� �޴�" << endl;
		cout << "2. ������ �޴�" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "������������������������������������������" << endl;
		cin >> choice;	
		switch (choice)
		{
		case 1: // ����� �޴�
			printUserLoginMenu(); 
			break;
		case 2: // ������ �޴�
			printManagerMenu(); 
			break;
		case 0: // ���α׷� ����
			exitProgram = true; 
			break;
		default: // �߸��� �Է� ���� ó��
			if (cin.fail())
			{
				cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			break;
		}
	}
}

void App::printUserLoginMenu() // ����� �α��� �޴� ���
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "������������������������������������������" << endl;
		cout << "             �α��� �޴�" << endl;
		cout << "������������������������������������������" << endl;
		cout << "1. �α���" << endl;
		cout << "2. ȸ�� ����" << endl;
		cout << "0. ���� �޴���" << endl;
		cout << "������������������������������������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 2: // ȸ�� ����
			userRegisteration();
			break;
		case 1: // �α���
			login();
			break;
		case 0: // ���� �޴���
			exitMenu = true;
			currentUserId = -1;
			break;
		default: // �߸��� �Է� ���� ó��
			if (cin.fail())
			{
				cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			break;
		}
	}
}

void App::printUserMenu() // ����� �޴� ���
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "������������������������������������������" << endl;
		cout << "              ����� �޴�" << endl;
		cout << "������������������������������������������" << endl;
		cout << "ID : "; 
		if (currentUserId == -1)
			cout << "�α��ε��� �ʾҽ��ϴ�." << endl;
		else
			cout << currentUserId << endl;
		cout << "������������������������������������������" << endl;
		cout << "1. �ٹ� ����" << endl;
		cout << "2. ���� ��� ���" << endl;
		cout << "3. ���� ��õ" << endl;
		cout << "0. ���� �޴���" << endl;
		cout << "������������������������������������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: // �ٹ� ����
			buyAlbum();
			break;
		case 2: // ���� ��� ���
			printPurchasedList();
			break;
		case 3: // ���� ��õ
			recommend();
			break;
		case 0: // ���� �޴���
			exitMenu = true;
			currentUserId = -1;
			break;
		default: // �߸��� �Է� ���� ó��
			if (cin.fail())
			{
				cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			break;
		}
	}
}
void App::printManagerMenu() // ������ �޴� ���
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "������������������������������������������" << endl;
		cout << "               ������ �޴�" << endl;
		cout << "������������������������������������������" << endl;
		cout << "1. ���ǰ� ���" << endl;
		cout << "2. �ٹ� ���" << endl;
		cout << "3. ��ü ����� ���" << endl;
		cout << "4. ��ü �ٹ� ���" << endl;
		cout << "5. ��ü ���ǰ� ���" << endl;
		cout << "0. ���� �޴���" << endl;
		cout << "������������������������������������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: // ���ǰ� ���
			addComposer();
			break;
		case 2: // �ٹ� ���
			addAlbum();
			break;
		case 3: // ����� ���
			um->printUserManager();
			break;
		case 4: // �ٹ� ���
			am->printAlbumManager();
			break;
		case 5: // ���ǰ� ���
			cm->printComposerManager();
			break;
		case 0: // ���� �޴���
			exitMenu = true;
			break;
		default: // �߸��� �Է� ���� ó��
			if (cin.fail())
			{
				cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			break;
		}
	}
}
void App::userRegisteration() // ���� ���
{
	cout << "������������������������������������������" << endl;
	cout << "                 ȸ�� ����" << endl;
	cout << "������������������������������������������" << endl;
	User newUser;
	int newID = (((um->getAllUserList()).back()).getID());
	int newPWsize;
	string newPW;
	int choice;
	newID++;

	cout << "�߱޹��� ���̵�� " << newID << "�Դϴ�." << endl;
	cout << "��й�ȣ�� �Է����ּ���. : ";
	cin >> newPW;
	newPWsize = newPW.size();
	newUser.setUser(newID, newPW);
	cout << "������������������������������������������" << endl;
	cout << "���̵�   : " << newID << endl;
	cout << "��й�ȣ : " << newPW << endl;
	cout << "������������������������������������������" << endl;
	cout << "�Է¹��� ������ �� ������ �����Ͻðڽ��ϱ�?" << endl;
	cout << "1. ��" << endl;
	cout << "2. �ƴϿ�" << endl;
	cout << "������������������������������������������" << endl;
	cin >> choice;
	if (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	else if (choice == 2)
		return;
	else if (choice == 1)
		if (um->addUserToFile(newUser))
		{
			cout << "���� ������ �����Ͽ����ϴ�." << endl;
			return;
		}
}

void App::login() // �α���
{
	if (currentUserId != -1)
	{
		cout << "Error : �̹� �α��� �Ǿ� �ֽ��ϴ�." << endl;
		return;
	}
	int gottenID;
	string gottenPW;
	cout << "���̵� �Է����ּ���. : ";
	cin >> gottenID;
	if (cin.fail())
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "��й�ȣ�� �Է����ּ���. : ";
	cin >> gottenPW;
	
	switch (um->authenticateUser(gottenID,gottenPW))
	{
	case 1:
		cout << "�α��ο� �����߽��ϴ�." << endl;
		currentUserId = gottenID;
		printUserMenu();
		break;
	case 2:
		cout << "Error : ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		break;
	case 3:
		cout << "Error : �ش� ���̵� �������� �ʽ��ϴ�." << endl;
		break;
	default:
		break;
	}
}

void App::buyAlbum() // �ٹ� ����
{
	int choice;
	bool exitMenu = false;
	while (!exitMenu)
	{
		cout << "������������������������������������������" << endl;
		cout << "                 �ٹ� ����" << endl;
		cout << "������������������������������������������" << endl;
		cout << "1. �̸����� �˻�" << endl;
		cout << "2. ���̵�� �˻�" << endl;
		cout << "3. ��ü �ٹ� Ȯ��" << endl;
		cout << "0. ���� �޴���" << endl;
		cout << "������������������������������������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			searchByName();
			break;
		case 2:
			searchById();
			break;
		case 3:
			am->printAlbumManager();
			break;
		case 0:
			exitMenu = true;
			break;
		default:
			if (cin.fail())
			{
				cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			break;
		}
	}
}

void App::printPurchasedList() // ���� ��� ���
{
	int purchasedAlbumID;
	MusicAlbum purchasedAlbum;
	if (um->getPurchasedListByUserId(currentUserId).size() == 0)
	{
		cout << "Error : ���� ����� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << "���̵�        ���    ���ǰ�     �帣  ����Ƚ�� " << endl;
	cout << "������������������������������������������" << endl;
	for (int i = 0; (unsigned)i < um->getPurchasedListByUserId(currentUserId).size(); i++)
	{
		purchasedAlbumID = um->getPurchasedListByUserId(currentUserId).at(i);
		purchasedAlbum = am->searchMusicAlbumById(purchasedAlbumID);
		cout << setw(2) << purchasedAlbum.getId() << " " << setw(16) << purchasedAlbum.getName() << " " << setw(12) << cm->searchComposerById(purchasedAlbum.getComposerId()).getName() << " " << setw(6) << purchasedAlbum.getGenreName() << " " << setw(3) << purchasedAlbum.getPurchasedCount() << endl;
	}
	cout << "������������������������������������������" << endl;
}

void App::recommend() // ��õ
{
	int choice;
	cout << "������������������������������������������" << endl;
	cout << "            ���� ��õ" << endl;
	cout << "������������������������������������������" << endl;
	cout << "1. ���� Ƚ�� ������ ��õ" << endl;
	cout << "2. �ֱ� ���� �ٹ��� ����� �帣 ��õ" << endl;
	cout << "������������������������������������������" << endl;
	cin >> choice;
	if (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	switch (choice)
	{
	case 1:
		rcdAlg = new RecTopTen();
		rcdAlg->recommend(currentUserId);
		break;
	case 2:
		rcdAlg = new RecMyAlg();
		rcdAlg->recommend(currentUserId);
		break;
	default:
		break;
	}

}

void App::addComposer()// ���ǰ� ���
{
	cout << "������������������������������������������" << endl;
	cout << "            ���ǰ� ���" << endl;
	cout << "������������������������������������������" << endl;
	Composer newComposer;
	string Name;

	cout << "���ǰ� �̸� : "; 
	cin >> Name;
	newComposer.setName(Name);
	if (cm->searchComposerByName(Name).getName() == Name) // �ߺ� Ȯ��
	{
		cout << "Error : �̹� ��ϵ� ���ǰ��Դϴ�." << endl;
		return;
	}

	if (cm->addComposerToFile(newComposer))
		cout << "���ǰ� ��Ͽ� �����Ͽ����ϴ�." << endl;
	else
		cout << "Error : ���ǰ� ��Ͽ� �����Ͽ����ϴ�." << endl;
	return;
}

void App::addAlbum() // �ٹ� ���
{
	MusicAlbum newAlbum;
	string Name;
	string MusicianName;
	int Genre;
	
	cout << "���ǰ� : ";
	cin >> MusicianName;
	if (cm->searchComposerByName(MusicianName).getName() != MusicianName)
	{
		cout << "Error : �ش� ���ǰ��� �������� �ʽ��ϴ�." << endl;
		return;
	}

	cout << "�ٹ� �̸� : ";
	cin >> Name;
	newAlbum.setName(Name);

	cout << "�帣 (0.�ε� / 1.�� / 2.�߶�� / 3.���� / 4.OST) : " ;
	cin >> Genre;
	if (Genre < 0 || Genre > 4 || cin.fail())
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}

	newAlbum.setName(Name);
	newAlbum.setComposerId(cm->searchComposerByName(MusicianName).getId());
	newAlbum.setGenre(Genre);

	am->addMusicAlbumToFile(newAlbum);

	cout << "�ٹ� ����� �Ϸ�Ǿ����ϴ�." << endl;
	return;
}

void App::searchById() // ID�� �˻�
{
	int keyId;
	cout << "���̵� �Է��ϼ���. : ";
	cin >> keyId;
	if (cin.fail())
	{
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	MusicAlbum target = am->searchMusicAlbumById(keyId);
	if (target.getId() != keyId) // ���� ���
	{
		return;
	}

	cout << "���̵�        ���    ���ǰ�     �帣  ����Ƚ�� " << endl;
	cout << "������������������������������������������" << endl;
	cout << setw(2) << target.getId() << " " << setw(16) << target.getName() << " " << setw(12) << cm->searchComposerById(target.getComposerId()).getName() << " " << setw(6) << target.getGenreName() << " " << setw(3) << target.getPurchasedCount() << endl;
	cout << "������������������������������������������" << endl;
	
	char choice;
	cout << "�ٹ��� �����Ͻðڽ��ϱ�(Y/N)? : ";
	cin >> choice;
	switch (choice)
	{
	case 'Y':
		if (am->updateMusicAlbumSellCount(target.getId()) && um->addAlbumIdToPurchaseList(currentUserId, target.getId())) // �ٹ� ���� Ƚ�� �߰� �� ������� ���� ��Ͽ� �߰�
			cout << "�ٹ� ���ſ� �����Ͽ����ϴ�." << endl;
		else
			cout << "Error : �ٹ� ���ſ� �����Ͽ����ϴ�." << endl;
		break;
	case 'N':
		return;
		break;
	default:
		if (cin.fail())
		{
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		break;
	}
}

void App::searchByName() // �̸����� �˻�
{
	string keyName;
	cout << "�ٹ� �̸��� �Է��ϼ���. : ";
	cin >> keyName;
	MusicAlbum target = am->searchMusicAlbumByName(keyName);
	if (target.getName() != keyName) // ���� ���
	{
		return;
	}
	cout << "���̵�        ���    ���ǰ�     �帣  ����Ƚ�� " << endl;
	cout << "������������������������������������������" << endl;
	cout << setw(2) << target.getId() << " " << setw(16) << target.getName() << " " << setw(12) << cm->searchComposerById(target.getComposerId()).getName() << " " << setw(6) << target.getGenreName() << " " << setw(3) << target.getPurchasedCount() << endl;
	cout << "������������������������������������������" << endl;

	char choice;
	cout << "�ٹ��� �����Ͻðڽ��ϱ�(Y/N)? : ";
	cin >> choice;
	switch (choice)
	{
	case 'Y':
		am->updateMusicAlbumSellCount(target.getId());
		um->addAlbumIdToPurchaseList(currentUserId, target.getId());
		break;
	case 'N':
		return;
		break;
	default:
		if (cin.fail())
		{
			cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		cout << "Error : �ùٸ��� ���� �����Դϴ�." << endl;
		break;
	}
}