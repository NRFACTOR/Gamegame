//
//  GameGame.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/25/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "GameGame.h"
#include "stdio.h"

Gamegame::Gamegame() {
cout<<"Welcome to GameGame!"<<endl;
cout<<"Your goal is to survive for "<<dayGoal<<" days."<<endl;
cout<<"Every ten days, you will encounter a shop, where you can spend your gold on useful items and upgrades."<<endl;
cout<<endl;

thePlayer = new Player();

cout<<endl;
GameLoop();
}

	// Game Loops
void Gamegame::GameLoop() {
    char menuChoice;
    theDisplays->GameMenu(*thePlayer);
    do {
        menuIndex = 0;
        if (thePlayer -> GetCurrentHealth() == 0) menuChoice = 'g';
        else if ((thePlayer -> GetCurrentDay()) == dayGoal) {
            EndGame(true);
        }
        else {
			theDisplays -> GameMenu(*thePlayer);
            menuChoice = UserInput::GetChar();
            menuChoice = tolower(menuChoice);
            if (menuChoice == 'g') menuChoice = '0';
        }
        switch (menuChoice) {
            case 'e' :
                Explore();
                thePlayer -> NextDay();
                break;
            case 'v' :
                if ((thePlayer -> GetCurrentDay())%10 == 0) {
                    Shop();
					thePlayer -> NextDay();
                    break;
                }
                else InvalidChoice();
                break;
            case 's' :
                cout<<"Feature not currently working. =( "<<endl;
                break;
            case 'g' :
                if ((thePlayer->GetCurrentHealth()) < 1) {
                    if (EndGame(false)) menuChoice = 0;
                }
                else menuChoice = 0;
                break;
            case 'q' :
                cout << "This will end your game, and you will lose any unsaved data..."<<endl;
                if (UserInput::GetConfirmation())cout<<"Exiting..."<<endl;
                else if (!UserInput::GetConfirmation()){
                    menuChoice = 0;
                    cout<<"Returning to game."<<endl;
                }
                break;
			/*
			 case 'd':
				thePlayer -> ListGameStats();
				break;
            case 'w' :
                if (thePlayer -> GetCurrentDay() == dayGoal) {
                    EndGame(true);
                    ResetGame();
                    
                }
                else menuChoice = 0;
                break;
			 */
            default:
                InvalidChoice();
                break;
        }
    } while (menuChoice != 'q' && menuChoice != 'g');
}

void Gamegame::BattleLoop(){
    int battleChoice;
    int damage;
    bool playerGoesFirst;
    bool endBattle = false;
	bool victory = false;
    
    Enemy theEnemy = theBattles->CreateEnemy();
    
    playerGoesFirst = (thePlayer->GetSpeedStat() > theEnemy.GetSpeedStat());
    
    do {
        if (playerGoesFirst) {
            
            theDisplays -> BattleMenu(*thePlayer, theEnemy);
            
			battleChoice = UserInput::GetInt(1,2);
            
            switch (battleChoice) {
                case 1:
                    damage = ((thePlayer->GetAttackStat()) - (theEnemy.GetDefenseStat()));
                    cout << "You strike the enemy for  " << damage << " damage." << endl;
                    theEnemy.ApplyHealthChange(false, damage);
                    break;
                case 2:
                    endBattle = true;
					victory = false;
                    break;
                    
                default:
                    InvalidChoice();
                    break;
            }
            if (theEnemy.GetCurrentHealth() == 0) {
                endBattle = true;
				victory = true;
            }
            else {
				damage = ((theEnemy.GetAttackStat()) - (thePlayer->GetDefenseStat()));
				if (damage < 0) damage = 0;
				cout << "The enemy strikes you for " << damage << " damage." << endl;
				thePlayer->ApplyHealthChange(false, damage);
			}
        }
		
        else if(!playerGoesFirst) {
            damage = ((theEnemy.GetAttackStat()) - (thePlayer->GetDefenseStat()));
            cout << "The enemy strikes you for " << damage << " damage." << endl;
            thePlayer->ApplyHealthChange(false, damage);
			
            if (thePlayer->GetCurrentHealth() == 0) {
                endBattle = true;
				victory = false;
            }
            
            theDisplays -> BattleMenu(*thePlayer, theEnemy);
            battleChoice = UserInput::GetInt(1,2);
            
            switch (battleChoice) {
                case 1:
                    damage = ((thePlayer->GetAttackStat()) - (theEnemy.GetDefenseStat()));
					if(damage < 0) damage = 0;
                    cout << "You strike the enemy for " << damage << " damage." << endl;
                    theEnemy.ApplyHealthChange(false, damage);
                    break;
                case 2:
                    endBattle = true;
					victory = false;
                    break;
                    
                default:
                    InvalidChoice();
                    break;
            }
            if (theEnemy.GetCurrentHealth() == 0) {
                endBattle = true;
				victory = true;
            }
        }
    } while (endBattle != true);
	
	if (victory) {
		DefeatedEnemy(theEnemy);
	}
}
	// End Game Loops

	// Menu Actions
