// Finding the roots of a Quadratic Equation
// f = ax^2 + bx + c 
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a,b,c;// Coefficients

    cout << "Enter a, b, c: ";
    cin >> a >> b  >> c;

    void qe(int ,int ,int);
    qe(a,b,c);
    

}

double delta(int a, int b, int c)
{
    return (b*b) - (4*a)*c;
}

void qe(int a,int b, int c)// Quadratic Equation function
{    
    double r1, r2; // Roots of the equation
    
    double delta(int, int, int);// Delta func prototype
    double d; // For storing the value of delta func in d

    if(a == 0)// If a == 0 the equation is not quadratic
    {
        cout << "Error!\nThis is not a Quadratic Equation!" << endl;
    }

    else{
        d = delta(a, b, c); // Calculating d
        if (d >= 0)
        {
            r1 = (-b + sqrt(d) ) / 2*a;
            r2 = (-b - sqrt(d) ) / 2*a;
            cout << "Root 1 is "<<r1<< endl;
            cout << "Root 2 is "<<r2<< endl;
        }
    }
}