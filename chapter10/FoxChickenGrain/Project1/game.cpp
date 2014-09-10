// Fox, Chicken, and Grain - classic puzzle 
// Game implementation - class represents a fox, chicken, and grain game

#include "game.h"

#include <iostream>
#include <string>

using namespace std;

const string Game::NORTH = "north";
const string Game::SOUTH = "south";
const string Game::ITEMS[NUM_ITEMS] = {"fox", 
                                       "chicken", 
									   "grain"};

//constructor
Game::Game()
{
    SetUp();
}

//status of whether or not game is won
bool Game::IsWon() const
{
    //if all items are on the north bank, player has won
    if (m_North.Count() == NUM_ITEMS)
    {
        cout << "You won!" << endl;
        return true;
    }

    //otherwise, player hasn't won
    return false;
}

//status of whether or not game is lost
bool Game::IsLost(const List& withoutFarmer) const
{
    //if item and its food on bank without farmer, player has lost
    for (int i=0; i<NUM_ITEMS - 1; ++i)
    {
        if ( withoutFarmer.Contains(ITEMS[i]) &&   //item
             withoutFarmer.Contains(ITEMS[i+1]) )  //food
        {
            cout << "The " << ITEMS[i];
			cout << " ate the " << ITEMS[i+1] << "! ";
            cout << "You lost!" << endl;
            return true;
        }
    }
   
    //otherwise, player hasn't lost
    return false;
}

//status of whether or not game is on
bool Game::IsPlaying() const
{
     bool lost;
     if (m_FarmerBank == SOUTH)
     {
         lost = IsLost(m_North);
     }
     else
     {
         lost = IsLost(m_South);
     }

     bool won = IsWon();
     
     //if player hasn't won and hasn't lost, game still on
     return (!lost && !won);
}

//sets up banks and farmer location
void Game::SetUp() 
{ 
    m_South.Clear();
    m_North.Clear();
    
    m_FarmerBank = SOUTH;
    
    for (int i=0; i<NUM_ITEMS; ++i)
    {
        m_South.Add(ITEMS[i]);
    }
}

//displays game instructions
void Game::DisplayInstructions() const
{
    cout << "\tWelcome to Fox, Chicken, and Grain";
    cout << endl << endl;
    
    cout << "A farmer must get his fox, chicken and grain safely " << endl;
    cout << "across a river from the south bank to the north bank." << endl;
    cout << "The farmer can take at most one thing with him when " << endl;
    cout << "he makes a trip across. Unfortunately, if the farmer " << endl;
    cout << "leaves the fox and chicken together, the fox will " << endl;
    cout << "eat the chicken. If the farmer leaves the chicken " << endl;
    cout << "and the grain together, the chicken will eat the grain." << endl;
    cout << endl;
    
    cout << "Help the farmer by entering the name of what you " << endl;
    cout << "want him to carry on his next trip to the opposite bank." << endl; 
    cout << "If you want the farmer to cross the river without " << endl;
    cout << "carrying anything, enter 'nothing' at the prompt." << endl;
    cout << endl;
}

//displays items on banks
void Game::DisplayBanks() const
{
    cout << "South bank:" << endl;
    m_South.Display();
    cout << endl;

    cout << "North bank:" << endl;
    m_North.Display();
    cout << endl;
 
    cout << "The farmer is on the ";
	cout << m_FarmerBank << " bank." << endl;  
    cout << endl;
} 

//moves an item from one bank to another
void Game::TransportItem(List& fromBank, List& toBank)
{
    string itemName;    //the item to transport 
   
    cout << "What should the farmer take?: ";
    cin >> itemName;
    cout << endl;
    
    //Remove() returns true if successful transfer
    if (fromBank.Remove(itemName))
    {
        toBank.Add(itemName);
        cout << "The farmer takes the ";
		cout << itemName << " with him." << endl;
    } 
    //Remove() returns false if couldn't find item 
    else
    {
        cout << "The farmer takes nothing." << endl;
    }

    cout << endl;
}

//plays the game
void Game::Play()
{
    SetUp();
    DisplayBanks();
        
    while (IsPlaying())
    {
        if (m_FarmerBank == SOUTH)
        {
            TransportItem(m_South, m_North);
            m_FarmerBank = NORTH;
        }
        else
        {
            TransportItem(m_North, m_South);
            m_FarmerBank = SOUTH;
        }
           
        DisplayBanks();
    }   
}
