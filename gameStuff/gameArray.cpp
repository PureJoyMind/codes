// https://www.youtube.com/playlist?list=PLSPw4ASQYyynKPY0I-QFHK0iJTjnvNUys
// using arrays to store game items
#include <iostream>
#include <iomanip>
#include <string> 
#include <array>

using namespace std;

// The shop array
const size_t shopSize{6};
array <string, shopSize> itemShop {"boots", "leggings", "armors", "axes", "swords", "potions"};

// Function prototypes
void printShop();
void printInventory(array<int, shopSize>);
bool buyItem(array<int, shopSize>& );

int main()
{
    array <int, shopSize> playerInventory{};

    bool game{true};// Game loop continuation condition
    while(game == true)// The game loop
    {
    printShop();
    printInventory(playerInventory);
    game = buyItem(playerInventory);
    }

    cout << "\n\n\n";
}

void printShop()// Printing the shop
{ 
    cout << setw(21) << "*** SHOP ***"<< endl;
    cout << "*****************************"  << endl;
    for(int i{0}; i < shopSize; i++){
        cout << setw(10) << i + 1 << "." << itemShop[i] << endl;
    }
    cout << "*****************************"  << endl;
}

void  printInventory(array <int, shopSize> player)// Printing the players inventory
{
    cout << setw(27) <<"*** YOUR INVENTORY ***"<< endl;
    int counter{1};
    for(int i{0}; i < shopSize; i++){
        if(player[i] > 0){
            cout << setw(10) << counter << "." << itemShop[i];
            cout << " ==> " << player[i] << endl;
            counter++;
        }
    }
    cout << "*****************************"  << endl;
}

bool buyItem(array<int, shopSize>& player)// Buying items (note the referenced argument)
{
    int input;
    cout << "What would you like to buy? <1 - "<< shopSize <<"> (-1 to quit!): ";
    cin >> input;

    if(input == -1 )// Verifying game continuation
    {
        return false;
    }

    if(input < 0 || input > shopSize)// Verifying input validity
    {
        cout << "That is not valid!!!\n\n\n"<< endl ;
        return true;
    }

    player[input - 1]++;// Adding the selected item to inventory
    cout << "\n\n\n";
    return true;
}