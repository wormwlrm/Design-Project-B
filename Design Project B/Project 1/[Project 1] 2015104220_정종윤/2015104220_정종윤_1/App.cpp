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
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢" << endl;
	cout << "¦¢¦¢¡ì    Æ÷ÄÏ¸ó ¹èÆ² ÇÁ·Î±×·¥    ¡í¦¢¦¢" << endl;
	cout << "¦¢¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢" << endl;
	cout << "¦¢¦¢    |$aC#_^                                                   ¦¢¦¢" << endl;
	cout << "¦¢¦¢    lo$b{({~:                                                 ¦¢¦¢" << endl;
	cout << "¦¢¦¢      ?Mj)((||_.                             ^, ,             ¦¢¦¢" << endl;
	cout << "¦¢¦¢         <{t#|(((},     .^^^       .;>-}1((){@$$&/            ¦¢¦¢" << endl;
	cout << "¦¢¦¢           .+|t#(((?>]))))))))){+~{(()((((|||kbf^             ¦¢¦¢" << endl;
	cout << "¦¢¦¢               i]()(()))111111)))))(/ft(1?~l:                 ¦¢¦¢" << endl;
	cout << "¦¢¦¢                |))11111{11111111)(<                        . ¦¢¦¢" << endl;
	cout << "¦¢¦¢               +()1x/{111111111x/1(|               `;!>+-[}1) ¦¢¦¢" << endl;
	cout << "¦¢¦¢               @ $J|U{1111111w_@O{(I ^;      }1)(()))))))))   ¦¢¦¢" << endl;
	cout << "¦¢¦¢            j / )UbO1{ 11 | 111{xbm##f[<  ||(((())))))))))))) ¦¢¦¢" << endl;
	cout << "¦¢¦¢            _znv#{1))11|)11)111nuuv     {|(((())))))))))))-   ¦¢¦¢" << endl;
	cout << "¦¢¦¢            `Uzcu(|(|##(||#(((tzcC}     ||((((((()))))))-     ¦¢¦¢" << endl;
	cout << "¦¢¦¢             ^uvt///##||###////nc1    :||(((, Il!><~_~        ¦¢¦¢" << endl;
	cout << "¦¢¦¢                :t#tjjjjrrrrrrrxxxjf|     i#(||-              ¦¢¦¢" << endl;
	cout << "¦¢¦¢             [|()|tfrxnuuuunrj|)(#:<+-]]###||                 ¦¢¦¢" << endl;
	cout << "¦¢¦¢             ((111#/())))((|/(11)#Irt/////###1                ¦¢¦¢" << endl;
	cout << "¦¢¦¢             t()111|#)1{11)/)111)/>~Jv)I~+-][)^               ¦¢¦¢" << endl;
	cout << "¦¢¦¢            :u/(1111||1111/){11)(c|+pqm.                      ¦¢¦¢" << endl;
	cout << "¦¢¦¢           (t#|(((((((||||(((((((|/f!                         ¦¢¦¢" << endl;
	cout << "¦¢¦¢              {j/#|||#/tttttt//###||#tr:                      ¦¢¦¢" << endl;
	cout << "¦¢¦¢              .rjt/#tj       unnrft//fr}                      ¦¢¦¢" << endl;          
	cout << "¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;

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
	int notSelected[6] = {1,1,1,1,1,1}; // Áßº¹ ¼±ÅÃ ¹æÁö
	while(selected < 3)
	{
		int choice;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "³ªÀÇ Æ÷ÄÏ¸ó " << 3 - selected << "¸¶¸®¸¦ ¼±ÅÃÇØ ÁÖ¼¼¿ä." << endl;
		showPokemonList();

		cout << "¹øÈ£¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä. : ";
		cin >> choice;
		while(choice < 1 || choice > 6 || cin.fail() || notSelected[choice-1] == 0)
		{
			cout << "Error : Àß¸øµÈ ÀÔ·Â ¶Ç´Â Áßº¹µÈ ¼±ÅÃÀÔ´Ï´Ù." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "´Ù½Ã ÀÔ·ÂÇØ ÁÖ¼¼¿ä. : ";
			cin >> choice;
		}
		allyList.push_back(pf.create_pokemon(choice));
		cout << allyList.at(selected)->getName() << "À»(¸¦) ³ªÀÇ Æ÷ÄÏ¸ó ¸®½ºÆ®¿¡ ³Ö¾ú´Ù!"  << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		notSelected[choice - 1] = 0;
		selected++;
		clear();
	}
}

