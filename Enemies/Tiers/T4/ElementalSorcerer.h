//
//  ElementalSorcerer.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/17/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef ElementalSorcerer_H
#define ElementalSorcerer_H

#include "Enemy.h"

class ElementalSorcerer : public Enemy {
public:
    ElementalSorcerer(int);
private:
		// Bonuses
	int healthMod = 0;
	int attackMod = 0;
	int defenseMod = 0;
	int speedMod = 0;
};
#endif /* ElementalSorcerer_H */