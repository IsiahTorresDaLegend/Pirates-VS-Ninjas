/*

GameStructure.h
GameStructure Abstract Base Class Definition
Written by Isiah Torres for course CSC 275

*/
//================================================================================================
// Include Guard 
#ifndef GAMESTRUCTURE_H	// if header file is not defined or included...
#define GAMESTRUCTURE_H	// define this header file so compiler includes it, else skip it.

//================================================================================================
// Preprocessor Directves
using namespace std; // allows the standard library to be visible to the program (no std:: needed)

//================================================================================================
// Class Definition
class GameStructure
{
public:
	// the compiler will generate a default constructor for us. No custom constructor needed. 
	
	// since we plan on using virtual functions for derived classes, it is good practice to add
	// a virtual destructor so programs can be destroyed dynamically with the appropriate
	// destructor. 
	// We explicity tell the compiler to generate a default version of the destructor with = default
	virtual ~GameStructure() = default; 

	// pure virtual functions are indicated with the virtual keyword and ending with = 0.
	// This function is void and constant because it will not be altering any member variables
	// nor return any values, just display text to the user. 
	// This class is now abstract since it has a pure virtual function. No objects can be created
	// because there is no implementation. Any derived classes must override this function to be
	// concrete and able to create objects, or else they are also abstract classes.
	virtual void Help() const = 0;
};


#endif // end of include guard for GAMESTRUCTURE_H
