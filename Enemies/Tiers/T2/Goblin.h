//
//  Goblin.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Goblin_H
#define Goblin_H

#include "Enemy.h"

class Goblin : public Enemy {
public:
    Goblin(int);
private:
		// Bonuses
	int healthMod = -4;
	int attackMod = -2;
	int defenseMod = -6;
	int speedMod = -4;
};
#endif /* Goblin_H */