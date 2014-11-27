//
//  Displays.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 10/25/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//
#include <sstream>
#include "Displays.h"
using namespace std;

Displays::Displays() {
    
}

void Displays::DrawBoxStart() {
    cout << "/";
    Displays::DrawLine();
    cout << "|" << endl;
}
void Displays::DrawDivider() {
    cout << "|";
    Displays::DrawLine();
    cout << "|" << endl;
}
void Displays::DrawEmptyBoxSpace() {
    vector<string> emptySpace = {"  "};
    Displays::EvenlySpacedStrings(emptySpace);
}
void Displays::DrawBoxEnd() {
    cout << "|";
    Displays::DrawLine();
    cout << "/" << endl;
}
void Displays::DrawLine() {
    for (int i = 0; i < menuWidthNotIncludingBorders; i++) {
        cout << "-";
    }
}

void Displays::DrawFullyFormattedNumericalMenu(Player thePlayer, vector<string> header, vector<string> title, vector<string> menuItems) {
    Displays::DrawBoxStart();
    Displays::EvenlySpacedStrings(header);
    Displays::DrawDivider();
    Displays::EvenlySpacedStrings(title);
    Displays::DrawDivider();
    Displays::DrawEmptyBoxSpace();
    Displays::ListMenuItemsNum(thePlayer, menuItems);
	
    for (unsigned long i = menuItems.size(); i <  Displays::maxMenuElements; i++) { Displays::DrawEmptyBoxSpace();}
	
    Displays::DrawBoxEnd();
}

void Displays::DrawFullyFormattedCharMenu(Player thePlayer, vector<string> header, vector<string> title, vector<string> menuItems) {
    Displays::DrawBoxStart();
    Displays::EvenlySpacedStrings(header);
    Displays::DrawDivider();
    Displays::EvenlySpacedStrings(title);
    Displays::DrawDivider();
    Displays::DrawEmptyBoxSpace();
    Displays::ListMenuItemsChar(thePlayer, menuItems);
	
    for (unsigned long i = (menuItems.size() / 2); i <  Displays::maxMenuElements; i++) { Displays::DrawEmptyBoxSpace();}
	
    Displays::DrawBoxEnd();
}

void Displays::EvenlySpacedStrings(vector<string> strVector) {
    int vectorContentLength = 0;
		// for every item in vector, add the length of item "i" to the length count
    for (int i = 0; i < strVector.size(); i++) { vectorContentLength += strVector[i].size();}
    
    int correctSpacing = (menuWidthNotIncludingBorders - vectorContentLength) / (strVector.size() + 1);
    cout << "|";
	
    for (int j = 0; j < (strVector.size()); j++) {
        for (int k = 0; k < (correctSpacing); k++) {cout << " ";}
		if ((strVector[j].size()) % 2 == 1) cout << " ";		// correction for each item in vector with odd number of characters
        cout << strVector[j];
    }
	
    int spacingcorrection = (GetMenuWidth() - correctSpacing);
	
    for (int l = 0; l == spacingcorrection; l++) {
        cout << " ";
    }
    for (int m = 0; m < (correctSpacing); m++) {cout << " ";}
    cout << "|"<<endl;
}

void Displays::ListMenuItemsNum(Player thePlayer, vector<string> menuOptions) {
    for(int i = 0; i < menuOptions.size(); i++) {
        cout << "| ";
        cout << "(" << (i+1) << ") ";
        cout << menuOptions[i];
        ProperSpacing(static_cast<int>(menuOptions[i].size()) + 5);
        cout << "|" << endl;
    }
}

void Displays::ListMenuItemsChar(Player thePlayer, vector<string> menuOptions) {
    for(int i = 0; i < menuOptions.size(); i+=2) {
        cout << "| ";
		if ((i == 2) && ((thePlayer.GetCurrentDay() % 10) != 0)) {
			i+=2;
		}
        cout << "(" << (menuOptions[i+1]) << ") ";
        cout << menuOptions[i];
        Displays::ProperSpacing(static_cast<int>(menuOptions[i].size()) + 5);
        cout << "|" << endl;
    }
}

void Displays::ProperSpacing(int spaceOccupied) {
    int whitespace = (menuWidthNotIncludingBorders - spaceOccupied);
    for (int i = 0; i < whitespace; i++) {
        cout << " ";
    }
}

	// Menu Generation Methods
void Displays::GameMenu(Player thePlayer) {
    string dayStr = "Day: " + Displays::CurrentNumber(thePlayer.GetCurrentDay());
    string healthStr = "Health: " + Displays::CurrentNumber(thePlayer.GetCurrentHealth());
    string goldStr = "Gold: " + Displays::CurrentNumber(thePlayer.GetCurrentGold());
    vector<string> header = {thePlayer.GetName()};
    vector<string> title = {dayStr, healthStr, goldStr};
    
    Displays::DrawFullyFormattedCharMenu(thePlayer, header, title, gameplayMenuOptions);
}

void Displays::ShopMenu(Player thePlayer) {
    string healthStr = "Health: "+ Displays::CurrentNumber(thePlayer.GetCurrentHealth());
    string goldStr = "Gold: "+ Displays::CurrentNumber(thePlayer.GetCurrentGold());
    vector<string> header =  {"Welcome to the shop! (5) = Exit"};
    vector<string> title = {healthStr, goldStr};
    
    Displays::DrawFullyFormattedNumericalMenu(thePlayer, header, title, Displays::potionNames);
}

void Displays::BattleMenu(Player thePlayer, Enemy theEnemy) {
    string playerHealthStr = "Your Health: " + Displays::CurrentNumber(thePlayer.GetCurrentHealth());
    string enemyHealthStr = "Enemy Health: " + Displays::CurrentNumber(theEnemy.GetCurrentHealth());
    string headerWithEnemyName = "Battle: " + theEnemy.GetFullName();
    
	vector<string> header = {headerWithEnemyName};
    vector<string> title = {playerHealthStr, enemyHealthStr};
    
    Displays::DrawFullyFormattedNumericalMenu(thePlayer, header, title, battleMenuOptions);
}

string Displays::CurrentNumber(int numberBeingDisplayed) {
    ostringstream oss;
    oss << numberBeingDisplayed;
    string tempStr;
    if (numberBeingDisplayed < 100 && numberBeingDisplayed > 9) tempStr = " ";
    else if (numberBeingDisplayed < 10) tempStr = "  ";
    tempStr += oss.str();
    return tempStr;
}

vector<string> Displays::GetGameplayMenuOptions() { return Displays::gameplayMenuOptions;}
vector<string> Displays::GetPotionNames() { return Displays::potionNames;}
vector<string> Displays::GetBattleMenuOptions() { return Displays::battleMenuOptions;}
int Displays::GetMenuWidth() { return Displays::menuWidthNotIncludingBorders;}