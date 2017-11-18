#include "App.h"

App::App()
{
	
}

App::~App()
{

}

void App::clear()
{
	system("pause");
	system("cls");	
}

void App::run()
{
	cout << "����������������������������������������" << endl;
	cout << "����������������������������������������" << endl;
	cout << "������    ���ϸ� ��Ʋ ���α׷�    ����" << endl;
	cout << "����������������������������������������������������������������������" << endl;
	cout << "����������������������������������������������������������������������" << endl;
	cout << "����    |$aC#_^                                                   ����" << endl;
	cout << "����    lo$b{({~:                                                 ����" << endl;
	cout << "����      ?Mj)((||_.                             ^, ,             ����" << endl;
	cout << "����         <{t#|(((},     .^^^       .;>-}1((){@$$&/            ����" << endl;
	cout << "����           .+|t#(((?>]))))))))){+~{(()((((|||kbf^             ����" << endl;
	cout << "����               i]()(()))111111)))))(/ft(1?~l:                 ����" << endl;
	cout << "����                |))11111{11111111)(<                        . ����" << endl;
	cout << "����               +()1x/{111111111x/1(|               `;!>+-[}1) ����" << endl;
	cout << "����               @ $J|U{1111111w_@O{(I ^;      }1)(()))))))))   ����" << endl;
	cout << "����            j / )UbO1{ 11 | 111{xbm##f[<  ||(((())))))))))))) ����" << endl;
	cout << "����            _znv#{1))11|)11)111nuuv     {|(((())))))))))))-   ����" << endl;
	cout << "����            `Uzcu(|(|##(||#(((tzcC}     ||((((((()))))))-     ����" << endl;
	cout << "����             ^uvt///##||###////nc1    :||(((, Il!><~_~        ����" << endl;
	cout << "����                :t#tjjjjrrrrrrrxxxjf|     i#(||-              ����" << endl;
	cout << "����             [|()|tfrxnuuuunrj|)(#:<+-]]###||                 ����" << endl;
	cout << "����             ((111#/())))((|/(11)#Irt/////###1                ����" << endl;
	cout << "����             t()111|#)1{11)/)111)/>~Jv)I~+-][)^               ����" << endl;
	cout << "����            :u/(1111||1111/){11)(c|+pqm.                      ����" << endl;
	cout << "����           (t#|(((((((||||(((((((|/f!                         ����" << endl;
	cout << "����              {j/#|||#/tttttt//###||#tr:                      ����" << endl;
	cout << "����              .rjt/#tj       unnrft//fr}                      ����" << endl;          
	cout << "����������������������������������������������������������������������" << endl;
	cout << "����������������������������������������������������������������������" << endl;

	clear();
	selectAllyPokemon();
	printAllyPokemon();
	clear();
	selectEnemyPokemon();
	printEnemyPokemon();
	clear();

	startBattle();
}

void App::selectAllyPokemon()
{
	int selected = 0;
	int notSelected[6] = {1,1,1,1,1,1}; // �ߺ� ���� ����
	while(selected < 3)
	{
		int choice;
		cout << "����������������������������������������" << endl;
		cout << "���� ���ϸ� " << 3 - selected << "������ ������ �ּ���." << endl;
		showPokemonList();

		cout << "��ȣ�� �Է��� �ּ���. : ";
		cin >> choice;
		while(choice < 1 || choice > 6 || cin.fail() || notSelected[choice-1] == 0)
		{
			cout << "Error : �߸��� �Է� �Ǵ� �ߺ��� �����Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "�ٽ� �Է��� �ּ���. : ";
			cin >> choice;
		}
		allyList.push_back(pf.create_pokemon(choice));
		cout << allyList.at(selected)->getName() << "��(��) ���� ���ϸ� ����Ʈ�� �־���!"  << endl;
		cout << "����������������������������������������" << endl;
		notSelected[choice - 1] = 0;
		selected++;
		clear();
	}
}

