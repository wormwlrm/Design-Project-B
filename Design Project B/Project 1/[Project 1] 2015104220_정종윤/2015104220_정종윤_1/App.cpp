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
	cout << "忙式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛忙式式式式式式式式式式式式式式式式忖弛" << endl;
	cout << "弛弛∫    ん鰍跨 寡ぎ Щ煎斜極    ∮弛弛" << endl;
	cout << "弛戍式式式式式式式式式式式式式式式式托托式式式式式式式式式式式式式式忖" << endl;
	cout << "弛戍式式式式式式式式式式式式式式式式扛扛式式式式式式式式式式式式式忖弛" << endl;
	cout << "弛弛    |$aC#_^                                                   弛弛" << endl;
	cout << "弛弛    lo$b{({~:                                                 弛弛" << endl;
	cout << "弛弛      ?Mj)((||_.                             ^, ,             弛弛" << endl;
	cout << "弛弛         <{t#|(((},     .^^^       .;>-}1((){@$$&/            弛弛" << endl;
	cout << "弛弛           .+|t#(((?>]))))))))){+~{(()((((|||kbf^             弛弛" << endl;
	cout << "弛弛               i]()(()))111111)))))(/ft(1?~l:                 弛弛" << endl;
	cout << "弛弛                |))11111{11111111)(<                        . 弛弛" << endl;
	cout << "弛弛               +()1x/{111111111x/1(|               `;!>+-[}1) 弛弛" << endl;
	cout << "弛弛               @ $J|U{1111111w_@O{(I ^;      }1)(()))))))))   弛弛" << endl;
	cout << "弛弛            j / )UbO1{ 11 | 111{xbm##f[<  ||(((())))))))))))) 弛弛" << endl;
	cout << "弛弛            _znv#{1))11|)11)111nuuv     {|(((())))))))))))-   弛弛" << endl;
	cout << "弛弛            `Uzcu(|(|##(||#(((tzcC}     ||((((((()))))))-     弛弛" << endl;
	cout << "弛弛             ^uvt///##||###////nc1    :||(((, Il!><~_~        弛弛" << endl;
	cout << "弛弛                :t#tjjjjrrrrrrrxxxjf|     i#(||-              弛弛" << endl;
	cout << "弛弛             [|()|tfrxnuuuunrj|)(#:<+-]]###||                 弛弛" << endl;
	cout << "弛弛             ((111#/())))((|/(11)#Irt/////###1                弛弛" << endl;
	cout << "弛弛             t()111|#)1{11)/)111)/>~Jv)I~+-][)^               弛弛" << endl;
	cout << "弛弛            :u/(1111||1111/){11)(c|+pqm.                      弛弛" << endl;
	cout << "弛弛           (t#|(((((((||||(((((((|/f!                         弛弛" << endl;
	cout << "弛弛              {j/#|||#/tttttt//###||#tr:                      弛弛" << endl;
	cout << "弛弛              .rjt/#tj       unnrft//fr}                      弛弛" << endl;          
	cout << "弛戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;

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
	int notSelected[6] = {1,1,1,1,1,1}; // 醞犒 摹鷗 寞雖
	while(selected < 3)
	{
		int choice;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "釭曖 ん鰍跨 " << 3 - selected << "葆葬蒂 摹鷗п 輿撮蹂." << endl;
		showPokemonList();

		cout << "廓�ㄧ� 殮溘п 輿撮蹂. : ";
		cin >> choice;
		while(choice < 1 || choice > 6 || cin.fail() || notSelected[choice-1] == 0)
		{
			cout << "Error : 澀跤脹 殮溘 傳朝 醞犒脹 摹鷗殮棲棻." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "棻衛 殮溘п 輿撮蹂. : ";
			cin >> choice;
		}
		allyList.push_back(pf.create_pokemon(choice));
		cout << allyList.at(selected)->getName() << "擊(蒂) 釭曖 ん鰍跨 葬蝶お縑 厥歷棻!"  << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
		notSelected[choice - 1] = 0;
		selected++;
		clear();
	}
}

