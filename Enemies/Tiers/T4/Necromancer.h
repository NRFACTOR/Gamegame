//
//  Necromancer.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Necromancer_H
#define Necromancer_H

#include "Enemy.h"

class Necromancer : public Enemy {
public:
    Necromancer(int);
private:
		// Bonuses
	int healthMod = 0;
	int attackMod = 0;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* Necromancer_H */