void App::selectEnemyPokemon()
{
	int selected = 0;
	int notSelected[6] = {1,1,1,1,1,1}; // Áßº¹ ¼±ÅÃ ¹æÁö
	while(selected < 3)
	{
		int choice;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "»ó´ë Æ÷ÄÏ¸ó " << 3 - selected << "¸¶¸®¸¦ ¼±ÅÃÇØ ÁÖ¼¼¿ä." << endl;
		showPokemonList();

		cout << "¹øÈ£¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä. : ";
		cin >> choice;
		while(choice < 1 || choice > 6 || cin.fail() || notSelected[choice-1] == 0)
		{
			cout << "Error : Àß¸øµÈ ÀÔ·Â ¶Ç´Â Áßº¹µÈ ¼±ÅÃÀÔ´Ï´Ù." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "´Ù½Ã ÀÔ·ÂÇØ ÁÖ¼¼¿ä. : ";
			cin >> choice;
		}
		enemyList.push_back(pf.create_pokemon(choice));
		cout << enemyList.at(selected)->getName() << "À»(¸¦) »ó´ë Æ÷ÄÏ¸ó ¸®½ºÆ®¿¡ ³Ö¾ú´Ù!"  << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		notSelected[choice - 1] = 0;
		selected++;
		clear();
	}
}

void App::showPokemonList()
{
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "            Æ÷ÄÏ¸ó ¸®½ºÆ®" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "1. ¸®ÀÚ¸ù" << endl;
	cout << "2. ÀÌ»óÇØ¾¾" << endl;
	cout << "3. °ÅºÏ¿Õ" << endl;
	cout << "4. ´Üµ¥±â" << endl;
	cout << "5. ±¸±¸" << endl;
	cout << "6. À×¾îÅ·" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
}