void App::selectEnemyPokemon()
{
	int selected = 0;
	int notSelected[6] = {1,1,1,1,1,1}; // 醞犒 摹鷗 寞雖
	while(selected < 3)
	{
		int choice;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "鼻渠 ん鰍跨 " << 3 - selected << "葆葬蒂 摹鷗п 輿撮蹂." << endl;
		showPokemonList();

		cout << "廓�ㄧ� 殮溘п 輿撮蹂. : ";
		cin >> choice;
		while(choice < 1 || choice > 6 || cin.fail() || notSelected[choice-1] == 0)
		{
			cout << "Error : 澀跤脹 殮溘 傳朝 醞犒脹 摹鷗殮棲棻." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "棻衛 殮溘п 輿撮蹂. : ";
			cin >> choice;
		}
		enemyList.push_back(pf.create_pokemon(choice));
		cout << enemyList.at(selected)->getName() << "擊(蒂) 鼻渠 ん鰍跨 葬蝶お縑 厥歷棻!"  << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
		notSelected[choice - 1] = 0;
		selected++;
		clear();
	}
}

void App::showPokemonList()
{
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "            ん鰍跨 葬蝶お" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "1. 葬濠跦" << endl;
	cout << "2. 檜鼻п噢" << endl;
	cout << "3. 剪磁諾" << endl;
	cout << "4. 欽等晦" << endl;
	cout << "5. 掘掘" << endl;
	cout << "6. 濘橫韁" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
}

