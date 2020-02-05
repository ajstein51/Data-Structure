/*
* AJ Stein
* CS 3610 Question 10 on first hw paper
* Using two numbers to multiple but doing it by recursivly calling a function
*/

// includes
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
// functions:
int multiply(int m, int n);

int main(){
    int m = 0, n = 0;
    cout << "\nPlease give me two numbers 'm' and 'n' that you want multiplied(first number will be m, second n): ";
    cin >> m >> n;
    cout << "\nYou have entered these two numbers, m = " << m << " n = " << n << endl;
    cout << multiply(m, n) << endl;
    

    return 0;
}

int multiply(int m, int n){
    if(n == 1)
        return m;
    else
        return m + multiply(m, n - 1);
    
}