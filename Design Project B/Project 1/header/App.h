#pragma once
#include <vector>

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
	void selectAllyPokemon();
	void selectEnemyPokemon();
	void showPokemonList();
	void startBattle();
	void selectTurnBehavior();
	void printAllPokemon();
	void executeTrun();

private:
	vector<Pokemon*> allyList;
	vector<Pokemon*> enemyList;
	PokemonFactory pf;
	TurnBehavior *tb;
	Pokemon* curAlly;
	Pokemon* curEnemy;
	
	//bool isMyTurn = true;
};

