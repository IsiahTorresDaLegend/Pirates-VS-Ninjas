/*

Character.cpp
Derived-class Character member-function definitions.
Written by Isiah Torres for course CSC 275

*/
//================================================================================================
// Preprocessor Directives
#include <iostream>	// needed to use input and output operations. 
#include <string>	// needed to use string objects.
#include "Character.h"	// Character class definition.
using namespace std;	// makes std visible so we do not need to use std::

//================================================================================================

// initialize static member 
const double Character::MAX_HEALTH = 100.0;

// constructor
Character::Character(){} // this is redundant, compiler would generate a default constructor
						 // for us.

// Help() must be overridden to make Character a concrete class...
void Character::Help() const
{
// however, only objects derived from this class will be used, so this help does not need anything
}

// standard character attacks will do 10 hitPoints to health. 
int Character::attack()
{
	int hitPoints = 10; // assigns the default hitPoints for characters
	cout << "\n\nYou attack the opponent causing " 
		<< hitPoints << " damage to their health!\n\n"; // let user know they are attacking
	return hitPoints; // return the amount of damage done. 
}

// Each character's special may vary, some may cause damage, some may heal, etc.
// let derived class override this function to determine what special() does.
int Character::special()
{
	return 0;
}

// Overloaded Talk methods
// takes a string as a parameter then display that string.
void Character::Talk(const string stuffToSay) const	
{
	cout << "\n\n\033[1;33m" << getName() << ": " // use getName to add Character's name dialog.
		<< stuffToSay << "\n\n\033[0m"; 
}

// second version of Talk
// takes two strings, a name, and stuffToSay.
void Character::Talk(const string name, const string stuffToSay) const 
{
	// prepends "name" to stuffToSay and displays it to user.
	cout << "\n\n" << name << ": " << stuffToSay << "\n\n";   
}

// Third version of Talk()
void Character::Talk() const
{
	bool success = false;
	do
	{
		try // try the following code...
		{
			string dialogue; // used to hold user input
			cout << "\nWhat do you want to say?\n"; // ask user
			getline(cin, dialogue); // get user input and store in dialogue
			if (dialogue.empty()) // if user enters nothing...
			{
				// throw this exception...
				throw "\n\033[1;35mException: Must enter something to say!\n\033[0m";
			}
			// else, display their message.
			cout << "\n\033[1;33m" << getName() << ": " << dialogue << "\n\033[0m";
			success = true;
		}
		// the thrown exception in the try block is a constant char pointer (essentially an array of
		// char elements) so the catch exception handler must be a const char* type.
		catch (const char* e) // catch the exception (e) if thrown. 
		{
			cout << e << endl; // display the exception to user. 
		}
	} while (success == false);
}

// set name, assigns parameter to the member variable name
void Character::setName(const string& newName) { name = newName; }

// return name
string Character::getName() const { return name; }

// set type
void Character::setType(const string& newType) { type = newType; }

// get type
string Character::getType() const { return type; }

// set attackName
void Character::setAttackName(const string& newAttackName) { attackName = newAttackName; }

// get attackName
string Character::getAttackName() const { return attackName; }

// set specialAttackName
void Character::setSpecialAttackName(const string& newSpecial) { specialAttackName = newSpecial; }

// get specialAttackName
string Character::getSpecialAttackName() const {return specialAttackName; }

// set blocking
void Character::block(bool stance) { blocking = stance; }

// get blocking
bool Character::isBlocking() const { return blocking; }

// set hitPoints
void Character::setHitPoints(const int& points) { hitPoints = points; }

// get hitPoints
int Character::getHitPoints() const { return hitPoints; }

// set specHitPoints
void Character::setSpecHitPoints(const int& points) { specHitPoints = points; }

// get specHitPoints
int Character::getSpecHitPoints() const { return specHitPoints; }

// set health 
void Character::setHealth(double newHealth)
{
	if (newHealth <= 0) // if newHealth will be less than or equal to 0...
	{
		health = 0;	// set health to 0 and tell user character has expired.
		cout << "\n\033[1;31m" << Character::getName() << " has perished...\n\033[0m";
	}
	else if (newHealth > MAX_HEALTH) // if newHealth is above the health limit...
	{
		health = MAX_HEALTH; // just set health to the max
	}
	else // for every other case, set health to newHealth.
	{
		health = newHealth;
	}
}

// return health 
double Character::getHealth() const { return health; }




