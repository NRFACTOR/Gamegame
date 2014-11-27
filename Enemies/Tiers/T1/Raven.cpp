//
//  Raven.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "Raven.h"
#include "Enemy.h"

using namespace std;

Raven::Raven(int difficulty) {
    Enemy::SetID();
    Enemy::SetDifficulty(difficulty);
	Enemy::SetTier(1);
	Enemy::SetSubclass(3);
	
    Enemy::SetName();
	
	Enemy::SetBaseHealthStat(healthMod);
    Enemy::SetBaseAttackStat(attackMod);
    Enemy::SetBaseDefenseStat(defenseMod);
    Enemy::SetBaseSpeedStat(speedMod);
    
	Enemy::currentHealth = Enemy::GetBaseHealth();
}