void App::startBattle()
{
	cout << "忙式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛忙式式式式式式式式式式式式式式式式忖弛" << endl;
	cout << "弛弛      寡ぎ擊 衛濛м棲棻.        弛弛" << endl;
	cout << "弛戍式式式式式式式式式式式式式式式式扣弛" << endl;
	cout << "弛弛釭曖 ん鰍跨    vs    鼻渠 ん鰍跨弛弛" << endl;
	cout << "弛戍式式式式式式式式式式式式式式式式扣弛" << endl;
	cout << "弛弛" << setw(10) << allyList.at(0)->getName() << setw(22) << enemyList.at(0)->getName() << "弛弛" << endl;
	cout << "弛弛" << setw(10) << allyList.at(1)->getName() << setw(22) << enemyList.at(1)->getName() << "弛弛" << endl;
	cout << "弛弛" << setw(10) << allyList.at(2)->getName() << setw(22) << enemyList.at(2)->getName() << "弛弛" << endl;
	cout << "弛戌式式式式式式式式式式式式式式式式戎弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式戎" << endl;
	clear();

	while(allyList.size() != 0 && enemyList.size() != 0) // 嬴捱 瞳捱 醞 ж釭塭紫 瞪資ж賊 寡ぎ 謙猿
	{
		curAlly = allyList.at(0); // 0廓簞 嬴捱 ん鰍跨 顫啪た, ⑷營 ん鰍跨
		curEnemy = enemyList.at(0); // 0廓簞 瞳捱 ん鰍跨 顫啪た, ⑷營 ん鰍跨
		while (curAlly->getHealthPoint() > 0 && curEnemy->getHealthPoint() > 0) // ⑷營 ん鰍跨 郭葬 寡ぎ, ж釭曖 羹溘檜 0檜 腎朝 牖除 謙猿
		{
			printCurPokemon();

			int choice;
			bool choiceSuccess = false;
			cout << "            釭曖 欐" << endl;
			cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
			while (choiceSuccess == false)
			{
				cout << "檜廓 欐縑 鼠歙擊 ж衛啊蝗棲梱?" << endl;
				cout << "1. 橾奩 奢問" << endl;
				cout << "2. 蝶鑒 餌辨" << endl;
				cout << "3. �瑍�" << endl;
				cin >> choice;
				if (choice < 1 || choice > 3 || cin.fail()) // 澀跤脹 殮溘 蕨諼 籀葬
				{
					cout << "澀跤脹 殮溘殮棲棻." << endl;
				}
				else if (choice == 2 && curAlly->getSkillCnt() == 0) // 蝶鑒擊 賅舒 餌辨ц擊 唳辦
				{
					cout << "蝶鑒擊 賅舒 餌辨ж艘蝗棲棻." << endl;
				}
				else
					choiceSuccess = true;
			}

			int effective;
			switch (choice)
			{
			case 1:
				tb = new AttackBehavior;				
				cout << curAlly->getName() << "曖 跺鱔 夢纂晦!" << endl;
				effective = tb->executeTurn(curAlly,curEnemy);
				if (effective == 2)
				{
					cout << "�膩�朝 渠欽ц棻!" << endl;
				}
				else if (effective == 0)
				{
					cout << "�膩�陛 滌煎檣 蛭 ж棻..." << endl;
				}
				break;
			case 2:
				tb = new SkillBehavior;
				tb->executeTurn(curAlly,curEnemy);
				break;
			case 3:
				tb = new RestBehavior;
				cout << curAlly->getName() << "擎(朝) 檜廓 欐縑 �瑍饒狤斐�!" << endl;
				cout << "羹溘擊 模榆 �蛹嘎葧�!" << endl;
				tb->executeTurn(curAlly, curEnemy);
				break;
			default:
				break;
			}
			clear();

			if (curEnemy->getHealthPoint() <= 0) // 瞳捱 ⑷營 ん鰍跨曖 ぬ寡
			{
				cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
				cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
				cout << curEnemy->getName() << "擎(朝) 噙楝螺棻!" << endl;
				for (size_t i = 0; i < enemyList.size() - 1; i++) // ん鰍跨擊 и 蘊噶 擅戲煎 渡曹棻
				{
					enemyList.at(i) = enemyList.at(i + 1);
				}
				if (enemyList.size() == 1)
				{
					cout << "鼻渠縑啪朝 渦 檜鼻 陴擎 ん鰍跨檜 橈棻!" << endl;
					cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
					cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
					enemyList.pop_back();
					break;
				}
				else
				{
					cout << "鼻渠朝 " << enemyList.at(0)->getName() << "擊(蒂) 疏麻棻!" << endl;
				}
				cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
				cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
				enemyList.pop_back();
				break;
			}

			printCurPokemon();

			cout << "           鼻渠曖 欐" << endl; 
			cout << "式式式式式式式式式式式式式式式式式式式式" << endl;

			choiceSuccess = false;
			while (choiceSuccess == false)
			{
				cout << "檜廓 欐縑 鼠歙擊 ж衛啊蝗棲梱?" << endl;
				cout << "1. 橾奩 奢問" << endl;
				cout << "2. 蝶鑒 餌辨" << endl;
				cout << "3. �瑍�" << endl;
				cin >> choice;
				if (choice < 1 || choice > 3 || cin.fail()) // 澀跤脹 殮溘 蕨諼 籀葬
				{
					cout << "澀跤脹 殮溘殮棲棻." << endl;
				}
				else if (choice == 2 && curEnemy->getSkillCnt() == 0) // 蝶鑒擊 賅舒 餌辨ц擊 唳辦
				{
					cout << "蝶鑒擊 賅舒 餌辨ж艘蝗棲棻." << endl;
				}
				else
					choiceSuccess = true;
				
			}

			switch (choice)
			{
			case 1:
				tb = new AttackBehavior;
				cout << curEnemy->getName() << "曖 跺鱔 夢纂晦!" << endl;
				effective = tb->executeTurn(curEnemy, curAlly);
				if (effective == 2)
				{
					cout << "�膩�朝 渠欽ц棻!" << endl;
				}
				else if (effective == 0)
				{
					cout << "�膩�陛 滌煎檣 蛭 ж棻..." << endl;
				}
				break;
			case 2:
				tb = new SkillBehavior;
				tb->executeTurn(curEnemy, curAlly);
				break;
			case 3:
				tb = new RestBehavior;
				cout << curEnemy->getName() << "擎(朝) 檜廓 欐縑 �瑍饒狤斐�!" << endl;
				cout << "羹溘擊 模榆 �蛹嘎葧�!" << endl;
				tb->executeTurn(curEnemy, curAlly);
				break;
			default:
				break;
			}
			clear();
		}

		if (curAlly->getHealthPoint() <= 0) // 嬴捱 ⑷營 ん鰍跨曖 ぬ寡
		{
			cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
			cout << curAlly->getName() << "擎(朝) 噙楝螺棻!" << endl;
			if (allyList.size() == 1)
			{
				cout << endl << "釭縑啪朝 渦 檜鼻 陴擎 ん鰍跨檜 橈棻!" << endl;
				cout << "換 擅檜 蠕蠕п螺棻..." << endl;
				cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
				cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
				allyList.pop_back();
				break;
			}
			cout << "熱堅ц橫! 給嬴諦, " << curAlly->getName() << "!" << endl;
			for (size_t i = 0; i < allyList.size() - 1; i++) // ん鰍跨擊 и 蘊噶 擅戲煎 渡曹棻
			{
				allyList.at(i) = allyList.at(i + 1);
			}
			cout << "陛塭, " << allyList.at(1)->getName() << "!" << endl;
			cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
			allyList.pop_back();
		}		
		clear();
	}
	if (enemyList.size() == 0)
	{
		cout << "忙式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛忙式式式式式式式式式式式式式式式式忖弛" << endl;
		cout << "弛弛∫           蝓葬!            ∮弛弛" << endl;
		cout << "弛戌式式式式式式式式式式式式式式式式戎弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式戎" << endl;
	}
	else if (allyList.size() == 0)
	{
		clear();
		cout << "忙式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛忙式式式式式式式式式式式式式式式式忖弛" << endl;
		cout << "弛弛∫             ぬ寡...        ∮弛弛" << endl;
		cout << "弛戌式式式式式式式式式式式式式式式式戎弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式戎" << endl;
	}
}

