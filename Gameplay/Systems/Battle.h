//
//  Battle.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/25/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include <iostream>
#include "Player.h"

// Enemies ----------------------
#include "Enemy.h"

// Tier 1
#include "GiantRat.h"
#include "Imp.h"
#include "Raven.h"
// Tier 2
#include "Goblin.h"
#include "Skeleton.h"
#include "Thief.h"
// Tier 3
#include "Chimera.h"
#include "OrcWarrior.h"
#include "Warg.h"
// Tier 4
#include "ElementalSorcerer.h"
#include "Giant.h"
#include "Necromancer.h"
// Tier 5
#include "Dragon.h"
#include "Phoenix.h"
#include "VoidDemon.h"

// End Enemies --------------------
class Battle{
public:
	Enemy CreateEnemy();
	void GetBattleInput(void);
private:
	Player thePlayer;
	int GenerateEnemyLevel();
};