#include "BaseRecAlg.h"

BaseRecAlg::BaseRecAlg()
{

}

BaseRecAlg::~BaseRecAlg()
{

}

#include "RecTopTen.h"

RecTopTen::RecTopTen()
{

}

RecTopTen::~RecTopTen()
{

}

vector<MusicAlbum> RecTopTen::recommend(int id)
{
	AlbumManager am;
	vector<MusicAlbum> AllAlbumList = am.getAllAlbumList();
	vector<MusicAlbum> RecTopTenList;
	MusicAlbum SelectedMusicAlbum;
	int Biggest;
	int PlaceOfSelectedMusicAlbum;

	for (int i = 0; (unsigned)i < 10; i++)
	{
		Biggest = 0;
		int j = 0;
		for (int j = 0; (unsigned)j < AllAlbumList.size(); j++) // 가장 구매 횟수 큰 앨범 찾음
		{
			if (AllAlbumList.at(j).getPurchasedCount() > Biggest)
			{
				Biggest = AllAlbumList.at(j).getPurchasedCount();
				SelectedMusicAlbum = AllAlbumList.at(j);
				PlaceOfSelectedMusicAlbum = j;
			}
		}
		RecTopTenList.push_back(SelectedMusicAlbum);
		AllAlbumList.erase(AllAlbumList.begin() + PlaceOfSelectedMusicAlbum);
	}

	cout << "순위         곡명      구매 횟수" << endl;
	for (int i = 0; (unsigned) i < RecTopTenList.size(); i++)
	{
		cout << setw(2) << i + 1 << setw(20) << RecTopTenList.at(i).getName() << setw(6) << RecTopTenList.at(i).getPurchasedCount() << endl;
	}
	return RecTopTenList;
}

#include "RecMyAlg.h"

RecMyAlg::RecMyAlg()
{

}

RecMyAlg::~RecMyAlg()
{
	
}

vector<MusicAlbum> RecMyAlg::recommend(int id)
{
	AlbumManager am;
	UserManager um;
	vector<MusicAlbum> AllAlbumList = am.getAllAlbumList();
	vector<MusicAlbum> RecMyAlgList;
	MusicAlbum SelectedMusicAlbum;
	int LastSelectedAlbum = (um.getAllUserList().at(id).getPurchasedList()->at((um.getAllUserList().at(id).getPurchasedList())->size() - 1));
	int LastSelectedGenre = am.searchMusicAlbumById(LastSelectedAlbum).getGenre();
	bool AlreadyBought;
	string Genre;

	for (int i = 0; (unsigned)i < AllAlbumList.size(); i++)
	{
		AlreadyBought = false;
		SelectedMusicAlbum = AllAlbumList.at(i);
		if (SelectedMusicAlbum.getGenre() == LastSelectedGenre) // 목록에서 장르 일치하는 앨범 찾음
		{
			for (int j = 0; (unsigned)j < um.getAllUserList().at(id).getPurchasedList()->size(); j++) 
			{
				if (SelectedMusicAlbum.getId() == um.getAllUserList().at(id).getPurchasedList()->at(j)) // 이미 구매한 앨범
					AlreadyBought = true;
			}
			if (!AlreadyBought)
			{
				RecMyAlgList.push_back(SelectedMusicAlbum);
			}
		}
	}
	
	switch (LastSelectedGenre)
	{
	case 0:
		Genre = "인디";
		break;
	case 1:
		Genre = "댄스";
		break;
	case 2:
		Genre = "발라드";
		break;
	case 3:
		Genre = "힙합";
		break;
	case 4:
		Genre = "OST";
		break;
	default:
		break;
	}

	cout << "회원님이 최근에 구매하신 장르는 " << Genre << "입니다." << endl;
	cout << "순위        곡명            장르" << endl;
	for (int i = 0; (unsigned)i < RecMyAlgList.size(); i++)
	{
		cout << setw(2) << i + 1 << setw(20) << RecMyAlgList.at(i).getName() << setw(10) << RecMyAlgList.at(i).getGenreName() << endl;
	}

	return RecMyAlgList;
}