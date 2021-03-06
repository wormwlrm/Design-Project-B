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
	cout << "忙式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛忙式式式式式式式式式式式式式式式式式忖弛" << endl;
	cout << "弛弛   ∫蛤雖瓚 擠奩 嶸鱔 Щ煎斜極∮  弛弛" << endl;
	cout << "弛戌式式式式式式式式式式式式式式式式式戎弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式戎" << endl;
	while (!exitProgram)
	{
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 餌辨濠 詭景" << endl;
		cout << "2. 婦葬濠 詭景" << endl;
		cout << "0. Щ煎斜極 謙猿" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cin >> choice;	
		switch (choice)
		{
		case 1: // 餌辨濠 詭景
			printUserLoginMenu(); 
			break;
		case 2: // 婦葬濠 詭景
			printManagerMenu(); 
			break;
		case 0: // Щ煎斜極 謙猿
			exitProgram = true; 
			break;
		default: // 澀跤脹 殮溘 蕨諼 籀葬
			if (cin.fail())
			{
				cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
			break;
		}
	}
}

void App::printUserLoginMenu() // 餌辨濠 煎斜檣 詭景 轎溘
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "             煎斜檣 詭景" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 煎斜檣" << endl;
		cout << "2. �蛾� 陛殮" << endl;
		cout << "0. 檜瞪 詭景煎" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cin >> choice;
		switch (choice)
		{
		case 2: // �蛾� 陛殮
			userRegisteration();
			break;
		case 1: // 煎斜檣
			login();
			break;
		case 0: // 檜瞪 詭景煎
			exitMenu = true;
			currentUserId = -1;
			break;
		default: // 澀跤脹 殮溘 蕨諼 籀葬
			if (cin.fail())
			{
				cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
			break;
		}
	}
}

