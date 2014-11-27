//
//  Dragon.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "Dragon.h"
#include "Enemy.h"

using namespace std;

Dragon::Dragon(int difficulty) {
    Enemy::SetID();
    Enemy::SetDifficulty(difficulty);
	Enemy::SetTier(5);
	Enemy::SetSubclass(1);
	
    Enemy::SetName();
    
	Enemy::SetBaseHealthStat(healthMod);
    Enemy::SetBaseAttackStat(attackMod);
    Enemy::SetBaseDefenseStat(defenseMod);
    Enemy::SetBaseSpeedStat(speedMod);
    
	Enemy::currentHealth = Enemy::GetBaseHealth();
}