//
//  Player.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 8/30/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "Player.h"


Player::Player() {
    SetName();
    level = 1;
    
    SetBaseHealthStat();
    SetBaseAttackStat();
    SetBaseDefenseStat();
    SetBaseSpeedStat();
    SetRequiredExperience();
	
    currentGold = 0;
    currentExp = 0;
	
    currentHealth = GetMaxHealth();
    
    bonusHealth = 0;
    bonusAttack = 0;
    bonusDefense = 0;
    bonusSpeed = 0;
    currentDay = 1;
}

//Begin SET method implementation

void Player::SetName() {
    cout << "Please enter a name for your character, up to " << characterMax << " characters in length." << endl;
	name = UserInput::GetString(0, characterMax);
}

void Player::SetBaseHealthStat() {
    baseHealthStat = 100 + (pow(4, ((level / 6) - 1))) + (10 * (level - 1)) + (bonusHealth * 5);
}

void Player::SetBaseAttackStat() {
    baseAttackStat = (15 + (2 ^ ((level / 5) - 1)) + (4 * (level - 1))) + (bonusAttack * 3);
}

void Player::SetBaseDefenseStat() {
    baseDefenseStat = (15 + (2 ^ ((level / 5) - 1)) + (4 * (level - 1))) + (bonusDefense * 3);
}

void Player::SetBaseSpeedStat() {
    baseSpeedStat = (10 + (2 ^ ((level / 5) - 1) + (3 * (level - 1)))) + (bonusSpeed * 2);
}

void Player::SetRequiredExperience() {
    if (level == 1) requiredExp = 100;
	else requiredExp = (100 * (pow(1.2, (level))));
}
//SET methods

//Begin GET method implementation
string Player::GetName(){ return name;}
int Player::GetMaxHealth() { return baseHealthStat;}
int Player::GetAttackStat() {return baseAttackStat;}
int Player::GetDefenseStat() {return baseDefenseStat;}
int Player::GetSpeedStat() {return baseSpeedStat;}

int Player::GetCurrentHealth() { return currentHealth;}
int Player::GetCurrentGold() { return currentGold;}
int Player::GetCurrentExperience() { return currentExp;}
int Player::GetRequiredExperience() { return requiredExp;}

int Player::GetLevel() { return level;}
string Player::GetBonusStatName(int i) { return bonusStatNames[i];}
int Player::GetCurrentDay() { return currentDay; }
//GET methods

//Begin Gameplay Methods

void Player::ApplyHealthChange(bool good, int damage) {
    if (good) {
        for (int i = 0; i < damage; ++i) {
            if (GetCurrentHealth() < GetMaxHealth()) {
                currentHealth++;
            }
        }
    }
    else if (!good) {
        for (int i = 0; i < damage; ++i) {
            if (currentHealth > 0) {
                currentHealth--;
            }
        }
    }
}

void Player::ApplyGoldChange(bool good, int amount) {
    if (good) {
        for (int i = 0; i < amount; ++i) {
            currentGold++;
            totalGoldAcquired++;
        }
    }
    else if(!good) {
        for (int i = 0; i < amount; ++i) {
            if (currentGold > 0) {
                currentGold--;
            }
        }
    }
}

void Player::ApplyExpChange(bool good, int amount) {
	if (good) {
		for (int i = 0; i < amount; ++i) {
			currentExp++;
		}
	}
	else if (!good) {
		for (int i = 0; i < amount; ++i) {
			if (currentExp > 0) {
				currentExp--;
			}
		}
	}
}

void Player::NextDay(){ currentDay++;}

void Player::LevelUp(Player thePlayer) {
	Displays::Displays *theDisplay = new Displays();
	vector<string> header = {" ++ LEVEL UP!! ++"};
	level++;
	vector<string> title = {"Select a bonus"};
	
	theDisplay -> DrawFullyFormattedNumericalMenu(thePlayer, header, title, bonusStatNames);
	SelectBonus();
    UpdateStats();
}

void Player::SelectBonus() {
    int bonus = UserInput::GetInt(1, 3);
	switch (bonus) {
        case 1:     // Strength
            bonusAttack += 2;
            bonusHealth ++;
            break;
        case 2:     // Endurance
            bonusDefense += 2;
            bonusHealth ++;
			break;
        case 3:     // Agility
            bonusSpeed += 3;
			break;
        default:
            cout << "Error! bonus stat selected is: " << bonus << ".\nYou should never see this message!";
            break;
    }
}
                           
void Player::ListGameStats() {
	cout <<  "Enemies Defeated:" << endl;
    for (int i = 0; i < 5; i++) {
		cout << "- Tier " + to_string(i) + ":" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "-- " << enemyNames[i][j] << ":" << endl;
			for (int k = 0; k < 5; k++) {
				cout << "--- Difficulty " + to_string(k) + " (" + to_string(enemiesDefeated[i][j][k]) << ")" << endl;
			}
		}
	}
}

void Player::UpdateStats() {
    SetBaseHealthStat();
    SetBaseAttackStat();
    SetBaseDefenseStat();
    SetBaseSpeedStat();
    currentHealth = GetMaxHealth();
    SetRequiredExperience();
}

void Player::ResetPlayer() {
    Player::level = 1;
    Player::SetBaseHealthStat();
    Player::SetBaseAttackStat();
    Player::SetBaseDefenseStat();
    Player::SetBaseSpeedStat();
    
    Player::currentGold = 0;
    Player::currentExp = 0;
    Player::currentHealth = Player::GetMaxHealth();
	
	Player::currentDay = 0;
}