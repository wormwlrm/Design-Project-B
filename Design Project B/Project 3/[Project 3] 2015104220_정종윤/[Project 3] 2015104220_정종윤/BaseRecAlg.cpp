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
		for (int j = 0; (unsigned)j < AllAlbumList.size(); j++) // ���� ���� Ƚ�� ū �ٹ� ã��
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

	cout << "����         ���      ���� Ƚ��" << endl;
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
		if (SelectedMusicAlbum.getGenre() == LastSelectedGenre) // ��Ͽ��� �帣 ��ġ�ϴ� �ٹ� ã��
		{
			for (int j = 0; (unsigned)j < um.getAllUserList().at(id).getPurchasedList()->size(); j++) 
			{
				if (SelectedMusicAlbum.getId() == um.getAllUserList().at(id).getPurchasedList()->at(j)) // �̹� ������ �ٹ�
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
		Genre = "�ε�";
		break;
	case 1:
		Genre = "��";
		break;
	case 2:
		Genre = "�߶��";
		break;
	case 3:
		Genre = "����";
		break;
	case 4:
		Genre = "OST";
		break;
	default:
		break;
	}

	cout << "ȸ������ �ֱٿ� �����Ͻ� �帣�� " << Genre << "�Դϴ�." << endl;
	cout << "����        ���            �帣" << endl;
	for (int i = 0; (unsigned)i < RecMyAlgList.size(); i++)
	{
		cout << setw(2) << i + 1 << setw(20) << RecMyAlgList.at(i).getName() << setw(10) << RecMyAlgList.at(i).getGenreName() << endl;
	}

	return RecMyAlgList;
}