void App::printUserMenu() // 餌辨濠 詭景 轎溘
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "              餌辨濠 詭景" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "ID : "; 
		if (currentUserId == -1)
			cout << "煎斜檣腎雖 彊懊蝗棲棻." << endl;
		else
			cout << currentUserId << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 撼彰 掘衙" << endl;
		cout << "2. 掘衙 跡煙 轎溘" << endl;
		cout << "3. 擠學 蹺繭" << endl;
		cout << "0. 檜瞪 詭景煎" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: // 撼彰 掘衙
			buyAlbum();
			break;
		case 2: // 掘衙 跡煙 轎溘
			printPurchasedList();
			break;
		case 3: // 擠學 蹺繭
			recommend();
			break;
		case 0: // 檜瞪 詭景煎
			exitMenu = true;
			currentUserId = -1;
			break;
		default: // 澀跤脹 殮溘 蕨諼 籀葬
			if (cin.fail())
			{
				cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
			break;
		}
	}
}
void App::printManagerMenu() // 婦葬濠 詭景 轎溘
{
	bool exitMenu = false;
	int choice;
	while (!exitMenu)
	{
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "               婦葬濠 詭景" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 擠學陛 蛔煙" << endl;
		cout << "2. 撼彰 蛔煙" << endl;
		cout << "3. 瞪羹 餌辨濠 轎溘" << endl;
		cout << "4. 瞪羹 撼彰 轎溘" << endl;
		cout << "5. 瞪羹 擠學陛 轎溘" << endl;
		cout << "0. 檜瞪 詭景煎" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: // 擠學陛 蛔煙
			addComposer();
			break;
		case 2: // 撼彰 蛔煙
			addAlbum();
			break;
		case 3: // 餌辨濠 轎溘
			um->printUserManager();
			break;
		case 4: // 撼彰 轎溘
			am->printAlbumManager();
			break;
		case 5: // 擠學陛 轎溘
			cm->printComposerManager();
			break;
		case 0: // 檜瞪 詭景煎
			exitMenu = true;
			break;
		default: // 澀跤脹 殮溘 蕨諼 籀葬
			if (cin.fail())
			{
				cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
			break;
		}
	}
}
void App::userRegisteration() // 嶸盪 蛔煙
{
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "                 �蛾� 陛殮" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	User newUser;
	int newID = (((um->getAllUserList()).back()).getID());
	int newPWsize;
	string newPW;
	int choice;
	newID++;

	cout << "嫦晝嫡擊 嬴檜蛤朝 " << newID << "殮棲棻." << endl;
	cout << "綠塵廓�ㄧ� 殮溘п輿撮蹂. : ";
	cin >> newPW;
	newPWsize = newPW.size();
	newUser.setUser(newID, newPW);
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "嬴檜蛤   : " << newID << endl;
	cout << "綠塵廓�� : " << newPW << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "殮溘嫡擎 薑爾煎 億 啗薑擊 儅撩ж衛啊蝗棲梱?" << endl;
	cout << "1. 蕨" << endl;
	cout << "2. 嬴棲螃" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	if (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	else if (choice == 2)
		return;
	else if (choice == 1)
		if (um->addUserToFile(newUser))
		{
			cout << "啗薑 儅撩縑 撩奢ж艘蝗棲棻." << endl;
			return;
		}
}

void App::login() // 煎斜檣
{
	if (currentUserId != -1)
	{
		cout << "Error : 檜嘐 煎斜檣 腎橫 氈蝗棲棻." << endl;
		return;
	}
	int gottenID;
	string gottenPW;
	cout << "嬴檜蛤蒂 殮溘п輿撮蹂. : ";
	cin >> gottenID;
	if (cin.fail())
	{
		cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	cout << "綠塵廓�ㄧ� 殮溘п輿撮蹂. : ";
	cin >> gottenPW;
	
	switch (um->authenticateUser(gottenID,gottenPW))
	{
	case 1:
		cout << "煎斜檣縑 撩奢ц蝗棲棻." << endl;
		currentUserId = gottenID;
		printUserMenu();
		break;
	case 2:
		cout << "Error : 綠塵廓�ㄟ� 橾纂ж雖 彊蝗棲棻." << endl;
		break;
	case 3:
		cout << "Error : п渡 嬴檜蛤陛 襄營ж雖 彊蝗棲棻." << endl;
		break;
	default:
		break;
	}
}

void App::buyAlbum() // 撼彰 掘衙
{
	int choice;
	bool exitMenu = false;
	while (!exitMenu)
	{
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "                 撼彰 掘衙" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 檜葷戲煎 匐儀" << endl;
		cout << "2. 嬴檜蛤煎 匐儀" << endl;
		cout << "3. 瞪羹 撼彰 �挫�" << endl;
		cout << "0. 檜瞪 詭景煎" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
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
				cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
			break;
		}
	}
}

void App::printPurchasedList() // 掘衙 跡煙 轎溘
{
	int purchasedAlbumID;
	MusicAlbum purchasedAlbum;
	if (um->getPurchasedListByUserId(currentUserId).size() == 0)
	{
		cout << "Error : 掘衙 跡煙檜 襄營ж雖 彊蝗棲棻." << endl;
		return;
	}
	cout << "嬴檜蛤        堊貲    擠學陛     濰腦  掘衙�蝦� " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; (unsigned)i < um->getPurchasedListByUserId(currentUserId).size(); i++)
	{
		purchasedAlbumID = um->getPurchasedListByUserId(currentUserId).at(i);
		purchasedAlbum = am->searchMusicAlbumById(purchasedAlbumID);
		cout << setw(2) << purchasedAlbum.getId() << " " << setw(16) << purchasedAlbum.getName() << " " << setw(12) << cm->searchComposerById(purchasedAlbum.getComposerId()).getName() << " " << setw(6) << purchasedAlbum.getGenreName() << " " << setw(3) << purchasedAlbum.getPurchasedCount() << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
}

void App::recommend() // 蹺繭
{
	int choice;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "            擠學 蹺繭" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "1. 掘衙 �蝦� 鼻嬪掏 蹺繭" << endl;
	cout << "2. 譆斬 掘衙 撼彰婁 綠蝌и 濰腦 蹺繭" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	if (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
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

void App::addComposer()// 擠學陛 蛔煙
{
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "            擠學陛 蛔煙" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	Composer newComposer;
	string Name;

	cout << "擠學陛 檜葷 : "; 
	cin >> Name;
	newComposer.setName(Name);
	if (cm->searchComposerByName(Name).getName() == Name) // 醞犒 �挫�
	{
		cout << "Error : 檜嘐 蛔煙脹 擠學陛殮棲棻." << endl;
		return;
	}

	if (cm->addComposerToFile(newComposer))
		cout << "擠學陛 蛔煙縑 撩奢ж艘蝗棲棻." << endl;
	else
		cout << "Error : 擠學陛 蛔煙縑 褒ぬж艘蝗棲棻." << endl;
	return;
}

void App::addAlbum() // 撼彰 蛔煙
{
	MusicAlbum newAlbum;
	string Name;
	string MusicianName;
	int Genre;
	
	cout << "擠學陛 : ";
	cin >> MusicianName;
	if (cm->searchComposerByName(MusicianName).getName() != MusicianName)
	{
		cout << "Error : п渡 擠學陛陛 襄營ж雖 彊蝗棲棻." << endl;
		return;
	}

	cout << "撼彰 檜葷 : ";
	cin >> Name;
	newAlbum.setName(Name);

	cout << "濰腦 (0.檣蛤 / 1.渣蝶 / 2.嫦塭萄 / 3.��м / 4.OST) : " ;
	cin >> Genre;
	if (Genre < 0 || Genre > 4 || cin.fail())
	{
		cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}

	newAlbum.setName(Name);
	newAlbum.setComposerId(cm->searchComposerByName(MusicianName).getId());
	newAlbum.setGenre(Genre);

	am->addMusicAlbumToFile(newAlbum);

	cout << "撼彰 蛔煙檜 諫猿腎歷蝗棲棻." << endl;
	return;
}

void App::searchById() // ID煎 匐儀
{
	int keyId;
	cout << "嬴檜蛤蒂 殮溘ж撮蹂. : ";
	cin >> keyId;
	if (cin.fail())
	{
		cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return;
	}
	MusicAlbum target = am->searchMusicAlbumById(keyId);
	if (target.getId() != keyId) // 橈朝 唳辦
	{
		return;
	}

	cout << "嬴檜蛤        堊貲    擠學陛     濰腦  掘衙�蝦� " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << setw(2) << target.getId() << " " << setw(16) << target.getName() << " " << setw(12) << cm->searchComposerById(target.getComposerId()).getName() << " " << setw(6) << target.getGenreName() << " " << setw(3) << target.getPurchasedCount() << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	
	char choice;
	cout << "撼彰擊 掘衙ж衛啊蝗棲梱(Y/N)? : ";
	cin >> choice;
	switch (choice)
	{
	case 'Y':
		if (am->updateMusicAlbumSellCount(target.getId()) && um->addAlbumIdToPurchaseList(currentUserId, target.getId())) // 撼彰 掘衙 �蝦� 蹺陛 塽 餌辨濠曖 掘衙 跡煙縑 蹺陛
			cout << "撼彰 掘衙縑 撩奢ж艘蝗棲棻." << endl;
		else
			cout << "Error : 撼彰 掘衙縑 褒ぬж艘蝗棲棻." << endl;
		break;
	case 'N':
		return;
		break;
	default:
		if (cin.fail())
		{
			cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
		break;
	}
}

void App::searchByName() // 檜葷戲煎 匐儀
{
	string keyName;
	cout << "撼彰 檜葷擊 殮溘ж撮蹂. : ";
	cin >> keyName;
	MusicAlbum target = am->searchMusicAlbumByName(keyName);
	if (target.getName() != keyName) // 橈朝 唳辦
	{
		return;
	}
	cout << "嬴檜蛤        堊貲    擠學陛     濰腦  掘衙�蝦� " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << setw(2) << target.getId() << " " << setw(16) << target.getName() << " " << setw(12) << cm->searchComposerById(target.getComposerId()).getName() << " " << setw(6) << target.getGenreName() << " " << setw(3) << target.getPurchasedCount() << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式" << endl;

	char choice;
	cout << "撼彰擊 掘衙ж衛啊蝗棲梱(Y/N)? : ";
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
			cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		cout << "Error : 螢夥腦雖 彊擎 摹鷗殮棲棻." << endl;
		break;
	}
}