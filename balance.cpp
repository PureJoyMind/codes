// https://codeforces.com/problemset/problem/1606/A

#include <iostream>
#include <string>


using namespace std;

string balanceCheck(string);// func prototype

// bool counter(string);

int main()
{
    int n;
    cin >> n;
    string strs[n];

    for (int i=0; i<n; i++)// Getting input strings from user
    {
        cin >> strs[i];
    }

    for (int i=0; i<n; i++)
    {
        strs[i] = balanceCheck(strs[i]);// Calling balanceCheck func
        cout << strs[i] << endl;// Outputting the balanced string
    }
}

string balanceCheck(string a)
// We deducted that if the first and the last char are the same it works
// So this func does that
{
    int s = a.size() - 1;
    if (a[0] == a[s]){
        return a;
    }
    else{
        a[0] = a[s];
        return a;
    }
}

// We wrote this func to check if the code was working properly

// bool counter(string a){
//     int ab{0}, ba{0};
//     int s = a.size();
//     for(int i{0}; i < s - 1; i++){
//         if(a[i]== 'a' && a[i+1] == 'b')
//             ab++;
//         if(a[i] == 'b' && a[i+1] == 'a')
//             ba++;
//     }
//     return ab == ba;
// }