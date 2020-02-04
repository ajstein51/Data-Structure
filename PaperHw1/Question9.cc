/*
* AJ Stein
* CS 3610 Question 9 on first hw paper
* The questions wants this program to find the mean and standard deviation of numbers
*/

// includes
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

// functions
void writevector(const vector<int> &t); // prints the vector
double mean(const vector<int> &t); // finds and returns the mean;
double standarddev(const vector<int> &t); // finds the standard dev

int main(){
    int input_num = 0, amount = 0;
    vector<int> t;
    
    cout << "\nHow many numbers will you be entering: ";
    cin >> amount;
    cout << "\nEnter the numbers: ";
    for(int i = 0; i < amount; i++){
        cin >> input_num;
        t.push_back(input_num);
    }
    // just whats been given:
    cout << "\nHere is what you have entered: ";
    writevector(t);
    // mean:
    cout << "\nHere is the mean: " << mean(t) << endl;
    // the deviation num:
    cout << "Here is the standard deviation: " << standarddev(t) << endl;

    return 0;
}

double standarddev(const vector<int> &t){
    double tmp = 0.0, meantmp = mean(t);
    for(size_t i = 0; i < t.size(); i++)
        tmp += pow(t[i] - meantmp, 2);

    tmp = sqrt(tmp / t.size());
    return tmp;
}

double mean(const vector<int> &t){
    double tmp = 0.0;
    for(size_t i = 0; i <t.size(); i++)
        tmp += t[i];
    
    tmp = tmp / t.size();
    return tmp;
}

void writevector(const vector<int> &t){
    for(size_t i = 0; i <t.size(); i++)
        cout << t[i] << " ";
    
    cout << endl;
}