void Gamegame::Explore() {
    srand(static_cast<unsigned int>(time(0)));
    int exploreResult = (rand() % 10);
    if (exploreResult < 4) BattleLoop();
    else if (exploreResult >= 4 && exploreResult < 7) LuckBasedEvent(true);
    else if (exploreResult >= 7) LuckBasedEvent(false);
}

void Gamegame::Shop() {
    char shopSelection;
    do {
        theDisplays -> ShopMenu(*thePlayer);
        shopSelection = UserInput::GetInt();
        switch (shopSelection) {
            case 1:
                cout<<"You are about to purchase a "<<potionNames[(shopSelection-1)]<<", healing "<<smallHealthChange<<" for "<<smallGoldChange<<" gold."<<endl;
                if (SufficientGold(smallGoldChange)){
                    if (UserInput::GetConfirmation()) {
                        thePlayer->ApplyHealthChange(true, smallHealthChange);
                        thePlayer->ApplyGoldChange(false,smallGoldChange);
                    }
                }
                else cout<<"You do not have enough gold."<<endl;
                break;
            case 2:
                cout<<"You are about to purchase a "<<potionNames[(shopSelection-1)]<<", healing "<<mediumHealthChange<<" for "<<mediumGoldChange<<" gold."<<endl;
                if (SufficientGold(mediumGoldChange)) {
                    if (UserInput::GetConfirmation()) {
                        thePlayer->ApplyHealthChange(true, mediumHealthChange);
                        thePlayer->ApplyGoldChange(false,mediumGoldChange);
                    }
                }
                else cout<<"You do not have enough gold."<<endl;
                break;
            case 3:
                cout<<"You are about to purchase a "<<potionNames[(shopSelection-1)]<<", healing "<<(mediumHealthChange+smallHealthChange)<<" for "<<largeGoldChange<<" gold."<<endl;
                if (SufficientGold(largeGoldChange)) {
                    if (UserInput::GetConfirmation()) {
                        thePlayer->ApplyHealthChange(true, (mediumHealthChange+smallHealthChange));
                        thePlayer->ApplyGoldChange(false,largeGoldChange);
                    }
                }
                else cout << "You do not have enough gold!" << endl;
                break;
            case 4:
                cout << "We are currently sold out of these potions. Sorry for the inconvenience." << endl;
                break;
            case 5:
                cout << "Are you sure you want to leave the shop?";
                if (!UserInput::GetConfirmation()) shopSelection = 0;
                break;
            default:
                InvalidChoice();
                shopSelection = 0;
                break;
        }
    } while (shopSelection != 5);
    
}
	// End Menu Actions ///////////////////////////////////////////////////////////////////////////////////////////////////

void Gamegame::InvalidChoice() {
    cout<<"That is not a valid choice. Try again."<<endl;
}

	// Event Methods
