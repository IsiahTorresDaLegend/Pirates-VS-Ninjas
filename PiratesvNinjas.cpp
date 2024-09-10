/*

PiratesvNinjas.cpp
Source code file containing function definitions for functons used in Pirates vs Ninjas program. 
Written by Isiah Torres
Course: CSC 275

*/
//================================================================================================
// Preprocessor directives
#include <iostream>
#include <string>
#include <random>
#include "PiratesvNinjas.h"
using namespace std;

//================================================================================================
// Function definitions

// Perform actions based on user choice. Allowed user and cpu to make choice separately to allow
// blocking and to allow different characters to attack first if not blocking. 
// Takes two Character shared pointers and an int. 
void humanMove(shared_ptr<Character> human, shared_ptr<Character> opponent, int choice)
{
    // note the use of pointer notation (->) to call member functions 
    if (choice == 1) // if the choice is 1
    {
        if (opponent->isBlocking()) // if isBlocking returns true...
        {
            // attack does nothing and turn switches..
            cout << "\n\033[1;33m" << opponent->getName() << " blocked the attack!\033[0m";
        }
        else
        {
            // if isBlocking is false, damage the opponent.
            opponent->setHealth(opponent->getHealth() - human->attack());
        }
    }
    // do nothing if choice == 2, blocking has already been made true.
    else if (choice == 3) // if choice is 3
    {
        if (opponent->isBlocking()) // if isBlocking returns true...
        {
            // attack does nothing and turn switches..
            cout << "\n\033[1;33m" << opponent->getName() << " blocked the attack!\033[0m";
        }
        else
        {
            // if isBlocking is false, damage the opponent.
            opponent->setHealth(opponent->getHealth() - human->special());
        }
    }
}

// Perform actions based on random number and simulate computer choice. 
// Takes two Character shared pointers and one int. 
void computerMove(shared_ptr<Character> human, shared_ptr<Character> opponent, int choice)
{
    // note the use of pointer notation (->) to call member functions 
    if (choice == 1) // if the choice is 1
    {
        if (human->isBlocking()) // if isBlocking returns true...
        {
            // attack does nothing and turn switches..
            cout << "\n\033[1;33m" << human->getName() << " blocked the attack!\033[0m";
        }
        else
        {
            // if isBlocking is false, damage the opponent.
            human->setHealth(human->getHealth() - opponent->attack());
        }
    }
    // do nothing if choice == 2, blocking has already been made true.
    else if (choice == 3) // if choice is 3
    {
        if (human->isBlocking()) // if isBlocking returns true...
        {
            // attack does nothing and turn switches..
            cout << "\n\033[1;33m" << human->getName() << " blocked the attack!\033[0m";
        }
        else
        {
            // if isBlocking is false, damage the opponent.
            human->setHealth(human->getHealth() - opponent->special());
        }
    }
}

// turn should be a or b. return the opposite.
char switchTurn(char turn)
{
    // turn must == 'a' or 'b'
    if (turn == 'a') // if turn is a
    {
        return 'b'; // return b
    }
    else // if turn is b
    {
        return 'a'; // return a
    }
}

// Display menu to user and return their choice as an int.
// Takes two Character shared pointers as an argument. 
int menu(shared_ptr<Character> human, shared_ptr<Character> opponent)
{
    human->block(false); // reset block after each round. 
    bool success = false; // used to know when do loop is done.
    int numChoice;
    do
    {
        // display the users options
        cout << "\n\nChoose an action: (enter 1-6)\n"
            << "1.) Attack\t" << "2.) Defend\n" << "3.) Use Special\t"
            << "4.) Show Health\n" << "5.) Talk\t" << "6.) Help\n";
        string choice; // user's selected action is stored here
        try
        {
            getline(cin, choice); // allow user to select an action
            numChoice = stoi(choice);
        }
        catch (const invalid_argument& e) // catch stoi() invalid_argument exception.
        {
            // inform the user of the problem.
            cout << "\n\033[1;35mInvalid input. Please enter a valid number.\n\033[0m";
            continue; // jump back to the beginning of the loop.
        }
        catch (const out_of_range& e) // catch stoi() out_of_range exception.
        {
            // inform user of the problem.
            cout << "\n\033[1;35mInput out of range, please enter a smaller number.\n\033[0m";
            continue; // jump back to the beginning of the loop .
        }
        if (numChoice == 1 || numChoice == 3) // if choice is 1 or 3, leave function.
        {
            success = true; // end do loop
        }
        else if (numChoice == 2) // if choice is 2...
        {
            // set block here to ensure a successful block will happen
            // since menu() is called before humanMove()
            human->block(true); // call the block() method to set data member value. 
            success = true; // end do loop.
        }
        else // if choice is not 1, 2, or 3...
        {
            switch (numChoice) // switch statement based on choice. 
            {
            case 4: // if choice is 4...
                // get value of health from both user and opponent and display it.
                cout << "\n\n" << human->getName() << ": " << human->getHealth();
                cout << "\n" << opponent->getName() << ": " << opponent->getHealth();
                continue; // restart the loop. 
            case 5: // if choice is 5...
                // display some banter between the characters with the Talk method
                human->Talk(); // call talk to allow user to enter dialogue.
                opponent->Talk("Enough talking, let's handle business."); 
                continue; // restart the loop
            case 6: // if choice is 6...
                human->Help(); // use the Help() method to display information. 
                continue; // restart loop
            default: // if there is any other answer chosen, send user an error message.
                cout << "\n\033[1;35mInvalid choice, enter a number 1-6.\n\033[0m";
                continue; // then restart loop again
            }
        }
    } while (success == false); // loop until false is true. 
    return numChoice;
}

// use a random number generator to simulate the computer picking a choice. 
int computerChoice(shared_ptr<Character> opponent)
{
    opponent->block(false); // reset the block value.
    // create a random_device object (rd) to generate a seed based on best entropy.
    random_device rd; 
    // create a mt19937 object (gen) and initialize it with rd's operator() seed value
    // to generate a pseudo-random number. 
    mt19937 gen(rd()); // initialize gen with rd() (random_device's operator()).
    // use uniform_int_distribution class to generate pseudo random numbers within a certain
    // range and to ensure each value has an equal probability to get chosen.
    uniform_int_distribution<> dist(1, 3); // distribute a range between 1-3
    // use the output from rng (gen) to map a range of int to the specified range.
    int index = dist(gen); // store it in int variable 'index'

    if (index == 2) // if index ("choice") == 2
    {
        // set blocking here to ensure a successful block since this is called before
        // humanMove() and computerMove().
        opponent->block(true);
    }

    return index; // return the value computed. 

}

// To prevent the user from being the only whose attack registers first, allow computer
// to randomly decide whose attack would land first and switch it after each round. 
// This allows the game to be more different every time the program is ran. 
char firstTurn()
{
    random_device rd; // generate a seed
    mt19937 gen(rd()); // generate a pseudo-random number with the seed
    uniform_int_distribution<> dist(1, 2); // map a range of ints to the desired range.
    int index = dist(gen); // store computed value

    if (index == 1) // if index ("turn") is 1, return a (human's turn)
    {
        return 'a'; // 1 represents a
    }
    else // if index is 2, computer will land their attack first.
    {
        return 'b'; // 2 represents b
    }
}
