/*

Pirates vs Ninja program
Demonstrating Object-Oriented Programming using Classes, Encapsulation, Abstraction,
Polymorphism, and inheritance.
Written by Isiah Torres for course CSC 275.

*/
//================================================================================================
// Preprocessor Directives
#include <chrono> //  included to use chrono::seconds()
#include <iostream> // standard input/output operations
#include <random> // to use random_device, mt19937, and uniformed_int_distribution class for RNG
#include <string> // to use string objects
#include <thread> // to use this_thread::sleep_for() 
#include "GameStructure.h" // abstract-base-class definition
#include "Character.h"  // Character class definition
#include "Ninja.h"  // Ninja class definition 
#include "Pirate.h" // Pirate class definition
#include "PiratesvNinjas.h" // to use functions made for this program
using namespace std; // to reduce typing

//================================================================================================ 
// main function
int main()
{

    string repeat = "y"; // this variable will keep our game loop going until user changes this
    while (repeat == "y")   // will keep going until user changes "answer" at the end.
    {
        system("cls"); // sends the "cls" command to Windows consoles to clear the screen.

        // use ANSI escape codes to change style and color of text in console and used 
        // raw string literal to add ASCII art for title. 
        cout << "\n\n\033[1;33m";
        cout << R"(___  _ ____ ____ ___ ____ ____    _  _ ____    _  _ _ _  _  _ ____ ____ 
|__] | |__/ |__|  |  |___ [__     |  | [__     |\ | | |\ |  | |__| [__  
|    | |  \ |  |  |  |___ ___]     \/  ___]    | \| | | \| _| |  | ___])";

        cout << "\n\n\033[0m";
        // brief description about the program. 
        cout << "\nThis is the arena to settle a rivalry that began centuries ago. It is time.\n"
            << "There is a long argued dispute over who is more deadly. Is it Pirates?\n"
            << "Or is it Ninjas? This dispute will be settled here in this arena with battle!\n"
            << "Which side will you choose in this battle to settle the score?\n";


        // user will pick between two choices (a or b) and be assigned a character.
        string character;
        string humanName; // allow user to create a name for their character

        // will assign Character based on user's choice.
        shared_ptr<Pirate> pirate(new Pirate()); // Create a shared pointer to a new Pirate object
        shared_ptr<Ninja> ninja(new Ninja()); // Create a shared pointer to a new Ninja object.
        // Create two shared pointers to a Character object.       
        shared_ptr<Character> humanPtr; // this one will represent the user
        shared_ptr<Character> opponentPtr; // this one will represent the computer. 

        do // do loop to run this block until user selects valid answer. 
        {
            cout << "Choose your Character: (a or b)\n"
                << "a.) Pirate\n" << "b.) Ninja\n";
            getline(cin, character); // user's choice is stored in character.
            // if user does not choose a or b, send a message.
            if (character != "a" && character != "b")
            {
                // end message to user and loop again. 
                cout << "\n\033[1;35mInvalid option! Enter a or b.\n\n\033[0m";
            }
        } while (character != "a" && character != "b"); // loop until character is equal to a or b. 

        do
        {
            cout << "\n\nEnter a name for your character: \n";
            getline(cin, humanName);    // use getline() to allow user to use spaces and symbols too.
            if (humanName.empty())
            {
                cout << "\n\033[1;35mMust enter a name for your character.\n\033[0m";
            }
        } while (humanName.empty());
        
        if (character == "a")   // if user chose a, they will be a pirate.
        {
            humanPtr = pirate; // assign the humanPtr to the pirate shared pointer. 
            humanPtr->setName(humanName); // set the member variable to the value the user input.

            opponentPtr = ninja; // the opponent will be a ninja if the human is a pirate.
            opponentPtr->setName("Cursed Shinobi"); // set name value of ninja object (opponent).
        }
        else
        {
            humanPtr = ninja; // assign the humanPtr to the ninja shared pointer. 
            humanPtr->setName(humanName); // set name with the setName() member function. 

            opponentPtr = pirate; // If human is a ninja, the opponent will be a pirate. 
            opponentPtr->setName("Captain Blood Beard"); // set name value of the pirate object ()
        }

        // inform user that characters have been sucessfully created.
        cout << "\n\033[1;34mCharacters created!\n\033[0m";

        // display the characters in the battle. 
        // using pointer notation, call member functions to display all attribute values. 
        cout << "\n" << humanPtr->getName() << "\n"
            << "Type: " << humanPtr->getType() << "\n"
            << "Attack: " << humanPtr->getAttackName() << "\n"
            << "Special: " << humanPtr->getSpecialAttackName() << "\n"
            << "Health: " << humanPtr->getHealth() << "\n\n"
            << "\033[1;33mVERSUS\n\033[0m"
            << "\n" << opponentPtr->getName() << "\n"
            << "Type: " << opponentPtr->getType() << "\n"
            << "Attack: " << opponentPtr->getAttackName() << "\n"
            << "Special: " << opponentPtr->getSpecialAttackName() << "\n"
            << "Health: " << opponentPtr->getHealth() << "\n\n"
            << "\033[1;31mFIGHT!\033[0m\n";

        // determine whose attack will land first in the first round
        char turn = firstTurn(); // firstTurn() uses rng, makes the game a little different. 
        if (turn == 'a') // if a, human's attack will land first in the first round
        {
            // inform user
            cout << "\n\033[1;33m" << humanPtr->getName() << " attacks first.\n\033[0m";
        }
        else // the computer's attack will land first in the first round. 
        {
            // inform user.
            cout << "\n\033[1;33m" << opponentPtr->getName() << " attacks first.\n\033[0m";
        }
        int choice; // will represent human's choice
        int cpuChoice; // will represent computer's choice
        int i = 1; // will represent the round count. 
        // loop rounds until one of the character's health drops to 0.
        while (humanPtr->getHealth() > 0 && opponentPtr->getHealth() > 0)
        {
            // display round count.
            cout << "\n\n\033[1;33mROUND " << i << "\n\033[0m";

            // present user with a menu and return their choice. 
            choice = menu(humanPtr, opponentPtr);
            // sleep for 3 seconds to simulate doing work using the this_thread namespace
            // and chrono::seconds()
            this_thread::sleep_for(chrono::seconds(3));
            // obtain a value for choice with RNG. 
            cpuChoice = computerChoice(opponentPtr);
            // turn will switch every round to determine whose attack would land first
            // (if other character is not blocking) to add a little more strategy. 
            if (turn == 'a')
            {
                // human's attack will land first, perform actions based on choice.
                humanMove(humanPtr, opponentPtr, choice);
                if (opponentPtr->getHealth() == 0)
                {
                    // if human's attack makes opponent's health drop to zero, end the match
                    break; // end while loop.
                }
                // computer's attack will land second, perform actions based on choice.
                computerMove(humanPtr, opponentPtr, cpuChoice);
            }
            else // turn == b
            {
                // computer's attack will land first, perform actions based on choice.
                computerMove(humanPtr, opponentPtr, cpuChoice);
                // if human's health drops to 0 first, end match
                if (humanPtr->getHealth() == 0) 
                {
                    break; // end while loop. 
                }
                // human's move will land second. 
                humanMove(humanPtr, opponentPtr, choice);
            }
            // switch whose attack would land first each round. 
            turn = switchTurn(turn);
            // get value of health from both user and opponent and display it.
            cout << "\n\n" << humanPtr->getName() << ": " << humanPtr->getHealth();
            cout << "\n" << opponentPtr->getName() << ": " << opponentPtr->getHealth();
            // increment round count after each loop. 
            i++;
        }

        if (humanPtr->getHealth() == 0)
        {
            cout << "\n\n\033[1;31mYOU LOST.\n"
                << "You have failed your people.\n"
                << opponentPtr->getType() << "s are more deadly.\n\n"
                << opponentPtr->getName() << ": Hahaha. You never stood a chance!\n\033[0m";
        }
        else
        {
            cout << "\n\n\033[1;32mYOU WON!\n"
                << "You have brought glory to your people!\n"
                << humanPtr->getType() << "s are the true warriors!\n\033[0m";
        }
        
        bool success = false; // reset success to false to use in do loop.
        do // do this action at least once until user selects a proper option.
        {
            string choice;
            try // try the following actions. 
            {

                cout << "\n\n\033[1;33mRematch? (enter y or n)\n\033[0n";
                getline(cin, choice);
                if (choice == "y" || choice == "n") // if choice == y or n, repeat the program.
                {
                    repeat = choice; // while loop continues.
                    success = true; // do loop ends.
                }
                else // if choice3 does not equal y or n
                {
                    // throw this exception. this is a string, but strings are objects, not 
                    // data types... 
                    throw "Exception: Invalid answer, please enter 'y' for yes or 'n' for no.\n\n";
                }
            }
            // the exception is essentially an array of characters so to refer to it we must use
            // a pointer.
            catch (const char* e)
            {
                cout << e << endl; // display the exception message to user.
            }
        } while (success == false);
    }

}