void Gamegame::LuckBasedEvent(bool goodLuck) {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = (rand()%4);
    
    switch (randomNumber) {
        case 0 :
            if (goodLuck) {                         //Good luck 1: small gold increase
                cout<<"You find a coinpurse, containing " << smallGoldChange << " gold!"<<endl;
                thePlayer->ApplyGoldChange(true, smallGoldChange);
            }
            else if (!goodLuck) {                   //Bad luck 1: small health decrease
                cout<<"You fall into a minor trap, taking " << smallHealthChange << " points of damage."<<endl;
                
                thePlayer->ApplyHealthChange(false, smallHealthChange);
            }
            break;
        case 1 :
            if (goodLuck) {                         //Good luck 2: medium gold increase
                cout<<"You find a small chest, containing " << mediumGoldChange << " gold."<<endl;
                
                thePlayer->ApplyGoldChange(true, mediumGoldChange);
            }
            else if (!goodLuck) {                   //Bad luck 2: small gold decrease
                cout<<"Oh no! You are robbed by a theif! Luckily, he didn't find your main stash of gold,"<<endl;
                cout<<"but he did get away with " << smallGoldChange << " gold"<<endl;
                
                thePlayer->ApplyGoldChange(false, smallGoldChange);
            }
            break;
        case 2 :
            if (goodLuck) {                         //Good luck 3: small health increase
                cout<<"You find a small potion, increasing your health by " << smallHealthChange << "!"<<endl;
                
                thePlayer->ApplyHealthChange(true, smallHealthChange);
            }
            else if (!goodLuck) {                   //Bad luck 3: medium health decrease
                cout<<"You fall into a strong trap, taking " << mediumHealthChange << " damage."<<endl;
                
                thePlayer->ApplyHealthChange(false, mediumHealthChange);
            }
            break;
        case 3:
            if (goodLuck) {                         //Good luck 4: medium gold & health increase
                cout<<"You find a benevolent wizard, who heals you for " << mediumHealthChange << ", and turns a pile"<<endl;
                cout<<"of rocks into " << mediumGoldChange << " gold! How fortunate!"<<endl;
                
                thePlayer->ApplyHealthChange(true, mediumHealthChange);
                thePlayer->ApplyGoldChange(true, mediumGoldChange);
            }
            else if (!goodLuck){                    //Bad luck 4: medium gold & health decrease
                cout<<"You are mugged by a mob of goblins, and everyone knows that goblins love shiny things."<<endl;
                cout<<"As well as losing "<< mediumHealthChange << " health in the fight, they manage to get away with " << mediumGoldChange << " gold."<<endl;
                
                thePlayer->ApplyHealthChange(false, mediumHealthChange);
                thePlayer->ApplyGoldChange(false, mediumGoldChange);
            }
            break;
        default:
            cout<<"Error. randomNumber is: "<<randomNumber<<". You should never see this message!!!"<<endl;
            break;
    }
}

bool Gamegame::SufficientGold(int amountBeingSubtracted){
    if ((thePlayer->GetCurrentGold()) >= amountBeingSubtracted) return true;
    else return false;
}
	// End Event Based Methods /////////////////////////////////////////////////////



void Gamegame::DefeatedEnemy(Enemy theEnemy) {
	int earnedGold = theEnemy.GoldOutput(*thePlayer);
	int earnedExp = theEnemy.ExpOutput(*thePlayer);
	
	cout << "You earned " + to_string(earnedGold) + " gold and " + to_string(earnedExp) + " experience from the fight!" << endl;
	thePlayer -> ApplyGoldChange(true, earnedGold);
	thePlayer -> ApplyExpChange(true, earnedExp);
	if (thePlayer -> GetCurrentExperience() >= thePlayer -> GetRequiredExperience()) {
		thePlayer -> ApplyExpChange(false, (thePlayer -> GetRequiredExperience()));
		thePlayer -> LevelUp(*thePlayer);
	}
}

	// File Management Methods
void Gamegame::SaveGame() {
    ofstream saveFile;
	saveFile.open ("example.txt");
	saveFile << "Writing this to a file.\n";
	saveFile.close();
}

void Gamegame::LoadGame() {
    
}

bool Gamegame::EndGame(bool playerVictory) {
    bool confirm;
    if (playerVictory) {
        cout << "Congratulations, adventurer! You are one of the first to ever complete GameGame!" << endl;
    }
    else if (!playerVictory) {
        cout << "You have died!" << endl;
        cout << "Game Over!" << endl;
    }
    cout<<"Thanks for playing!"<<endl;
    cout<<endl;
    cout<<"Would you like to try again?"<<endl;
	confirm = UserInput::GetConfirmation();
	if (confirm) {
		ResetGame();
		return true;
	}
	else if (!confirm) {
		return false;
	}
}

void Gamegame::ResetGame() {
    thePlayer->ResetPlayer();
}
	// End Game Management Methods /////////////////////////////////////////////////////

	// Miscellaneous Methods

	// End Miscellaneous Methods ///////////////////////////////////////////////////////

	// DEBUG Methods

void Gamegame::OutputEnemyStats(Enemy theEnemy) {
    cout << "ID: " << theEnemy.GetID() << endl;
	cout << "Tier: " << theEnemy.GetTier() << endl;
	cout << "Subclass: " << theEnemy.GetSubclass() << endl;
    cout << "Lv: " << theEnemy.GetDifficulty() << endl;
    cout << "Enemy Name: " << theEnemy.GetName() << "." << endl;
    cout << "Health: " << theEnemy.GetAttackStat() << "." << endl;
    cout << "Attack: " << theEnemy.GetAttackStat() << "." << endl;
    cout << "Defense: " << theEnemy.GetDefenseStat() << "." << endl;
    cout << "Speed: " << theEnemy.GetSpeedStat() << "." << endl;
}
