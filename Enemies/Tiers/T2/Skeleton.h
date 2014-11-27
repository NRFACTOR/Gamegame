//
//  Skeleton.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Skeleton_H
#define Skeleton_H

#include "Enemy.h"

class Skeleton : public Enemy {
public:
    Skeleton(int);
private:
		// Bonuses
	int healthMod = -7;
	int attackMod = -5;
	int defenseMod = -6;
	int speedMod = -7;
};
#endif /* Skeleton_H */