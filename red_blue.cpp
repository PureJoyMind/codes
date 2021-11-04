// https://codeforces.com/problemset/problem/1559/B

#include <iostream>
#include <string>
using namespace std;

string converter(string);
bool qCheck(string );

int main(){
    int n;
    int length;
    cin >> n;

    string strs[n];

    for(int i{0};i < n; i++){
        cin >> length;
        cin.ignore();
        getline(cin, strs[i]);
    }

    for (int i{0}; i < n; i++)
    {
        if(qCheck(strs[i])){
            strs[i][0] = 'B';
        }
        cout << converter(strs[i]) << endl;
    }
}

string converter(string str){
    int length = str.size();
    
    
    for(int i{0}; i < (length-1); i++){
        if(str[i] == 'B' && str[i + 1] == '?'){
            str[i + 1] = 'R';
        }
        if(str[i] == 'R' && str[i + 1] == '?'){
            str[i + 1] = 'B';
        }
    }
    for(int i{length - 1}; i > 0; i--){
        if(str[i] == 'B' && str[i - 1] == '?'){
            str[i - 1] = 'R';
        }
        if(str[i] == 'R' && str[i - 1] == '?'){
            str[i - 1] = 'B';
        }
    }

    return str;
 
}

bool qCheck(string ch){
    int all{0};
    for(int i{0}; i < ch.size(); i++){
        if(ch[i] == '?')
            all += 1;
            
    }
    return all == ch.size();
}