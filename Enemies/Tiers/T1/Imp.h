//
//  Imp.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef Imp_H
#define Imp_H

#include "Enemy.h"

class Imp : public Enemy {
public:
    Imp(int);
private:
		// Bonuses
	int healthMod = -8;
	int attackMod = -5;
	int defenseMod = -6;
	int speedMod = -4;
};
#endif /* Imp_H */