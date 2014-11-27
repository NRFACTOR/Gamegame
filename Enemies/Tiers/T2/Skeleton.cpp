//
//  Skeleton.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "Skeleton.h"
#include "Enemy.h"

using namespace std;

Skeleton::Skeleton(int difficulty) {
    Enemy::SetID();
    Enemy::SetDifficulty(difficulty);
	Enemy::SetTier(2);
	Enemy::SetSubclass(2);
	
    Enemy::SetName();
    
	Enemy::SetBaseHealthStat(healthMod);
    Enemy::SetBaseAttackStat(attackMod);
    Enemy::SetBaseDefenseStat(defenseMod);
    Enemy::SetBaseSpeedStat(speedMod);
    
	Enemy::currentHealth = Enemy::GetBaseHealth();
}