// Fox, Chicken, and Grain - classic puzzle 
// Game definition - class represents a fox, chicken, and grain game

#ifndef GAME_H 
#define GAME_H 

#include <string>
#include "list.h"

using namespace std;

class Game
{
public:
    Game();                            
    //status of whether or not game is won
    bool IsWon() const;                
    //status of whether or not game is lost
    bool IsLost(const List& withoutFarmer) const;  
    //status of whether or not game is on
    bool IsPlaying() const;            
    //sets up banks and farmer location
    void SetUp();                      
    //displays game instructions
    void DisplayInstructions() const;  
    //displays items on banks
    void DisplayBanks() const;         
    //moves an item from one bank to another
    void TransportItem(List& fromBank, List& toBank);  
    //plays the game
    void Play();                       
                   
private:    
    static const string NORTH;       //constant for north
    static const string SOUTH;       //constant for south
    
    static const int NUM_ITEMS = 3;  //number of items
    static const string ITEMS[NUM_ITEMS];  //items 
    
    List m_North;                    //north bank
    List m_South;                    //south bank

    string m_FarmerBank;             //farmer location
};

#endif
