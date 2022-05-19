// The knight class
#pragma once

#include <array>

class Knight{
    public:
        int counter = 1;

        void getMove()
        {
            int m;
            std::cin >> m;
            moveNum = m;
        }

        void changePos()
        {
            current[0] += moves[moveNum][0];
            current[1] += moves[moveNum][1];
        }
    private:
    // https://stackoverflow.com/questions/11734861/when-can-outer-braces-be-omitted-in-an-initializer-list
    // Had problems with initializing the array
    // Found solution on given link
        std::array< std::array<int, 2>, 8 > moves{ 
            {
              {2, -1}, {1, -2}, {-1, -2}, {-2, -1},
              {-2, 1}, {-1, 2}, {1, 2}, {2, 1}
            }
        };
        // Current location
        // current{row, column}
        std::array< int, 2 > current;
        // The move number between 0-7
        int moveNum;
};