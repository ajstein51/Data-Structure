/*
* AJ Stein
* CS 3610 Question 12 on first hw paper
* Making a sequencial search recursive
*/
#include <iostream>
#include <vector>
using namespace std;
// Functions:
int seqsearch(int target, vector<int> t, int x);

int main(){
    int input = 0, amount = 0, target = 0;
    vector<int> t;
    cout << "\nHow many numbers will you be entering: ";
    cin >> amount;
    cout << "\nEnter the numbers: ";
    for(int i = 0; i < amount; i++){
        cin >> input;
        t.push_back(input);
    }
    cout << "\nWhat is your target number: ";
    cin >> target;

    cout << "\nThis position of the target is: " << seqsearch(target, t, 0) << endl;

    return 0;
}

int seqsearch(int target, vector<int> t, int x){
    if(t[x] == target)
        return x;
    else
        return seqsearch(target, t, x + 1);
}