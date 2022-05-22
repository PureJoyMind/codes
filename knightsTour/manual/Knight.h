// The knight class
#pragma once

#include <array>

class Knight{
    public:

        Knight(int row, int column)
        {
            // Getting the initial position of the knight on the board
            current[0] = row;
            current[1] = column;
        }

        int counter = 1; // The counter for knights position
        // Current location
        // current{row, column}

        void changePos(int& m)// getting move number as input and changing position
        {
            // Bounds checking both horizontal and vertical move before applying them to the variables
            while( (current[0] + moves[m][0]) >= 8 || (current[0] + moves[m][0]) < 0 )
            {
                std::cout << std::setw(10) << "\nU" << "navailable move! Try again: ";
                std::cin >> m;
                /* 
                I tried using a recursive algorithm. I realize it wasn't needed
                in the first place. An interesting bug arose though. I figured it out.
                Recursive is not needed anyways...
                */
                //changePos(m);
            }
            while( (current[1] + moves[m][1]) >= 8 || (current[1] + moves[m][1]) < 0 )
            {
                std::cout << std::setw(10) << "\nU" << "navailable move! Try again: ";
                std::cin >> m;
                //changePos(m);
            }
            
            current[0] += moves[m][0];
            current[1] += moves[m][1];
        }

        void assignCurrent(int& a, int& b)
        {
            a = current[0];
            b = current[1];
        }
    private:
    // https://stackoverflow.com/questions/11734861/when-can-outer-braces-be-omitted-in-an-initializer-list
    // Had problems with initializing the array
    // Found solution on given link
        std::array< std::array<int, 2>, 8 > moves{ 
            {
              {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
              {1, -2}, {2, -1}, {2, 1}, {1, 2}
            }
        };
        std::array< int, 2 > current;
};