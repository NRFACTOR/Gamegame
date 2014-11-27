//
//  Necromancer.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "Necromancer.h"
#include "Enemy.h"

using namespace std;

Necromancer::Necromancer(int difficulty) {
    Enemy::SetID();
    Enemy::SetDifficulty(difficulty);
	Enemy::SetTier(4);
	Enemy::SetSubclass(3);
	
    Enemy::SetName();
    
	Enemy::SetBaseHealthStat(healthMod);
    Enemy::SetBaseAttackStat(attackMod);
    Enemy::SetBaseDefenseStat(defenseMod);
    Enemy::SetBaseSpeedStat(speedMod);
    
	Enemy::currentHealth = Enemy::GetBaseHealth();
}