//
//  GameGame.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/27/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Gamegame_GameGame_h
#define Gamegame_GameGame_h

#include <sstream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

	// Player
#include "Player.h"
	// End Player

	// Displays
#include "Displays.h"
	// End Displays

	// User Input
#include "UserInput.h"
	// End User Input
#include "Battle.h"

class Player;
class Enemy;
using namespace std;

class Gamegame {
	
public:
	Gamegame();
	// Game Loops
	void StartMenu();
	void GameLoop();
	
	// Menu Action methods
	void Explore();
	void Shop();
	void BattleLoop();

	// Event methods
	void LuckBasedEvent(bool);
	bool SufficientGold(int);
	void InvalidChoice();

	void DefeatedEnemy(Enemy);
	// Enemy Instantiation Methods
	Enemy CreateEnemy(void);
	int GenerateEnemyLevel(void);

	// Battle Action methods
	int Attack(void);

	// Game Data Management Methods
	void SaveGame(void);
	void LoadGame(void);
	bool EndGame(bool);
	void ResetGame(void);

	// Misc. Methods
	bool intComp(int, int);

	//DEBUG Methods
	void OutputEnemyStats(Enemy);
	// End Methods //////////////////////////////////
	
private:
	Player *thePlayer;
	Displays *theDisplays = new Displays();
	Battle *theBattles = new Battle();
	
	// Variables ////////////////////////////////////
	// --- Gold Incrementation & Decrementation ---
	const int smallGoldChange = 15;
	const int mediumGoldChange = 30;
	const int largeGoldChange = 50;
	const int hugeGoldChange = 100;

	// --- Health Incrementation & Decrementation ---
	const int smallHealthChange = 10;
	const int mediumHealthChange = 25;
	const int largeHealthChange = 50;
	const int hugeHealthChange = 120;

	// Menu Items and related variables
	const vector<string> gameplayMenuOptions = {"Explore", "E", "Visit the Shop", "V", "Save", "S", "Quit", "Q"};
	const vector<string> potionNames = {"Minor Potion", "Average Potion", "Strong Potion", "Ultimate Potion"};
	const vector<string> battleMenuOptions = {"Attack","Run"};
	const int maxMenuElements = 7;

	// Goal-related variables
	int dayGoal = 150;

	// Miscellaneous Variables
	int menuWidthNotIncludingBorders = 62;
	int menuIndex = 0;

	// End Variables ////////////////////////////////
};
#endif