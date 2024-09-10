/*

PiratesvNinjas.h
Header file for function prototypes used in Pirates vs Ninja program.
Written by Isiah Torres
Course: CSC 275

*/
//================================================================================================
// Include Guard
#ifndef PIRATESVNINJAS_H
#define PIRATESVNINJAS_H

//================================================================================================
#include "Character.h"

//================================================================================================
// function prototypes

// Takes both Character shared_ptrs and the user's choice and performs actions accordingly.
void humanMove(shared_ptr<Character> human, shared_ptr<Character> opponent, int choice);

// Takes both Character shared_ptrs and a int and performs actions accordingly. 
void computerMove(shared_ptr<Character>human, shared_ptr<Character> opponent, int choice);

// pass a character then return the opposite. (only works for a and b) 
char switchTurn(char turn);

// Takes both Character shared_ptrs and presents a menu for a user to make a choice, returns choice
int menu(shared_ptr<Character> human, shared_ptr<Character> opponent);

// Takes a Character shared_ptr representing the computer, uses random number generator as a choice 
int computerChoice(shared_ptr<Character> opponent);

// Uses RNG to decide which Character gets to attack first. (only works with a and b)
char firstTurn();


#endif // end of include guard for PIRATESVNINJAS_H
