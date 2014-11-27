//
//  Battle.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/25/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "Battle.h"
// Enemy Instantiation Methods
Enemy Battle::CreateEnemy() {
    srand(static_cast<unsigned int>(time(0)));
    
    int randomEnemyTier = (rand() % 100);
    int randomEnemySubClass = (rand() % 3);
    
    int enemySet = ((thePlayer.GetLevel() - 1) / 5);
    
    switch (enemySet) {
        case 0:									// Levels 1-4
            if (randomEnemyTier < 75) {         // Generate Tier 1 enemy
                if (randomEnemySubClass == 0) return *new GiantRat(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Imp(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Raven(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 2 enemy
                if (randomEnemySubClass == 0) return *new Goblin(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Skeleton(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Thief(GenerateEnemyLevel());
            }
            break;
        case 1:									// Levels 5-9
            if (randomEnemyTier < 50) {         // Generate Tier 1 enemy
                if (randomEnemySubClass == 0) return *new GiantRat(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Imp(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Raven(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 2 enemy
                if (randomEnemySubClass == 0) return *new Goblin(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Skeleton(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Thief(GenerateEnemyLevel());
            }
            break;
        case 2:									// Levels 10-14
            if (randomEnemyTier < 30) {         // Generate Tier 1 enemy
                if (randomEnemySubClass == 0) return *new GiantRat(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Imp(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Raven(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 80) {    // Generate Tier 2 enemy
                if (randomEnemySubClass == 0) return *new Goblin(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Skeleton(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Thief(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 3 enemy
                if (randomEnemySubClass == 0) return *new Chimera(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new OrcWarrior(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Warg(GenerateEnemyLevel());
            }
            break;
        case 3:									// Levels 15-19
            if (randomEnemyTier < 20) {         // Generate Tier 1 enemy
                if (randomEnemySubClass == 0) return *new GiantRat(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Imp(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Raven(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 60) {    // Generate Tier 2 enemy
                if (randomEnemySubClass == 0) return *new Goblin(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Skeleton(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Thief(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 3 enemy
                if (randomEnemySubClass == 0) return *new Chimera(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new OrcWarrior(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Warg(GenerateEnemyLevel());
            }
            break;
        case 4:									// Levels 20-24
            if (randomEnemyTier < 30) {         // Generate Tier 2 enemy
                if (randomEnemySubClass == 0) return *new Goblin(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Skeleton(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Thief(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 80) {    // Generate Tier 3 enemy
                if (randomEnemySubClass == 0) return *new Chimera(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new OrcWarrior(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Warg(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 4 enemy
                if (randomEnemySubClass == 0) return *new ElementalSorcerer(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Giant(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Necromancer(GenerateEnemyLevel());
            }
            break;
        case 5:									// Levels 25-29
            if (randomEnemyTier < 20) {         // Generate Tier 2 enemy
                if (randomEnemySubClass == 0) return *new Goblin(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Skeleton(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Thief(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 60) {    // Generate Tier 3 enemy
                if (randomEnemySubClass == 0) return *new Chimera(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new OrcWarrior(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Warg(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 4 enemy
                if (randomEnemySubClass == 0) return *new ElementalSorcerer(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Giant(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Necromancer(GenerateEnemyLevel());
            }
            break;
        case 6:									// Levels 30-35
            if (randomEnemyTier < 30) {         // Generate Tier 3 enemy
                if (randomEnemySubClass == 0) return *new Chimera(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new OrcWarrior(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Warg(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 80) {    // Generate Tier 4 enemy
                if (randomEnemySubClass == 0) return *new ElementalSorcerer(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Giant(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Necromancer(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 5 enemy
                if (randomEnemySubClass == 0) return *new Dragon(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Phoenix(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new VoidDemon(GenerateEnemyLevel());
            }
            break;
        case 7:                                 // Level 35!
            if (randomEnemyTier < 30) {         // Generate Tier 3 enemy
                if (randomEnemySubClass == 0) return *new Chimera(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new OrcWarrior(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Warg(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 80) {    // Generate Tier 4 enemy
                if (randomEnemySubClass == 0) return *new ElementalSorcerer(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Giant(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new Necromancer(GenerateEnemyLevel());
            }
            else if (randomEnemyTier < 100) {   // Generate Tier 5 enemy
                if (randomEnemySubClass == 0) return *new Dragon(GenerateEnemyLevel());
                else if (randomEnemySubClass == 1) return *new Phoenix(GenerateEnemyLevel());
                else if (randomEnemySubClass == 2) return *new VoidDemon(GenerateEnemyLevel());
                break;
            default:
                cout << "Error: enemySetNumber is " << enemySet << ". You should never see this message!" << endl;
                break;
                
            }
    }
}

int Battle::GenerateEnemyLevel(void) {                    // For guide to enemy level occurrences, see: GameGame Comprehensive Statistics Guide
    srand(static_cast<unsigned int>(time(0)));
    
    int levelModifier = ((thePlayer.GetLevel() -1) % 5);
    int randomPercentage = (rand() % 100);
    
    int enemyLevel = 0;
    
    switch (levelModifier) {
        case 0:
            if (randomPercentage < 25) enemyLevel = 0;
            else if (randomPercentage < 75) enemyLevel = 1;
            else if (randomPercentage < 90) enemyLevel = 2;
            else if (randomPercentage < 100) enemyLevel = 3;
            break;
        case 1:
            if (randomPercentage < 20) enemyLevel = 0;
            else if (randomPercentage < 50) enemyLevel = 1;
            else if (randomPercentage < 75) enemyLevel = 2;
            else if (randomPercentage < 90) enemyLevel = 3;
            else if (randomPercentage < 100) enemyLevel = 4;
            break;
        case 2:
            if (randomPercentage < 10) enemyLevel = 0;
            else if (randomPercentage < 30) enemyLevel = 1;
            else if (randomPercentage < 60) enemyLevel = 2;
            else if (randomPercentage < 85) enemyLevel = 3;
            else if (randomPercentage < 100) enemyLevel = 4;
            break;
        case 3:
            if (randomPercentage < 10) enemyLevel = 1;
            else if (randomPercentage < 35) enemyLevel = 2;
            else if (randomPercentage < 80) enemyLevel = 3;
            else if (randomPercentage < 100) enemyLevel = 4;
            break;
        case 4:
            if (randomPercentage < 10) enemyLevel = 1;
            else if (randomPercentage < 30) enemyLevel = 2;
            else if (randomPercentage < 70) enemyLevel = 3;
            else if (randomPercentage < 100) enemyLevel = 4;
            break;
        default:
            cout << "Error: levelModifier is " << levelModifier << ". You should never see this message!" << endl;
            break;
    }
    return enemyLevel;
}
// End Enemy Instantiation Methods