void App::selectEnemyPokemon()
{
	int selected = 0;
	int notSelected[6] = {1,1,1,1,1,1}; // �ߺ� ���� ����
	while(selected < 3)
	{
		int choice;
		cout << "����������������������������������������" << endl;
		cout << "��� ���ϸ� " << 3 - selected << "������ ������ �ּ���." << endl;
		showPokemonList();

		cout << "��ȣ�� �Է��� �ּ���. : ";
		cin >> choice;
		while(choice < 1 || choice > 6 || cin.fail() || notSelected[choice-1] == 0)
		{
			cout << "Error : �߸��� �Է� �Ǵ� �ߺ��� �����Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "�ٽ� �Է��� �ּ���. : ";
			cin >> choice;
		}
		enemyList.push_back(pf.create_pokemon(choice));
		cout << enemyList.at(selected)->getName() << "��(��) ��� ���ϸ� ����Ʈ�� �־���!"  << endl;
		cout << "����������������������������������������" << endl;
		notSelected[choice - 1] = 0;
		selected++;
		clear();
	}
}

void App::showPokemonList()
{
	cout << "����������������������������������������" << endl;
	cout << "            ���ϸ� ����Ʈ" << endl;
	cout << "����������������������������������������" << endl;
	cout << "1. ���ڸ�" << endl;
	cout << "2. �̻��ؾ�" << endl;
	cout << "3. �źϿ�" << endl;
	cout << "4. �ܵ���" << endl;
	cout << "5. ����" << endl;
	cout << "6. �׾�ŷ" << endl;
	cout << "����������������������������������������" << endl;
}

