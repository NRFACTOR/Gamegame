//
//  Player.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 8/30/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Displays.h"
#include "Enemy.h"
#include "UserInput.h"

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Enemy;

class Player {
public:
    Player(void);
	
    //SET methods    
    void SetName();
    void SetRequiredExperience(void);
    void SetBaseHealthStat(void);
    void SetBaseAttackStat(void);
    void SetBaseDefenseStat(void);
    void SetBaseSpeedStat(void);
    
    //Get methods
    string GetName(void);
    int GetMaxHealth(void);
    int GetAttackStat(void);
    int GetDefenseStat(void);
    int GetSpeedStat(void);
    
    int GetCurrentHealth(void);
    int GetCurrentGold(void);
    int GetCurrentExperience(void);
    int GetRequiredExperience(void);
    int GetLevel(void);
    string GetBonusStatName(int);
	
    int GetCurrentDay(void);
    
	//Action methods
    void Attack(Enemy);
    
    void DefeatedEnemy(Player, Enemy);
	void TallyDefeatedEnemy(Enemy);
    
    void LevelUp(Player);
    void SelectBonus();
	
    void ListGameStats(void);
    void UpdateStats(void);
    void ResetPlayer(void);
	
		//Player Progression Methods
	void ApplyHealthChange(bool, int);
    void ApplyGoldChange(bool, int);
	void ApplyExpChange(bool, int);
	
	void NextDay(void);
	
private:
	
    int currentDay;
    // Stats
    const int characterMax = 16;
    string name;
    int level;
    int currentExp;
    int requiredExp;
    
    int currentHealth;
    int baseHealthStat;
    int baseAttackStat;
    int baseDefenseStat;
    int baseSpeedStat;
    
    // Stat Bonuses
    vector<string> bonusStatNames = {"Strength", "Endurance", "Agility"};
	
    int bonusHealth = 0;
    int bonusAttack = 0;
    int bonusDefense = 0;
    int bonusSpeed = 0;
    
    // Gold
    int currentGold = 0;
    
    //Player totals
    int totalGoldSpent = 0;
    int totalGoldAcquired = 0;
    int totalExperienceGained = 0;
    
	string enemyNames [5][3] = {
		{"Giant Rat", "Imp", "Raven"},
		{"Goblin", "Skeleton", "Thief"},
		{"Chimera", "Orc Warrior", "Warg"},
		{"Elemental Sorcerer", "Giant", "Necromancer"},
		{"Dragon", "Phoenix", "Void Demon"}
	};
    int enemiesDefeated [5][3][5] = {
		{	// Format: [Tier][Subclass][Difficulty]
			{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}
		},
	};
    
    // --- Item Lists ---
    vector<string>  inventory;
};

#endif /* defined(PLAYER_H) */
