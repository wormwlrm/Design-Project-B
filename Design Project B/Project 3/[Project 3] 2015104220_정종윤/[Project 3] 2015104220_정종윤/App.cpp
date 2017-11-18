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
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢" << endl;
	cout << "¦¢¦¢   ¡ìµðÁöÅÐ À½¹Ý À¯Åë ÇÁ·Î±×·¥¡í  ¦¢¦¢" << endl;
	cout << "¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	while (!exitProgram)
	{
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. »ç¿ëÀÚ ¸Þ´º" << endl;
		cout << "2. °ü¸®ÀÚ ¸Þ´º" << endl;
		cout << "0. ÇÁ·Î±×·¥ Á¾·á" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cin >> choice;	
		switch (choice)
		{
		case 1: // »ç¿ëÀÚ ¸Þ´º
			printUserLoginMenu(); 
			break;
		case 2: // °ü¸®ÀÚ ¸Þ´º
			printManagerMenu(); 
			break;
		case 0: // ÇÁ·Î±×·¥ Á¾·á
			exitProgram = true; 
			break;
		default: // Àß¸øµÈ ÀÔ·Â ¿¹¿Ü Ã³¸®
			if (cin.fail())
			{
				cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
			break;
		}
	}
}

void App::printUserLoginMenu() // »ç¿ëÀÚ ·Î±×ÀÎ ¸Þ´º Ãâ·Â
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "             ·Î±×ÀÎ ¸Þ´º" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. ·Î±×ÀÎ" << endl;
		cout << "2. È¸¿ø °¡ÀÔ" << endl;
		cout << "0. ÀÌÀü ¸Þ´º·Î" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cin >> choice;
		switch (choice)
		{
		case 2: // È¸¿ø °¡ÀÔ
			userRegisteration();
			break;
		case 1: // ·Î±×ÀÎ
			login();
			break;
		case 0: // ÀÌÀü ¸Þ´º·Î
			exitMenu = true;
			currentUserId = -1;
			break;
		default: // Àß¸øµÈ ÀÔ·Â ¿¹¿Ü Ã³¸®
			if (cin.fail())
			{
				cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
			break;
		}
	}
}