void App::startBattle()
{
	cout << "����������������������������������������" << endl;
	cout << "����������������������������������������" << endl;
	cout << "����      ��Ʋ�� �����մϴ�.        ����" << endl;
	cout << "����������������������������������������" << endl;
	cout << "�������� ���ϸ�    vs    ��� ���ϸ󦢦�" << endl;
	cout << "����������������������������������������" << endl;
	cout << "����" << setw(10) << allyList.at(0)->getName() << setw(22) << enemyList.at(0)->getName() << "����" << endl;
	cout << "����" << setw(10) << allyList.at(1)->getName() << setw(22) << enemyList.at(1)->getName() << "����" << endl;
	cout << "����" << setw(10) << allyList.at(2)->getName() << setw(22) << enemyList.at(2)->getName() << "����" << endl;
	cout << "����������������������������������������" << endl;
	cout << "����������������������������������������" << endl;
	clear();

	while(allyList.size() != 0 && enemyList.size() != 0) // �Ʊ� ���� �� �ϳ��� �����ϸ� ��Ʋ ����
	{
		curAlly = allyList.at(0); // 0��° �Ʊ� ���ϸ� Ÿ����, ���� ���ϸ�
		curEnemy = enemyList.at(0); // 0��° ���� ���ϸ� Ÿ����, ���� ���ϸ�
		while (curAlly->getHealthPoint() > 0 && curEnemy->getHealthPoint() > 0) // ���� ���ϸ� ���� ��Ʋ, �ϳ��� ü���� 0�� �Ǵ� ���� ����
		{
			printCurPokemon();

			int choice;
			bool choiceSuccess = false;
			cout << "            ���� ��" << endl;
			cout << "����������������������������������������" << endl;
			while (choiceSuccess == false)
			{
				cout << "�̹� �Ͽ� ������ �Ͻðڽ��ϱ�?" << endl;
				cout << "1. �Ϲ� ����" << endl;
				cout << "2. ��ų ���" << endl;
				cout << "3. �޽�" << endl;
				cin >> choice;
				if (choice < 1 || choice > 3 || cin.fail()) // �߸��� �Է� ���� ó��
				{
					cout << "�߸��� �Է��Դϴ�." << endl;
				}
				else if (choice == 2 && curAlly->getSkillCnt() == 0) // ��ų�� ��� ������� ���
				{
					cout << "��ų�� ��� ����Ͽ����ϴ�." << endl;
				}
				else
					choiceSuccess = true;
			}

			int effective;
			switch (choice)
			{
			case 1:
				tb = new AttackBehavior;				
				cout << curAlly->getName() << "�� ���� ��ġ��!" << endl;
				effective = tb->executeTurn(curAlly,curEnemy);
				if (effective == 2)
				{
					cout << "ȿ���� ����ߴ�!" << endl;
				}
				else if (effective == 0)
				{
					cout << "ȿ���� ������ �� �ϴ�..." << endl;
				}
				break;
			case 2:
				tb = new SkillBehavior;
				tb->executeTurn(curAlly,curEnemy);
				break;
			case 3:
				tb = new RestBehavior;
				cout << curAlly->getName() << "��(��) �̹� �Ͽ� �޽��Ͽ���!" << endl;
				cout << "ü���� �ҷ� ȸ���ߴ�!" << endl;
				tb->executeTurn(curAlly, curEnemy);
				break;
			default:
				break;
			}
			clear();

			if (curEnemy->getHealthPoint() <= 0) // ���� ���� ���ϸ��� �й�
			{
				cout << "����������������������������������������" << endl;
				cout << "����������������������������������������" << endl;
				cout << curEnemy->getName() << "��(��) ��������!" << endl;
				for (size_t i = 0; i < enemyList.size() - 1; i++) // ���ϸ��� �� ĭ�� ������ ����
				{
					enemyList.at(i) = enemyList.at(i + 1);
				}
				if (enemyList.size() == 1)
				{
					cout << "��뿡�Դ� �� �̻� ���� ���ϸ��� ����!" << endl;
					cout << "����������������������������������������" << endl;
					cout << "����������������������������������������" << endl;
					enemyList.pop_back();
					break;
				}
				else
				{
					cout << "���� " << enemyList.at(0)->getName() << "��(��) ���´�!" << endl;
				}
				cout << "����������������������������������������" << endl;
				cout << "����������������������������������������" << endl;
				enemyList.pop_back();
				break;
			}

			printCurPokemon();

			cout << "           ����� ��" << endl; 
			cout << "����������������������������������������" << endl;

			choiceSuccess = false;
			while (choiceSuccess == false)
			{
				cout << "�̹� �Ͽ� ������ �Ͻðڽ��ϱ�?" << endl;
				cout << "1. �Ϲ� ����" << endl;
				cout << "2. ��ų ���" << endl;
				cout << "3. �޽�" << endl;
				cin >> choice;
				if (choice < 1 || choice > 3 || cin.fail()) // �߸��� �Է� ���� ó��
				{
					cout << "�߸��� �Է��Դϴ�." << endl;
				}
				else if (choice == 2 && curEnemy->getSkillCnt() == 0) // ��ų�� ��� ������� ���
				{
					cout << "��ų�� ��� ����Ͽ����ϴ�." << endl;
				}
				else
					choiceSuccess = true;
				
			}

			switch (choice)
			{
			case 1:
				tb = new AttackBehavior;
				cout << curEnemy->getName() << "�� ���� ��ġ��!" << endl;
				effective = tb->executeTurn(curEnemy, curAlly);
				if (effective == 2)
				{
					cout << "ȿ���� ����ߴ�!" << endl;
				}
				else if (effective == 0)
				{
					cout << "ȿ���� ������ �� �ϴ�..." << endl;
				}
				break;
			case 2:
				tb = new SkillBehavior;
				tb->executeTurn(curEnemy, curAlly);
				break;
			case 3:
				tb = new RestBehavior;
				cout << curEnemy->getName() << "��(��) �̹� �Ͽ� �޽��Ͽ���!" << endl;
				cout << "ü���� �ҷ� ȸ���ߴ�!" << endl;
				tb->executeTurn(curEnemy, curAlly);
				break;
			default:
				break;
			}
			clear();
		}

		if (curAlly->getHealthPoint() <= 0) // �Ʊ� ���� ���ϸ��� �й�
		{
			cout << "����������������������������������������" << endl;
			cout << "����������������������������������������" << endl;
			cout << curAlly->getName() << "��(��) ��������!" << endl;
			if (allyList.size() == 1)
			{
				cout << endl << "�����Դ� �� �̻� ���� ���ϸ��� ����!" << endl;
				cout << "�� ���� įį������..." << endl;
				cout << "����������������������������������������" << endl;
				cout << "����������������������������������������" << endl;
				allyList.pop_back();
				break;
			}
			cout << "�����߾�! ���ƿ�, " << curAlly->getName() << "!" << endl;
			for (size_t i = 0; i < allyList.size() - 1; i++) // ���ϸ��� �� ĭ�� ������ ����
			{
				allyList.at(i) = allyList.at(i + 1);
			}
			cout << "����, " << allyList.at(1)->getName() << "!" << endl;
			cout << "����������������������������������������" << endl;
			cout << "����������������������������������������" << endl;
			allyList.pop_back();
		}		
		clear();
	}
	if (enemyList.size() == 0)
	{
		cout << "����������������������������������������" << endl;
		cout << "����������������������������������������" << endl;
		cout << "������           �¸�!            ����" << endl;
		cout << "����������������������������������������" << endl;
		cout << "����������������������������������������" << endl;
	}
	else if (allyList.size() == 0)
	{
		clear();
		cout << "����������������������������������������" << endl;
		cout << "����������������������������������������" << endl;
		cout << "������             �й�...        ����" << endl;
		cout << "����������������������������������������" << endl;
		cout << "����������������������������������������" << endl;
	}
}

