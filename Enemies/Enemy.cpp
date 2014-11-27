//
//  Enemy.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 8/18/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "Enemy.h"
#include <iostream>

using namespace std;
// Begin Enemy Method Implementation

void Enemy::ApplyHealthChange(bool good, int damage) {
    if (good) {
        for (int i = 0; i < damage; ++i) {
            if (GetCurrentHealth() < GetBaseHealth()) currentHealth++;
        }
    }
    else if (!good) {
        for (int i = 0; i < damage; ++i) {
            if (currentHealth > 0) currentHealth--;
        }
    }
}

void Enemy::Attack(Player thePlayer) {
    int damage = (baseDefenseStat - thePlayer.GetDefenseStat());
    thePlayer.ApplyHealthChange(false, damage);
}

int Enemy::GoldOutput(Player thePlayer) {
	return (((tier * 25) + ((GetDifficulty() * 6) - thePlayer.GetLevel()) - ((thePlayer.GetLevel()/8) * 20)) / 2);
	
}

int Enemy::ExpOutput(Player thePlayer) {
	return ((GetDifficulty() * GetTier() * 1.4) / thePlayer.GetLevel()) * (thePlayer.GetRequiredExperience() / 10);
}

	// Begin SET Method Implementation
void Enemy::SetTier(int _tier) { tier = _tier;}
void Enemy::SetID() { enemyID = tier + subclass;}

void Enemy::SetSubclass(int _subclass) { subclass = _subclass;}

void Enemy::SetDifficulty(int _difficulty ) { difficulty  = _difficulty;}

void Enemy::SetName() { name = enemyNames[(GetTier() - 1)][(GetSubclass() - 1)];}

void Enemy::SetBaseHealthStat(int hpBonus) {
    baseHealthStat = 10 + (tier * 11) + ((difficulty-1) * 11) + (hpBonus * difficulty);
}

void Enemy::SetBaseAttackStat(int atkBonus) {
    baseAttackStat = 6 + (tier * 4) + (difficulty * 2) + atkBonus;
}

void Enemy::SetBaseDefenseStat(int defBonus) {
    baseDefenseStat = 8 + (tier * 4) + (difficulty * 4) + defBonus;
}

void Enemy::SetBaseSpeedStat(int spdBonus) {
    baseSpeedStat = (difficulty  * 4) + (10 - tier) + spdBonus;
}
	// End SET Methods

// Begin GET method implementation
int Enemy::GetTier() { return tier;}
int Enemy::GetSubclass() { return subclass;}
int Enemy::GetID(){ return enemyID;}
int Enemy::GetDifficulty (){ return difficulty ;}

string Enemy::GetName(){ return name;}
string Enemy::GetFullName(){
	string fName = difficultyList[difficulty];
	fName.append(" ");
	fName.append(name);
	return fName;
}

int Enemy::GetCurrentHealth() { return currentHealth;}
int Enemy::GetBaseHealth() { return baseHealthStat;}
int Enemy::GetAttackStat() { return baseAttackStat;}
int Enemy::GetDefenseStat() { return baseDefenseStat;}
int Enemy::GetSpeedStat() { return baseSpeedStat;}
// GET methods //////////////////////////////////////////////////////////////////////////////