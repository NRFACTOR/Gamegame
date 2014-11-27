//
//  OrcWarrior.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef OrcWarrior_H
#define OrcWarrior_H

#include "Enemy.h"

class OrcWarrior : public Enemy {
public:
    OrcWarrior(int);
private:
		// Bonuses
	int healthMod = 0;
	int attackMod = 0;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* OrcWarrior_H */