void App::selectTurnBehavior()
{

}

void App::printAllyPokemon()
{
	cout << "����������������������������������������" << endl;
	cout << "          ���õ� �Ʊ� ���ϸ�" << endl;
	for(size_t i = 0; i < 3; i++)
	{
		Pokemon* Cur = allyList.at(i);
		cout << Cur->getName() << endl;
		cout << "����������������������������������������" << endl;
		cout << "ü��           : " << Cur->getHealthPoint() << "/" << Cur->getMaximumHealthPoint() << endl;
		cout << "���ݷ�         : " << Cur->getAttackPoint() << endl;
		cout << "����         : " << Cur->getDefensePoint() << endl;
		cout << "�ܿ� ��ų Ƚ�� : " << Cur->getSkillCnt() << endl;
		cout << "����������������������������������������" << endl;
	}
}

void App::printEnemyPokemon()
{
	cout << "����������������������������������������" << endl;
	cout << "          ���õ� ���� ���ϸ�" << endl;
	for(size_t i = 0; i < 3; i++)
	{
		Pokemon* Cur = enemyList.at(i);
		cout << Cur->getName() << endl;
		cout << "����������������������������������������" << endl;
		cout << "ü��           : " << Cur->getHealthPoint() << "/" << Cur->getMaximumHealthPoint() << endl;
		cout << "���ݷ�         : " << Cur->getAttackPoint() << endl;
		cout << "����         : " << Cur->getDefensePoint() << endl;
		cout << "�ܿ� ��ų Ƚ�� : " << Cur->getSkillCnt() << endl;
		cout << "����������������������������������������" << endl;
	}
}

void App::printCurPokemon()
{
	cout << "����������������������������������������" << endl;
	cout << "���� ���ϸ�" << endl;
	cout << "����������������������������������������" << endl;
	cout << curAlly->getName() << endl;
	cout << "����������������������������������������" << endl;
	cout << "ü��           : " << curAlly->getHealthPoint() << "/" << curAlly->getMaximumHealthPoint() << endl;
	cout << "���ݷ�         : " << curAlly->getAttackPoint() << endl;
	cout << "����         : " << curAlly->getDefensePoint() << endl;
	cout << "�ܿ� ��ų Ƚ�� : " << curAlly->getSkillCnt() << endl;
	cout << "����������������������������������������" << endl;

	cout << "����������������������������������������" << endl;
	cout << "��� ���ϸ�" << endl;
	cout << "����������������������������������������" << endl;
	cout << curEnemy->getName() << endl;
	cout << "����������������������������������������" << endl;
	cout << "ü��           : " << curEnemy->getHealthPoint() << "/" << curEnemy->getMaximumHealthPoint() << endl;
	cout << "���ݷ�         : " << curEnemy->getAttackPoint() << endl;
	cout << "����         : " << curEnemy->getDefensePoint() << endl;
	cout << "�ܿ� ��ų Ƚ�� : " << curEnemy->getSkillCnt() << endl;
	cout << "����������������������������������������" << endl;
}

void App::executeTurn()
{

}

vector<Pokemon*> App::getAllyList()
{
	return allyList;
}

vector<Pokemon*> App::getEnemyList()
{
	return enemyList;
}

Pokemon* App::getCurAlly()
{
	return allyList.at(0);
}

Pokemon* App::getCurEnemy()
{
	return enemyList.at(0);
}