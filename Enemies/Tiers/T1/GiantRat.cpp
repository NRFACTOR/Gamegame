//
//  GiantRat.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "GiantRat.h"
#include "Enemy.h"

using namespace std;

GiantRat::GiantRat(int difficulty) {
    Enemy::SetID();
    Enemy::SetDifficulty(difficulty);
	Enemy::SetTier(1);
	Enemy::SetSubclass(1);
	
    Enemy::SetName();
	
	Enemy::SetBaseHealthStat(healthMod);
    Enemy::SetBaseAttackStat(attackMod);
    Enemy::SetBaseDefenseStat(defenseMod);
    Enemy::SetBaseSpeedStat(speedMod);
    
	Enemy::currentHealth = Enemy::GetBaseHealth();
}