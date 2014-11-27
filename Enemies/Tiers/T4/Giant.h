//
//  Giant.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef GIANT_H
#define GIANT_H

#include "Enemy.h"

class Giant : public Enemy {
public:
    Giant(int);
private:
		// Bonuses
	int healthMod = 0;
	int attackMod = 0;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* Giant_H */