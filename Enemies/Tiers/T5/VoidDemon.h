//
//  VoidDemon.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef VoidDemon_H
#define VoidDemon_H

#include "Enemy.h"

class VoidDemon : public Enemy {
public:
    VoidDemon(int);
private:
		// Bonuses
	int healthMod = 0;
	int attackMod = 0;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* VoidDemon_H */