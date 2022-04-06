#include <bits/stdc++.h>

using namespace std;

int binaryCheck(string);
bool multiCheck(string, int);

int main(){
    int t;
    cin >> t;
    
    for (int i; i < t; t++)
    {
        string digits;
        cin >> digits[i]; 
        
    }
}


int binaryCheck(string test){
    int one{0}, zero{0};

    for(int i{0}; i < test.length(); i++){
        if (test[i] == '1')
            one += 1;
        else
            zero += 1;
    }
    if (one > zero)
        return one;
    else 
        return zero;
}

bool multiCheck(string test, int idx){
    if(test[idx] == test[idx - 1] || test[idx] == test[idx + 1]){
        return true;
    }
    else 
        return false;
}