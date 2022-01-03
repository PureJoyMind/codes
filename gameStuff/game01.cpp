// https://youtu.be/TH7plF4UT_E
// Coding challenge to make a game
// My personal challenge was to make it without using functions or arrays. 
// Not much off a challenge I know but still. 

#include <iostream>
#include <string>
#include <random>

using namespace std;

int main(){

    default_random_engine randInt{static_cast<unsigned int>(time(0))};
    uniform_real_distribution<float> attackRole{0.0f, 1.0f};

    cout << "\t*** Humans VS Goblins***\n" << endl;

    int humanCount{};// Number of initial humans
    int goblinCount{};// Number of initial goblins

    // damage and health
    float hHealth{250};
    float hDamage{200};
    float gHealth{50};
    float gDamage{40};

    float currentHHealth;
    float currentGHealth;

    int humanKillCount{0};
    int goblinKillCount{0};

    cout << "Enter Human number: ";
    cin >> humanCount;
    cout << "Enter goblin number: ";
    cin >> goblinCount;

    const float hChance{0.6f};// Human attack chance
    const float gChance{0.6f};// goblin attack chance

    // choosing if its humans turn or goblins by replacing 0 and 1 at 
    // the end of each loop
    char turn{'h'};

    while( humanCount > 0 && goblinCount > 0)// while both humans and goblins numbers are above 0
    // (both are still alive)
    {
        float attack = attackRole(randInt);// random attack chance
        // Checking if attack works
        // cout << attack << " is attack number in this turn." << endl;

        if(turn == 'h' && attack < hChance)
        {
            currentGHealth -= hDamage;
            if(currentGHealth < 0){
                --goblinCount;
                ++goblinKillCount;
                currentGHealth = gHealth;
            }
            turn = 'g';
        } 
        else if(turn == 'g' && attack < gChance)
        {
            currentHHealth -= gDamage;
            if(currentHHealth < 0){
                --humanCount;
                ++humanKillCount;
                currentHHealth = hHealth;
            }
            turn = 'h';
        }
    }

    if(humanCount == 0)
    {
        cout << "\nIt was a witty battle between the ferocious beasts and noble knights!" << endl;
        cout << "But in the end... " << endl;
        cout << "The beasts won!\nMay the gods have mercy on our fallen brothers souls...\n"<< endl;
        cout << "-------------------------------------\n";
        cout << humanKillCount <<" humans and "<<goblinKillCount<<" goblins died in this battle."<<endl;
        cout << "In the end " << goblinCount << " goblins survived." << endl;
        cout << "We'll slaughter those beasts later!!!"<<endl;
    }
    else
    {
        cout << "It was a witty battle between the ferocious beasts and noble knights!" << endl;
        cout << "And in the end... " << endl;
        cout << "The fearless knights of the EMPIRE won this battle!\n" <<endl;
        cout << "-------------------------------------\n\n";
        cout << humanKillCount <<" humans and "<<goblinKillCount<<" goblins died in this battle."<<endl;
        cout << "In the end " << humanCount << " brothers returned from the battle." << endl;
        cout << "May we one day win this neverending war...\n"<< endl;
    }

}