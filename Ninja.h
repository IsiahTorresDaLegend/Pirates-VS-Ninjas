/*

Ninja.h
Class definition for Ninja, derived from Character
Written by Isiah Torres for course CSC 275

*/
//================================================================================================
// Include Guard 
#ifndef NINjA_H // all headers use an include guard to prevent excessive includes...
#define NINJA_H	// which can cause problems. 

//================================================================================================
// Preprocessor Directives
#include <string>
#include "Character.h" // Character class definition

//================================================================================================
// Class Definition
// create a class called Ninja with public inheritance from Character
class Ninja : public Character 
{
public:

	Ninja(); // Default constructor
	
	// constructor
	Ninja(const string&); // will initialize the name of the character. 

	virtual ~Ninja() = default;	// generate a virtual destructor for this class.

	virtual void Help() const override; // override the Help function for this class as well.

	virtual int attack() override;	// override attack function specific to this class.

	virtual int special() override; // override special function for this class. 

	void ThrowStars() const;	// add a new capablity for this class. 

	// override these get methods to return custom values
	virtual string getType() const override; 

	virtual string getAttackName() const override;

	virtual string getSpecialAttackName() const override;

	virtual int getHitPoints() const override;

	virtual int getSpecHitPoints() const override;

private:

	string type = "Ninja"; // type of character
	string attackName = "Throw Shuriken"; // name of standard attack
	string specialAttackName = "Hidden Kunai"; // name of special attack
	int hitPoints = 20; // damage power.
	int specHitPoints = 35; // special power
};



#endif // end of include guard for NINJA_H
