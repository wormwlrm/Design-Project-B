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
		return "인디";
	case 1:
		return "댄스";
	case 2:
		return "발라드";
	case 3:
		return "힙합";
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
	//cout << "곡 만들기(곡명,음악가,장르)" << endl;
	//for (int i = 0; i < 20; i++)
	//{
	//	int ID = i;
	//	string Name; cin >> Name;
	//	int size = Name.size();
	//	int MusicianID; cin >> MusicianID;
	//	int Genre; cin >> Genre;
	//	int PurchasedNum = 0;

	//	fsOut.write((char*)&ID, sizeof(int)); // 앨범 ID
	//	fsOut.write((char*)&size, sizeof(int)); // 이름 길이
	//	fsOut.write(Name.c_str(), Name.size()); // 이름
	//	fsOut.write((char*)&MusicianID, sizeof(int)); // 음악가 ID
	//	fsOut.write((char*)&Genre, sizeof(int)); // 장르
	//	fsOut.write((char*)&PurchasedNum, sizeof(int)); // 구매 횟수
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

	ifstream fsIn(fileName, ios::binary | ios::in); // 몇 번 째 ID까지 등록되었는지 확인
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // 앨범 아이디
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 길이
		fsIn.seekg(newNameSize, ios::cur); // 이름 길이만큼 건너 뜀
		fsIn.seekg(12, ios::cur); // 음악가 ID, 장르, 구매횟수 건너 뜀
	}
	fsIn.close();
	newID++; // 새로 등록할 ID
	newNameSize = newName.size();

	ofstream fsOut(fileName, ios::binary | ios::out | ios::app); // dat에 등록
	fsOut.seekp(0, ios::end);
	fsOut.write((char*)&newID, sizeof(int)); // ID
	fsOut.write((char*)&newNameSize, sizeof(int)); // 이름 사이즈
	fsOut.write(newName.c_str(), newNameSize); // 이름
	fsOut.write((char*)&newMusicianID, sizeof(int)); // 음악가 ID
	fsOut.write((char*)&newGenre, sizeof(int)); // 장르
	fsOut.write((char*)&newPurchasedNum, sizeof(int)); // 구매 횟수
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
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름
		fsIn.read((char*)&newMusicianID, sizeof(int)); // 음악가 ID
		fsIn.read((char*)&newGenre, sizeof(int)); // 장르
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // 구매횟수

		if (newName == _name) // 이름이 같은 앨범 발견 시
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
	//못 찾았을 경우
	cout << "Error : 검색 결과가 존재하지 않습니다." << endl;
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
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름
		fsIn.read((char*)&newMusicianID, sizeof(int)); // 음악가 ID
		fsIn.read((char*)&newGenre, sizeof(int)); // 장르
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // 구매횟수

		if (newID == _id) // ID가 같은 앨범 발견 시
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
	//못 찾았을 경우
	cout << "Error : 검색 결과가 존재하지 않습니다." << endl;
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
		fsIO.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIO.read(&newName[0], newNameSize); // 이름
		fsIO.read((char*)&newMusicianID, sizeof(int)); // 음악가 ID
		fsIO.read((char*)&newGenre, sizeof(int)); // 장르
		fsIO.read((char*)&newPurchasedNum, sizeof(int)); // 구매횟수
		
		if (newID == albumId) // ID가 같은 앨범 발견 시 구매 횟수 바꾸고 종료
		{
			fsIO.seekp(-4, ios::cur);
			newPurchasedNum++; // 구매 횟수 ++
			fsIO.write((char*)&newPurchasedNum, sizeof(int)); // 덮어쓰기
			fsIO.close();
			return true;
		}
	}
	fsIO.close();
	return false;
}

vector<MusicAlbum> AlbumManager::getAllAlbumList()
{
	vector<MusicAlbum> AlbumList; // 반환할 전체 앨범 리스트 생성

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
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름
		fsIn.read((char*)&newMusicianID, sizeof(int)); // 음악가 ID
		fsIn.read((char*)&newGenre, sizeof(int)); // 장르
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // 구매횟수
		
		MusicAlbum newAlbum; // 앨범 생성
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
	cout << "아이디        곡명    음악가     장르  구매횟수 " << endl;
	cout << "─────────────────────" << endl;
	while (true)
	{
		fsIn.read((char*)&newID, sizeof(int)); // ID
		if (fsIn.eof())
			break;
		fsIn.read((char*)&newNameSize, sizeof(int)); // 이름 사이즈
		newName.resize(newNameSize);
		fsIn.read(&newName[0], newNameSize); // 이름
		fsIn.read((char*)&newMusicianID, sizeof(int)); // 음악가 ID
		fsIn.read((char*)&newGenre, sizeof(int)); // 장르
		fsIn.read((char*)&newPurchasedNum, sizeof(int)); // 구매횟수

		switch (newGenre)
		{
		case 0:
			newGenreString = "인디"; 
			break;
		case 1:
			newGenreString = "댄스";
			break;
		case 2:
			newGenreString = "발라드";
			break;
		case 3:
			newGenreString = "힙합";
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