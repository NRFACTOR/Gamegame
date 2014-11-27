//
//  Chimera.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Chimera_H
#define Chimera_H

#include "Enemy.h"

class Chimera : public Enemy {
public:
    Chimera(int);
private:
		// Bonuses
	int healthMod = 0;
	int attackMod = 0;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* Chimera_H */