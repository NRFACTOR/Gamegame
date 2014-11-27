//
//  GiantRat.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef GIANTRAT_H
#define GIANTRAT_H

#include "Enemy.h"

class GiantRat : public Enemy {
public:
    GiantRat(int);
private:
		// Bonuses
	int healthMod = -10;
	int attackMod = -6;
	int defenseMod = -8;
	int speedMod = -8;
};
#endif /* GiantRat_H */