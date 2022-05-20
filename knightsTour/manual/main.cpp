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
bool moveCheck(int&);

// Initializing the game board
array< array<int, 8>, 8 > board {};

int main(){
    int bX = 0;
    int bY = 0;

    cout << setw(20) << 'w' << "elcome to The Knights Tour\n\n";
    cout << setw(10) << 'T' << "his is a famous chess problem.\n";
    cout << setw(10) << 'y' << "ou have to move the knight to every\n";
    cout << setw(10) << 's' << "quare of the board, touching them all only once.\n\n";
    cout << setw(10) << "\"K" << "eep in mind that all numbers must be between 0-7\" \n\n";

    cout << setw(10) << 'P' << "lease enter the initial position of the knight:(row, column) ";
    cin >> bX >> bY;

    int playerMove;// Players move on each turn

    Knight knight(bX, bY);
    while (true)
    {
        cout << setw(10) << 'E' << "nter the next move:(0-7)";
        cin >> playerMove;
        moveCheck(playerMove);

        knight.changePos(playerMove);

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

bool moveCheck(int& a)// Bounds checking player moves
{
    while(a < 0 || a > 7)
        cout << setw(10) << "\nT" << "hat is a wrong move try again: ";
        cin >> a;
    return true;
}