// The knight class
#pragma once

#include <array>

class Knight{
    public:
        int counter = 1;

        void changePos(int m)// getting move number as input and changing position
        {
            if( (current[0] + moves[m][0]) < 8 || (current[0] + moves[m][0]) >= 0 )
                current[0] += moves[m][0];
            
            if( (current[1] += moves[m][1]) < 8 || (current[1] += moves[m][1]) >= 0 ) 
                current[1] += moves[m][1];
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
};