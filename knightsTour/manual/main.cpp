// The knights tour chess problem
// Moving the knight around the chess board and touch all 64 squares only once
// The manual method:
//   The user chooses the moves.

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>

#include "Knight.h"

using namespace std;

// Function prototypes
void draw();

// Initializing the game board
array< array<int, 8>, 8 > board {};

int main(){
    int bX = 0;
    int bY = 0;
    
    Knight knight(1, 1);
    while (true)
    {
        bX = knight.current[0];
        bY = knight.current[1];

        // Adding knights position to the game board
        ::board[bX][bY] = knight.counter;
        draw();
        break;
    }
    
}

void draw()// Draw chess board
{
    // First line
    cout << setw(10) << "X"<<' ';
    for(int i{0}; i < 8; i++)
    {
        cout << "  " << i << " ";// Colummn numbers
    }

    cout << endl;

    for(int j{0}; j < 8; j++)
    {
        cout << setw(10) << j;// Row numbers
        for(int k{0}; k < 8; k++)// Each row
        {
            cout << " | " << ::board[j][k];
        }
        cout << " |" << endl;
        cout << setw(12) << '-'<<"---------------------------------"<<endl;
    }

}