void App::printUserMenu() // »ç¿ëÀÚ ¸Þ´º Ãâ·Â
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "              »ç¿ëÀÚ ¸Þ´º" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "ID : "; 
		if (currentUserId == -1)
			cout << "·Î±×ÀÎµÇÁö ¾Ê¾Ò½À´Ï´Ù." << endl;
		else
			cout << currentUserId << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. ¾Ù¹ü ±¸¸Å" << endl;
		cout << "2. ±¸¸Å ¸ñ·Ï Ãâ·Â" << endl;
		cout << "3. À½¾Ç ÃßÃµ" << endl;
		cout << "0. ÀÌÀü ¸Þ´º·Î" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: // ¾Ù¹ü ±¸¸Å
			buyAlbum();
			break;
		case 2: // ±¸¸Å ¸ñ·Ï Ãâ·Â
			printPurchasedList();
			break;
		case 3: // À½¾Ç ÃßÃµ
			recommend();
			break;
		case 0: // ÀÌÀü ¸Þ´º·Î
			exitMenu = true;
			currentUserId = -1;
			break;
		default: // Àß¸øµÈ ÀÔ·Â ¿¹¿Ü Ã³¸®
			if (cin.fail())
			{
				cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
			break;
		}
	}
}
void App::printManagerMenu() // °ü¸®ÀÚ ¸Þ´º Ãâ·Â
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "               °ü¸®ÀÚ ¸Þ´º" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. À½¾Ç°¡ µî·Ï" << endl;
		cout << "2. ¾Ù¹ü µî·Ï" << endl;
		cout << "3. ÀüÃ¼ »ç¿ëÀÚ Ãâ·Â" << endl;
		cout << "4. ÀüÃ¼ ¾Ù¹ü Ãâ·Â" << endl;
		cout << "5. ÀüÃ¼ À½¾Ç°¡ Ãâ·Â" << endl;
		cout << "0. ÀÌÀü ¸Þ´º·Î" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: // À½¾Ç°¡ µî·Ï
			addComposer();
			break;
		case 2: // ¾Ù¹ü µî·Ï
			addAlbum();
			break;
		case 3: // »ç¿ëÀÚ Ãâ·Â
			um->printUserManager();
			break;
		case 4: // ¾Ù¹ü Ãâ·Â
			am->printAlbumManager();
			break;
		case 5: // À½¾Ç°¡ Ãâ·Â
			cm->printComposerManager();
			break;
		case 0: // ÀÌÀü ¸Þ´º·Î
			exitMenu = true;
			break;
		default: // Àß¸øµÈ ÀÔ·Â ¿¹¿Ü Ã³¸®
			if (cin.fail())
			{
				cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
			break;
		}
	}
}
void App::userRegisteration() // À¯Àú µî·Ï
{
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "                 È¸¿ø °¡ÀÔ" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	User newUser;
	int newID = (((um->getAllUserList()).back()).getID());
	int newPWsize;
	string newPW;
	int choice;
	newID++;

	cout << "¹ß±Þ¹ÞÀ» ¾ÆÀÌµð´Â " << newID << "ÀÔ´Ï´Ù." << endl;
	cout << "ºñ¹Ð¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä. : ";
	cin >> newPW;
	newPWsize = newPW.size();
	newUser.setUser(newID, newPW);
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "¾ÆÀÌµð   : " << newID << endl;
	cout << "ºñ¹Ð¹øÈ£ : " << newPW << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "ÀÔ·Â¹ÞÀº Á¤º¸·Î »õ °èÁ¤À» »ý¼ºÇÏ½Ã°Ú½À´Ï±î?" << endl;
	cout << "1. ¿¹" << endl;
	cout << "2. ¾Æ´Ï¿À" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cin >> choice;
	if (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	else if (choice == 2)
		return;
	else if (choice == 1)
		if (um->addUserToFile(newUser))
		{
			cout << "°èÁ¤ »ý¼º¿¡ ¼º°øÇÏ¿´½À´Ï´Ù." << endl;
			return;
		}
}

void App::login() // ·Î±×ÀÎ
{
	if (currentUserId != -1)
	{
		cout << "Error : ÀÌ¹Ì ·Î±×ÀÎ µÇ¾î ÀÖ½À´Ï´Ù." << endl;
		return;
	}
	int gottenID;
	string gottenPW;
	cout << "¾ÆÀÌµð¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä. : ";
	cin >> gottenID;
	if (cin.fail())
	{
		cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "ºñ¹Ð¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä. : ";
	cin >> gottenPW;
	
	switch (um->authenticateUser(gottenID,gottenPW))
	{
	case 1:
		cout << "·Î±×ÀÎ¿¡ ¼º°øÇß½À´Ï´Ù." << endl;
		currentUserId = gottenID;
		printUserMenu();
		break;
	case 2:
		cout << "Error : ºñ¹Ð¹øÈ£°¡ ÀÏÄ¡ÇÏÁö ¾Ê½À´Ï´Ù." << endl;
		break;
	case 3:
		cout << "Error : ÇØ´ç ¾ÆÀÌµð°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù." << endl;
		break;
	default:
		break;
	}
}

void App::buyAlbum() // ¾Ù¹ü ±¸¸Å
{
	int choice;
	bool exitMenu = false;
	while (!exitMenu)
	{
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "                 ¾Ù¹ü ±¸¸Å" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. ÀÌ¸§À¸·Î °Ë»ö" << endl;
		cout << "2. ¾ÆÀÌµð·Î °Ë»ö" << endl;
		cout << "3. ÀüÃ¼ ¾Ù¹ü È®ÀÎ" << endl;
		cout << "0. ÀÌÀü ¸Þ´º·Î" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
				cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
			break;
		}
	}
}

void App::printPurchasedList() // ±¸¸Å ¸ñ·Ï Ãâ·Â
{
	int purchasedAlbumID;
	MusicAlbum purchasedAlbum;
	if (um->getPurchasedListByUserId(currentUserId).size() == 0)
	{
		cout << "Error : ±¸¸Å ¸ñ·ÏÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù." << endl;
		return;
	}
	cout << "¾ÆÀÌµð        °î¸í    À½¾Ç°¡     Àå¸£  ±¸¸ÅÈ½¼ö " << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	for (int i = 0; (unsigned)i < um->getPurchasedListByUserId(currentUserId).size(); i++)
	{
		purchasedAlbumID = um->getPurchasedListByUserId(currentUserId).at(i);
		purchasedAlbum = am->searchMusicAlbumById(purchasedAlbumID);
		cout << setw(2) << purchasedAlbum.getId() << " " << setw(16) << purchasedAlbum.getName() << " " << setw(12) << cm->searchComposerById(purchasedAlbum.getComposerId()).getName() << " " << setw(6) << purchasedAlbum.getGenreName() << " " << setw(3) << purchasedAlbum.getPurchasedCount() << endl;
	}
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
}

void App::recommend() // ÃßÃµ
{
	int choice;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "            À½¾Ç ÃßÃµ" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "1. ±¸¸Å È½¼ö »óÀ§±Ç ÃßÃµ" << endl;
	cout << "2. ÃÖ±Ù ±¸¸Å ¾Ù¹ü°ú ºñ½ÁÇÑ Àå¸£ ÃßÃµ" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cin >> choice;
	if (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
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

void App::addComposer()// À½¾Ç°¡ µî·Ï
{
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "            À½¾Ç°¡ µî·Ï" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	Composer newComposer;
	string Name;

	cout << "À½¾Ç°¡ ÀÌ¸§ : "; 
	cin >> Name;
	newComposer.setName(Name);
	if (cm->searchComposerByName(Name).getName() == Name) // Áßº¹ È®ÀÎ
	{
		cout << "Error : ÀÌ¹Ì µî·ÏµÈ À½¾Ç°¡ÀÔ´Ï´Ù." << endl;
		return;
	}

	if (cm->addComposerToFile(newComposer))
		cout << "À½¾Ç°¡ µî·Ï¿¡ ¼º°øÇÏ¿´½À´Ï´Ù." << endl;
	else
		cout << "Error : À½¾Ç°¡ µî·Ï¿¡ ½ÇÆÐÇÏ¿´½À´Ï´Ù." << endl;
	return;
}

void App::addAlbum() // ¾Ù¹ü µî·Ï
{
	MusicAlbum newAlbum;
	string Name;
	string MusicianName;
	int Genre;
	
	cout << "À½¾Ç°¡ : ";
	cin >> MusicianName;
	if (cm->searchComposerByName(MusicianName).getName() != MusicianName)
	{
		cout << "Error : ÇØ´ç À½¾Ç°¡°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù." << endl;
		return;
	}

	cout << "¾Ù¹ü ÀÌ¸§ : ";
	cin >> Name;
	newAlbum.setName(Name);

	cout << "Àå¸£ (0.ÀÎµð / 1.´í½º / 2.¹ß¶óµå / 3.ÈüÇÕ / 4.OST) : " ;
	cin >> Genre;
	if (Genre < 0 || Genre > 4 || cin.fail())
	{
		cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}

	newAlbum.setName(Name);
	newAlbum.setComposerId(cm->searchComposerByName(MusicianName).getId());
	newAlbum.setGenre(Genre);

	am->addMusicAlbumToFile(newAlbum);

	cout << "¾Ù¹ü µî·ÏÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
	return;
}

void App::searchById() // ID·Î °Ë»ö
{
	int keyId;
	cout << "¾ÆÀÌµð¸¦ ÀÔ·ÂÇÏ¼¼¿ä. : ";
	cin >> keyId;
	if (cin.fail())
	{
		cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	MusicAlbum target = am->searchMusicAlbumById(keyId);
	if (target.getId() != keyId) // ¾ø´Â °æ¿ì
	{
		return;
	}

	cout << "¾ÆÀÌµð        °î¸í    À½¾Ç°¡     Àå¸£  ±¸¸ÅÈ½¼ö " << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << setw(2) << target.getId() << " " << setw(16) << target.getName() << " " << setw(12) << cm->searchComposerById(target.getComposerId()).getName() << " " << setw(6) << target.getGenreName() << " " << setw(3) << target.getPurchasedCount() << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	
	char choice;
	cout << "¾Ù¹üÀ» ±¸¸ÅÇÏ½Ã°Ú½À´Ï±î(Y/N)? : ";
	cin >> choice;
	switch (choice)
	{
	case 'Y':
		if (am->updateMusicAlbumSellCount(target.getId()) && um->addAlbumIdToPurchaseList(currentUserId, target.getId())) // ¾Ù¹ü ±¸¸Å È½¼ö Ãß°¡ ¹× »ç¿ëÀÚÀÇ ±¸¸Å ¸ñ·Ï¿¡ Ãß°¡
			cout << "¾Ù¹ü ±¸¸Å¿¡ ¼º°øÇÏ¿´½À´Ï´Ù." << endl;
		else
			cout << "Error : ¾Ù¹ü ±¸¸Å¿¡ ½ÇÆÐÇÏ¿´½À´Ï´Ù." << endl;
		break;
	case 'N':
		return;
		break;
	default:
		if (cin.fail())
		{
			cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
		break;
	}
}

void App::searchByName() // ÀÌ¸§À¸·Î °Ë»ö
{
	string keyName;
	cout << "¾Ù¹ü ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä. : ";
	cin >> keyName;
	MusicAlbum target = am->searchMusicAlbumByName(keyName);
	if (target.getName() != keyName) // ¾ø´Â °æ¿ì
	{
		return;
	}
	cout << "¾ÆÀÌµð        °î¸í    À½¾Ç°¡     Àå¸£  ±¸¸ÅÈ½¼ö " << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << setw(2) << target.getId() << " " << setw(16) << target.getName() << " " << setw(12) << cm->searchComposerById(target.getComposerId()).getName() << " " << setw(6) << target.getGenreName() << " " << setw(3) << target.getPurchasedCount() << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;

	char choice;
	cout << "¾Ù¹üÀ» ±¸¸ÅÇÏ½Ã°Ú½À´Ï±î(Y/N)? : ";
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
			cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		cout << "Error : ¿Ã¹Ù¸£Áö ¾ÊÀº ¼±ÅÃÀÔ´Ï´Ù." << endl;
		break;
	}
}