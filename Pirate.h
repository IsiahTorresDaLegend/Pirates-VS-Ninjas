/*

Pirate.h
Class definition for Pirate, derived from Character
Written by Isiah Torres for course CSC 275

*/
//================================================================================================
// Include Guard
#ifndef PIRATE_H // if this file is not defined or included...
#define PIRATE_H // define this file so the compiler can include it. 

//================================================================================================
// Preprocessor Directives
#include <string>	// allows use of string objects
#include "Character.h" // Character class definition 
using namespace std; // saves typing by not needing to use std:: 

//================================================================================================
// Class definition

// create a class called Pirate with public inheritance from the Character class
class Pirate : public Character
{
public:	// add the public members

	// default constructor
	Pirate();

	// constructor takes a constant string reference
	Pirate(const string&);

	// generate a virtual destructor for this class. 
	virtual ~Pirate() = default;

	// override Help() to display something new for this class. 
	virtual void Help() const override;

	// override attack() to make attack specific to this class.
	virtual int attack() override; 

	// override special function for this class. 
	virtual int special() override; 

	// add new attribute unique for this class. 
	void UseSword() const;

	// override these get methods to return custom values
	virtual string getType() const override;

	virtual string getAttackName() const override;

	virtual string getSpecialAttackName() const override;

	virtual int getHitPoints() const override;

	virtual int getSpecHitPoints() const override;

private:
	string type = "Pirate"; // type of character
	string attackName = "Sword Dance"; // name of standard attack
	string specialAttackName = "Black Ball Pistol"; // name of special attack
	int hitPoints = 20; // damage power.
	int specHitPoints = 35; // special power
};

#endif // end of include guard for PIRATE_H
