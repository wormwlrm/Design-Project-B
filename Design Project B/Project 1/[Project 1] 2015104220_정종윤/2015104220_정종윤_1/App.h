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
	void selectAllyPokemon(); // 아군 포켓몬 선택
	void selectEnemyPokemon(); // 적군 포켓몬 선택
	void showPokemonList(); // 모든 포켓몬 리스트 출력
	void startBattle(); // 아군 적군 간 배틀 시작
	void selectTurnBehavior(); // 턴에 할 행동 선택
	void printAllyPokemon(); // 아군이 선택한 포켓몬 리스트 출력
	void printEnemyPokemon(); // 적군이 선택한 포켓몬 리스트 출력
	void executeTurn(); // 턴 수행
	void printCurPokemon(); // 현재 배틀중인 포켓몬 출력

	void clear();

	//get 함수
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

