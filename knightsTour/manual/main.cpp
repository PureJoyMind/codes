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

    ::board[bX][bY] = knight.counter;
    
    draw();
    knight.counter++;
    
    // Temporary variable: 
    // For when a square is full I can use this to revert
    // back to the previous move
    int tmpX{bX}, tmpY{bY};

    int revertPlayerMove = 0;

    while (true)
    {
        cout << setw(10) << "\"E" << "nter -1 to exit the game\"\n\n ";
        cout << setw(10) << 'E' << "nter the next move(0-7): ";
        cin >> playerMove;

        if(playerMove == -1)
            break;

        while(playerMove < 0 || playerMove > 7)
        {
            cout << setw(10) << "\nO" << "ut of bounds! Try again(0-7): ";
            cin >> playerMove;
        }

        knight.changePos(playerMove);

        // tmp var for the last position on board
        tmpX = bX;
        tmpY = bY;

        knight.assignCurrent(bX, bY);
        // Adding knights position to the game board
        // Checking if that spot is empty
        if(::board[bX][bY] == 0)
        {
            ::board[bX][bY] = knight.counter;
            draw();
            knight.counter++;
        }
        else{
            cout << setw(10) << "\nO" << "ops! That spot is already full!\n";
            // Reverting bX, bY back to last position 
            bX = tmpX;
            bY = tmpY;

            // Reverting the current position in Knight object
            // back to last position
            /*
            In order to reverse a knight move, we must use
            the move number used and add 4 to it. if it exeeds 7 then
            we must start from 0 and add 4 then.
            I used a switch case to do this.
            */
            switch (playerMove)
            {
            case 0:
                revertPlayerMove = 4;
                break;
            case 1:
                revertPlayerMove = 5;
                break;
            case 2:
                revertPlayerMove = 6;
                break;
            case 3:
                revertPlayerMove = 7;
                break;
            case 4:
                revertPlayerMove = 0;
                break;
            case 5:
                revertPlayerMove = 1;
                break;
            case 6:
                revertPlayerMove = 2;
                break;
            case 7:
                revertPlayerMove = 3;
                break;
            default:
                break;
            }
            knight.changePos(revertPlayerMove);

        }
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