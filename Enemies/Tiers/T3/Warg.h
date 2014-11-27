//
//  Warg.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Warg_H
#define Warg_H

#include "Enemy.h"

class Warg : public Enemy {
public:
    Warg(int);
private:
		// Bonuses
	int healthMod = 0;
	int attackMod = 0;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* Warg_H */