/*

Ninja.cpp
Derived-class Ninja member-function definitions.
Written by Isiah Torres for course CSC 275

*/
//================================================================================================
// Preprocessor Directives
#include <iostream>
#include <string>
#include "Ninja.h"
using namespace std;

//================================================================================================



// constructor 

Ninja::Ninja() // Default constructor
{}

// takes a string to set the name attribute and a double to set the health attribute.
// TODO: update constructors.
Ninja::Ninja(const string& newName)
{
	setName(newName);	// public member can be interacted with directly.
}

// override Help()
void Ninja::Help() const
{
	// print information about ninjas to the screen.
	cout << "\n\nNinjas are quick, silent, and deadly. "
		<< "They can throw ninja stars at their enemies from a distance!\n"
		<< "Special: Disappear and throw a kunai from behind to sneak up for close\n"
		<< "combat.\n\n";
}

// override attack method with a custom one for Ninjas
int Ninja::attack()
{
	ThrowStars();	// display attack dialogue
	// display character's name and the amount of damage done to screen.
	cout << "\n" << getName() << "'s attack caused " << hitPoints 
		<< " damage to the enemy!\n";
	return hitPoints; // return the value of hitPoints
}

// override special method with a custom one for Ninjas
int Ninja::special()
{
	// use specHitPoints data member, let user know what is going on.
	// using ANSI escape codes to manipulate text within terminal. 
	cout << "\n\033[1;31m*** " << getName() << " disappears ***\n"
		<< "*** a Kunai is thrown from behind ***\n"
		<< "*** " << getName() << " reappears from behind again for close combat! ***"
		<< "\n\n\033[0m" << getName() << "'s attack caused " << specHitPoints
		<< " damage to the enemy!\n\n";
	return specHitPoints;
}

// this is the Ninja's method of attacking
void Ninja::ThrowStars() const
{
	// display that the ninja is performing an action
	cout << "\n\n\033[1;31m*** Shuriken fly from " << Ninja::getName()
		<< "'s hands ***\n\033[0m"; 
}

// get type
string Ninja::getType() const { return type; }

// get attackName
string Ninja::getAttackName() const { return attackName; }

// get specialAttackName
string Ninja::getSpecialAttackName() const { return specialAttackName; }

// get hitPoints
int Ninja::getHitPoints() const { return hitPoints; }

// get specHitPoints
int Ninja::getSpecHitPoints() const { return specHitPoints; }