void App::startBattle()
{
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢" << endl;
	cout << "¦¢¦¢      ¹èÆ²À» ½ÃÀÛÇÕ´Ï´Ù.        ¦¢¦¢" << endl;
	cout << "¦¢¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©¦¢" << endl;
	cout << "¦¢¦¢³ªÀÇ Æ÷ÄÏ¸ó    vs    »ó´ë Æ÷ÄÏ¸ó¦¢¦¢" << endl;
	cout << "¦¢¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©¦¢" << endl;
	cout << "¦¢¦¢" << setw(10) << allyList.at(0)->getName() << setw(22) << enemyList.at(0)->getName() << "¦¢¦¢" << endl;
	cout << "¦¢¦¢" << setw(10) << allyList.at(1)->getName() << setw(22) << enemyList.at(1)->getName() << "¦¢¦¢" << endl;
	cout << "¦¢¦¢" << setw(10) << allyList.at(2)->getName() << setw(22) << enemyList.at(2)->getName() << "¦¢¦¢" << endl;
	cout << "¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	clear();

	while(allyList.size() != 0 && enemyList.size() != 0) // ¾Æ±º Àû±º Áß ÇÏ³ª¶óµµ Àü¸êÇÏ¸é ¹èÆ² Á¾·á
	{
		curAlly = allyList.at(0); // 0¹øÂ° ¾Æ±º Æ÷ÄÏ¸ó Å¸°ÔÆÃ, ÇöÀç Æ÷ÄÏ¸ó
		curEnemy = enemyList.at(0); // 0¹øÂ° Àû±º Æ÷ÄÏ¸ó Å¸°ÔÆÃ, ÇöÀç Æ÷ÄÏ¸ó
		while (curAlly->getHealthPoint() > 0 && curEnemy->getHealthPoint() > 0) // ÇöÀç Æ÷ÄÏ¸ó ³¢¸® ¹èÆ², ÇÏ³ªÀÇ Ã¼·ÂÀÌ 0ÀÌ µÇ´Â ¼ø°£ Á¾·á
		{
			printCurPokemon();

			int choice;
			bool choiceSuccess = false;
			cout << "            ³ªÀÇ ÅÏ" << endl;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			while (choiceSuccess == false)
			{
				cout << "ÀÌ¹ø ÅÏ¿¡ ¹«¾ùÀ» ÇÏ½Ã°Ú½À´Ï±î?" << endl;
				cout << "1. ÀÏ¹Ý °ø°Ý" << endl;
				cout << "2. ½ºÅ³ »ç¿ë" << endl;
				cout << "3. ÈÞ½Ä" << endl;
				cin >> choice;
				if (choice < 1 || choice > 3 || cin.fail()) // Àß¸øµÈ ÀÔ·Â ¿¹¿Ü Ã³¸®
				{
					cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
				}
				else if (choice == 2 && curAlly->getSkillCnt() == 0) // ½ºÅ³À» ¸ðµÎ »ç¿ëÇßÀ» °æ¿ì
				{
					cout << "½ºÅ³À» ¸ðµÎ »ç¿ëÇÏ¿´½À´Ï´Ù." << endl;
				}
				else
					choiceSuccess = true;
			}

			int effective;
			switch (choice)
			{
			case 1:
				tb = new AttackBehavior;				
				cout << curAlly->getName() << "ÀÇ ¸öÅë ¹ÚÄ¡±â!" << endl;
				effective = tb->executeTurn(curAlly,curEnemy);
				if (effective == 2)
				{
					cout << "È¿°ú´Â ´ë´ÜÇß´Ù!" << endl;
				}
				else if (effective == 0)
				{
					cout << "È¿°ú°¡ º°·ÎÀÎ µí ÇÏ´Ù..." << endl;
				}
				break;
			case 2:
				tb = new SkillBehavior;
				tb->executeTurn(curAlly,curEnemy);
				break;
			case 3:
				tb = new RestBehavior;
				cout << curAlly->getName() << "Àº(´Â) ÀÌ¹ø ÅÏ¿¡ ÈÞ½ÄÇÏ¿´´Ù!" << endl;
				cout << "Ã¼·ÂÀ» ¼Ò·® È¸º¹Çß´Ù!" << endl;
				tb->executeTurn(curAlly, curEnemy);
				break;
			default:
				break;
			}
			clear();

			if (curEnemy->getHealthPoint() <= 0) // Àû±º ÇöÀç Æ÷ÄÏ¸óÀÇ ÆÐ¹è
			{
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				cout << curEnemy->getName() << "Àº(´Â) ¾²·¯Á³´Ù!" << endl;
				for (size_t i = 0; i < enemyList.size() - 1; i++) // Æ÷ÄÏ¸óÀ» ÇÑ Ä­¾¿ ¾ÕÀ¸·Î ´ç±ä´Ù
				{
					enemyList.at(i) = enemyList.at(i + 1);
				}
				if (enemyList.size() == 1)
				{
					cout << "»ó´ë¿¡°Ô´Â ´õ ÀÌ»ó ³²Àº Æ÷ÄÏ¸óÀÌ ¾ø´Ù!" << endl;
					cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
					cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
					enemyList.pop_back();
					break;
				}
				else
				{
					cout << "»ó´ë´Â " << enemyList.at(0)->getName() << "À»(¸¦) ²¨³Â´Ù!" << endl;
				}
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				enemyList.pop_back();
				break;
			}

			printCurPokemon();

			cout << "           »ó´ëÀÇ ÅÏ" << endl; 
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;

			choiceSuccess = false;
			while (choiceSuccess == false)
			{
				cout << "ÀÌ¹ø ÅÏ¿¡ ¹«¾ùÀ» ÇÏ½Ã°Ú½À´Ï±î?" << endl;
				cout << "1. ÀÏ¹Ý °ø°Ý" << endl;
				cout << "2. ½ºÅ³ »ç¿ë" << endl;
				cout << "3. ÈÞ½Ä" << endl;
				cin >> choice;
				if (choice < 1 || choice > 3 || cin.fail()) // Àß¸øµÈ ÀÔ·Â ¿¹¿Ü Ã³¸®
				{
					cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
				}
				else if (choice == 2 && curEnemy->getSkillCnt() == 0) // ½ºÅ³À» ¸ðµÎ »ç¿ëÇßÀ» °æ¿ì
				{
					cout << "½ºÅ³À» ¸ðµÎ »ç¿ëÇÏ¿´½À´Ï´Ù." << endl;
				}
				else
					choiceSuccess = true;
				
			}

			switch (choice)
			{
			case 1:
				tb = new AttackBehavior;
				cout << curEnemy->getName() << "ÀÇ ¸öÅë ¹ÚÄ¡±â!" << endl;
				effective = tb->executeTurn(curEnemy, curAlly);
				if (effective == 2)
				{
					cout << "È¿°ú´Â ´ë´ÜÇß´Ù!" << endl;
				}
				else if (effective == 0)
				{
					cout << "È¿°ú°¡ º°·ÎÀÎ µí ÇÏ´Ù..." << endl;
				}
				break;
			case 2:
				tb = new SkillBehavior;
				tb->executeTurn(curEnemy, curAlly);
				break;
			case 3:
				tb = new RestBehavior;
				cout << curEnemy->getName() << "Àº(´Â) ÀÌ¹ø ÅÏ¿¡ ÈÞ½ÄÇÏ¿´´Ù!" << endl;
				cout << "Ã¼·ÂÀ» ¼Ò·® È¸º¹Çß´Ù!" << endl;
				tb->executeTurn(curEnemy, curAlly);
				break;
			default:
				break;
			}
			clear();
		}

		if (curAlly->getHealthPoint() <= 0) // ¾Æ±º ÇöÀç Æ÷ÄÏ¸óÀÇ ÆÐ¹è
		{
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			cout << curAlly->getName() << "Àº(´Â) ¾²·¯Á³´Ù!" << endl;
			if (allyList.size() == 1)
			{
				cout << endl << "³ª¿¡°Ô´Â ´õ ÀÌ»ó ³²Àº Æ÷ÄÏ¸óÀÌ ¾ø´Ù!" << endl;
				cout << "´« ¾ÕÀÌ Ä¯Ä¯ÇØÁ³´Ù..." << endl;
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				allyList.pop_back();
				break;
			}
			cout << "¼ö°íÇß¾î! µ¹¾Æ¿Í, " << curAlly->getName() << "!" << endl;
			for (size_t i = 0; i < allyList.size() - 1; i++) // Æ÷ÄÏ¸óÀ» ÇÑ Ä­¾¿ ¾ÕÀ¸·Î ´ç±ä´Ù
			{
				allyList.at(i) = allyList.at(i + 1);
			}
			cout << "°¡¶ó, " << allyList.at(1)->getName() << "!" << endl;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			allyList.pop_back();
		}		
		clear();
	}
	if (enemyList.size() == 0)
	{
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢" << endl;
		cout << "¦¢¦¢¡ì           ½Â¸®!            ¡í¦¢¦¢" << endl;
		cout << "¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	}
	else if (allyList.size() == 0)
	{
		clear();
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢" << endl;
		cout << "¦¢¦¢¡ì             ÆÐ¹è...        ¡í¦¢¦¢" << endl;
		cout << "¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	}
}

void App::selectTurnBehavior()
{

}

void App::printAllyPokemon()
{
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "          ¼±ÅÃµÈ ¾Æ±º Æ÷ÄÏ¸ó" << endl;
	for(size_t i = 0; i < 3; i++)
	{
		Pokemon* Cur = allyList.at(i);
		cout << Cur->getName() << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "Ã¼·Â           : " << Cur->getHealthPoint() << "/" << Cur->getMaximumHealthPoint() << endl;
		cout << "°ø°Ý·Â         : " << Cur->getAttackPoint() << endl;
		cout << "¹æ¾î·Â         : " << Cur->getDefensePoint() << endl;
		cout << "ÀÜ¿© ½ºÅ³ È½¼ö : " << Cur->getSkillCnt() << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	}
}

void App::printEnemyPokemon()
{
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "          ¼±ÅÃµÈ Àû±º Æ÷ÄÏ¸ó" << endl;
	for(size_t i = 0; i < 3; i++)
	{
		Pokemon* Cur = enemyList.at(i);
		cout << Cur->getName() << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "Ã¼·Â           : " << Cur->getHealthPoint() << "/" << Cur->getMaximumHealthPoint() << endl;
		cout << "°ø°Ý·Â         : " << Cur->getAttackPoint() << endl;
		cout << "¹æ¾î·Â         : " << Cur->getDefensePoint() << endl;
		cout << "ÀÜ¿© ½ºÅ³ È½¼ö : " << Cur->getSkillCnt() << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	}
}

void App::printCurPokemon()
{
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "³ªÀÇ Æ÷ÄÏ¸ó" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << curAlly->getName() << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "Ã¼·Â           : " << curAlly->getHealthPoint() << "/" << curAlly->getMaximumHealthPoint() << endl;
	cout << "°ø°Ý·Â         : " << curAlly->getAttackPoint() << endl;
	cout << "¹æ¾î·Â         : " << curAlly->getDefensePoint() << endl;
	cout << "ÀÜ¿© ½ºÅ³ È½¼ö : " << curAlly->getSkillCnt() << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;

	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "»ó´ë Æ÷ÄÏ¸ó" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << curEnemy->getName() << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "Ã¼·Â           : " << curEnemy->getHealthPoint() << "/" << curEnemy->getMaximumHealthPoint() << endl;
	cout << "°ø°Ý·Â         : " << curEnemy->getAttackPoint() << endl;
	cout << "¹æ¾î·Â         : " << curEnemy->getDefensePoint() << endl;
	cout << "ÀÜ¿© ½ºÅ³ È½¼ö : " << curEnemy->getSkillCnt() << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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