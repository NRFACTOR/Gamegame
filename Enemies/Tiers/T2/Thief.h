//
//  Thief.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Thief_H
#define Thief_H

#include "Enemy.h"

class Thief : public Enemy {
public:
    Thief(int);
private:
		// Bonuses
	int healthMod = -3;
	int attackMod = -4;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* Thief_H */