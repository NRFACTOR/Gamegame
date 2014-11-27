//
//  Raven.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Raven_H
#define Raven_H

#include "Enemy.h"

class Raven : public Enemy {
public:
    Raven(int);
private:
		// Bonuses
	int healthMod = -7;
	int attackMod = -4;
	int defenseMod = -6;
	int speedMod = -2;
};
#endif /* Raven_H */