//
//  Displays.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/25/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef __Gamegame__Displays__
#define __Gamegame__Displays__
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;
class Enemy;
class Player;

class Displays {
public:
    Displays();
    // Menu Drawing Methods
    void DrawBoxStart(void);
    void DrawDivider(void);
    void DrawEmptyBoxSpace(void);
    void DrawBoxEnd(void);
    void DrawLine(void);
	
    void DrawFullyFormattedNumericalMenu(Player, vector<string>, vector<string>, vector<string>);
    void DrawFullyFormattedCharMenu(Player, vector<string>, vector<string>, vector<string>);
    
	void EvenlySpacedStrings(vector<string>);
    void ListMenuItemsNum(Player, vector<string>);
    void ListMenuItemsChar(Player, vector<string>);
    void ProperSpacing(int);
    string CurrentNumber(int);
    // End Menu Drawing Methods
    
    // Menus
    void GameMenu(Player);
	void ShopMenu(Player);
    void BattleMenu(Player, Enemy);
    
    // End Menus
	
		// Message Box
	void MessageBox(string);
	string EnemyHitPlayerMsg(int);
	string PlayerHitEnemyMsg(int);
    
    // Get Methods
    vector<string> GetGameplayMenuOptions(void);
    vector<string> GetPotionNames(void);
    vector<string> GetBattleMenuOptions(void);
    int GetMenuWidth(void);
    int GetMaxMenuElements(void);
    // End Get Methods
private:
    // Menu Variables
    int menuWidthNotIncludingBorders = 62;
    int maxMenuElements = 7;
    // Menu Option Vectors
    vector<string> gameplayMenuOptions = {"Explore", "E", "Visit the Shop", "V", "Save", "S", "Quit", "Q"};
    vector<string> potionNames = {"Minor Potion ", "Average Potion", "Strong Potion", "Ultimate Potion"};
    vector<string> battleMenuOptions = {"Attack","Run"};
};
#endif /* defined(__Gamegame__Displays__) */