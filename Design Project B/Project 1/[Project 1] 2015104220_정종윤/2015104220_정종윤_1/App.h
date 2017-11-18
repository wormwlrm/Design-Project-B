#pragma once
#include <vector>
#include <iomanip>
#include "AttackBehavior.h"
#include "RestBehavior.h"
#include "SkillBehavior.h"
#include "PokemonFactory.h"


class App
{
public:
	App();
	~App();

	void run();

private:
	void selectAllyPokemon(); // �Ʊ� ���ϸ� ����
	void selectEnemyPokemon(); // ���� ���ϸ� ����
	void showPokemonList(); // ��� ���ϸ� ����Ʈ ���
	void startBattle(); // �Ʊ� ���� �� ��Ʋ ����
	void selectTurnBehavior(); // �Ͽ� �� �ൿ ����
	void printAllyPokemon(); // �Ʊ��� ������ ���ϸ� ����Ʈ ���
	void printEnemyPokemon(); // ������ ������ ���ϸ� ����Ʈ ���
	void executeTurn(); // �� ����
	void printCurPokemon(); // ���� ��Ʋ���� ���ϸ� ���

	void clear();

	//get �Լ�
	vector<Pokemon*> getAllyList();
	vector<Pokemon*> getEnemyList();
	Pokemon* getCurAlly();
	Pokemon* getCurEnemy();

private:
	vector<Pokemon*> allyList;
	vector<Pokemon*> enemyList;
	PokemonFactory pf;
	TurnBehavior *tb;
	Pokemon* curAlly;
	Pokemon* curEnemy;
	
//	bool isMyTurn = true;
};

