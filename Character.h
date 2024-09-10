/*

Character.h
Class definition for Character, derived from GameStructure.
Written by Isiah Torres for course CSC 275

*/
//================================================================================================
// Include Guard
#ifndef CHARACTER_H
#define CHARACTER_H

//================================================================================================
// Preprocessor Directives
#include <string>	// allows the use of string objects
#include "GameStructure.h" // base-class definition

//================================================================================================
// Class Definition

// created a class called Character with public inheritance from the GameStructure class.
class Character : public GameStructure
{
public: // these members can be used anywhere where the object is used.
	Character();	// constructor

	virtual ~Character() = default; // compiler generates a virtual destructor. 

	// must override Help() to be a concrete class. We use the override keyword to make our
	// intentions clear. virtual functions allows the compiler to use the appropriate function
	// according to the type of object that is invoking it; This allows us to use multiple 
	// definitions for the same function name. 
	virtual void Help() const override;

	// All characters will have an attack method, this method will be overriden by derived-classes
	// This function returns an int and takes an int as a parameter. 
	virtual int attack();

	// All characters will have a special ability or attack. Will be overriden by the derived
	// classes and will return an int. 
	virtual int special();

	// overloaded talk methods
	void Talk(const string) const;	// this method takes only one string parameter
	
	// if there are two parameters provided, use this method
	void Talk(const string, const string) const; 

	// third version of Talk()
	void Talk() const;

	// set and get methods
	void setName(const string&);	// set name, takes a constant reference as a parameter.
	string getName() const;	// returns name, is constant so it cannot change member variable.

	void setType(const string&); // set type, takes a constant string reference
	virtual string getType() const; // returns type, constant so it cannot change a member variable.

	void setAttackName(const string&); // set attackName variable
	virtual string getAttackName() const; // returns attackName value

	void setSpecialAttackName(const string&); // set specialAttackName
	virtual string getSpecialAttackName() const; // get specialAttackName

	void setHitPoints(const int&); // set hitPoints attribute
	virtual int getHitPoints() const; // get hitPoints attribute

	void setSpecHitPoints(const int&); // set specHitPoints attribute
	virtual int getSpecHitPoints() const; // get specHitPoints attribute

	void block(bool); // set blocking attribute
	bool isBlocking() const; // get blocking attribute

	void setHealth(double);	// set health, takes double as a parameter to use a decimal place.
	double getHealth() const; // get health.

	static const double MAX_HEALTH; // max health a character can have.
	// static member stores infomation about the entire class, exists for entire class.

private: // hidden and can only be accessed by public methods.  
	string name;	// name of character
	string type; // type of character
	string attackName; // name of standard attack
	string specialAttackName; // name of special attack
	int hitPoints; // damage power.
	int specHitPoints; // special power
	bool blocking = false; // determines if character is blocking, starts as false.
	double health = MAX_HEALTH;	// health of character, each character starts with full health. 
};

#endif	// end of include guard for CHARACTER_H