void App::selectTurnBehavior()
{

}

void App::printAllyPokemon()
{
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "          摹鷗脹 嬴捱 ん鰍跨" << endl;
	for(size_t i = 0; i < 3; i++)
	{
		Pokemon* Cur = allyList.at(i);
		cout << Cur->getName() << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "羹溘           : " << Cur->getHealthPoint() << "/" << Cur->getMaximumHealthPoint() << endl;
		cout << "奢問溘         : " << Cur->getAttackPoint() << endl;
		cout << "寞橫溘         : " << Cur->getDefensePoint() << endl;
		cout << "濤罹 蝶鑒 �蝦� : " << Cur->getSkillCnt() << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	}
}

void App::printEnemyPokemon()
{
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "          摹鷗脹 瞳捱 ん鰍跨" << endl;
	for(size_t i = 0; i < 3; i++)
	{
		Pokemon* Cur = enemyList.at(i);
		cout << Cur->getName() << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "羹溘           : " << Cur->getHealthPoint() << "/" << Cur->getMaximumHealthPoint() << endl;
		cout << "奢問溘         : " << Cur->getAttackPoint() << endl;
		cout << "寞橫溘         : " << Cur->getDefensePoint() << endl;
		cout << "濤罹 蝶鑒 �蝦� : " << Cur->getSkillCnt() << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	}
}

void App::printCurPokemon()
{
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "釭曖 ん鰍跨" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << curAlly->getName() << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "羹溘           : " << curAlly->getHealthPoint() << "/" << curAlly->getMaximumHealthPoint() << endl;
	cout << "奢問溘         : " << curAlly->getAttackPoint() << endl;
	cout << "寞橫溘         : " << curAlly->getDefensePoint() << endl;
	cout << "濤罹 蝶鑒 �蝦� : " << curAlly->getSkillCnt() << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;

	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "鼻渠 ん鰍跨" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << curEnemy->getName() << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "羹溘           : " << curEnemy->getHealthPoint() << "/" << curEnemy->getMaximumHealthPoint() << endl;
	cout << "奢問溘         : " << curEnemy->getAttackPoint() << endl;
	cout << "寞橫溘         : " << curEnemy->getDefensePoint() << endl;
	cout << "濤罹 蝶鑒 �蝦� : " << curEnemy->getSkillCnt() << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式" << endl;
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