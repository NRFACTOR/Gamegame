//
//  Enemy.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 8/18/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"
#include <string>

using namespace std;

class Player;
class Enemy {
public:
		// Gameplay methods
    void Attack(Player);
    void ApplyHealthChange(bool, int);
    int GoldOutput(Player);
	int ExpOutput(Player);
	
		// SET methods
	void SetTier(int);
	void SetSubclass(int);
    void SetID(void);
    void SetDifficulty(int);
    
    void SetName(void);
    void SetBaseHealthStat(int);
    void SetBaseAttackStat(int);
    void SetBaseDefenseStat(int);
    void SetBaseSpeedStat(int);
    
		//GET methods
    int GetID(void);
    int GetDifficulty(void);
    int GetTier(void);
	int GetSubclass(void);
    string GetName(void);
	string GetFullName(void);
		// Stats
    int GetCurrentHealth(void);
	
    int GetBaseHealth(void);
    int GetAttackStat(void);
    int GetDefenseStat(void);
    int GetSpeedStat(void);
		//GET methods for Bonuses
	int GetHealthBonus(void);
	int GetAttackBonus(void);
	int GetDefenseBonus(void);
	int GetSpeedBonus(void);
	
	// Enemy Instantiation Methods
	Enemy Create(void);
	int GenerateDifficulty(void);
	
	string enemyNames[5][3] = {
		{"Giant Rat", "Imp", "Raven"},
		{"Goblin", "Skeleton", "Thief"},
		{"Chimera", "Orc Warrior", "Warg"},
		{"Sorcerer", "Giant", "Necromancer"},
		{"Dragon", "Phoenix", "Void Demon"}
	};
    string difficultyList[5] = {"Scrawny", "Hardened", "Deadly", "Epic", "Legendary"};
protected:
    int tier;
	int subclass;
	int enemyID = ((tier - 1) * 3) + subclass;
    int difficulty;
    
	string name;
    
	int currentHealth;
	
    int baseHealthStat;
    int baseAttackStat;
    int baseDefenseStat;
    int baseSpeedStat;
};

#endif /* Enemy_H */