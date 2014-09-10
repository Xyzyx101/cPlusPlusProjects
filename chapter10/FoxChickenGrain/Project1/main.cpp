// Fox, Chicken, and Grain - classic puzzle 
// Main function

#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    Game foxChickenGrain;
    
    foxChickenGrain.DisplayInstructions();
       
    char again;
    do 
    {
        foxChickenGrain.Play();
        cout << endl << "Play again? (y/n): ";
        cin >> again;
        cout << endl;
    } while (again != 'n');
    
    return 0;
}

