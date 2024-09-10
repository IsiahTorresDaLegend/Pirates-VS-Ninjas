/*

Pirate.cpp
Derived-class Pirate member-function definitions.
Written by Isiah Torres for course CSC 275

*/
//================================================================================================
// Preprocessor Directives
#include <iostream>
#include <string>
#include "Pirate.h" // Pirate class definition
using namespace std;

//================================================================================================

Pirate::Pirate() // Default constructor
{}

// constructor, takes a string constant reference and a double as parameters.
Pirate::Pirate(const string& newName)
{
	setName(newName); // use the string parameter to set the name attribute. name is public.  
}

// override the Help() function to output information about Pirate objects
void Pirate::Help() const
{
	cout << "\n\nPirates are fearless, savage, and fierce. "
		<< "They can use their swords to slice their foes.\n\n";
}

// override attack() to be specific to pirates
int Pirate::attack()
{
	UseSword(); // display output UseSword() first...
	// then use getName() to retrieve the value of name for the object...
	// then add the name and hitPoints to dialogue and send to output.
	cout << "\n" << getName() << "'s attack caused " << hitPoints
		<< " damage to the enemy!\n";
	return hitPoints; // return the value of hitPoints
}

// override special() as well.
int Pirate::special() 
{
	// display to user that character is performing an action. 
	// use data member specHitPoints.
	cout << "\n\033[1;31m*** " << getName() << " pulls a black ball pistol from the hip ***\n"
		<< "*** then aims the hand-held canon at their foe, then fires ***\n\n\033[0m"
		<< getName() << "'s attack caused " << specHitPoints << " damage to the enemy!\n\n";
	return specHitPoints;
}

// New action for Pirate objects. Lets the user know the object is performing an action.
void Pirate::UseSword() const
{
	// Using ASNI escape codes to manipulate text in console. 
	cout << "\n\n\033[1;31m*** " << getName() << " rushes with vicious sword swings ***\n\033[0m";
}

// get type
string Pirate::getType() const { return type; }

// get attackName
string Pirate::getAttackName() const { return attackName; }

// get specialAttackName
string Pirate::getSpecialAttackName() const { return specialAttackName; }

// get hitPoints
int Pirate::getHitPoints() const { return hitPoints; }

// get specHitPoints
int Pirate::getSpecHitPoints() const { return specHitPoints; }