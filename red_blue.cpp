// https://codeforces.com/problemset/problem/1559/B

#include <iostream>
#include <string>
using namespace std;

string converter(string);// Function prototypes
bool qCheck(string );// Function prototypes

int main(){
    int n;
    int length;
    cin >> n;

    string strs[n];// Array to store the input strings

    for(int i{0};i < n; i++)// Getting the strings from user and storing in strs
    {
        cin >> length;
        cin.ignore();
        getline(cin, strs[i]);
    }

    for (int i{0}; i < n; i++)// For each given string
    {
        if(qCheck(strs[i]))// Calling qCheck func and if was true replace the first char with 'B'
        {
            strs[i][0] = 'B';
        }
        cout << converter(strs[i]) << endl;// Calling the convert func to the given string
    }
}

string converter(string str)// Converting '?'s to 'B's and 'R's
{
    int length = str.size();
    
    for(int i{0}; i < (length-1); i++)// Loop the string from [0] to end first
    {
        if(str[i] == 'B' && str[i + 1] == '?')// If the char is 'B' and the next char is '?'
        {
            str[i + 1] = 'R';
        }
        if(str[i] == 'R' && str[i + 1] == '?')// If the char is 'R' and the next char is '?'
        {
            str[i + 1] = 'B';
        }
    }
    for(int i{length - 1}; i > 0; i--)// Loop the string from end to [0]
    {
        if(str[i] == 'B' && str[i - 1] == '?')// If the char is 'B' and the next char is '?'
        {
            str[i - 1] = 'R';
        }
        if(str[i] == 'R' && str[i - 1] == '?')// If the char is 'R' and the next char is '?'
        {
            str[i - 1] = 'B';
        }
    }

    return str;
 
}

bool qCheck(string ch)// Checking if all characters are '?'
{
    int all{0};
    for(int i{0}; i < ch.size(); i++)// Counting all the '?'s in a given string
    {
        if(ch[i] == '?')
            all += 1;
            
    }
    return all == ch.size();// If the count was equal to the length of the string return 1
}