/*
* AJ Stein
* Ohio University CS3610 Project 1
* 1-16-20
* We are to write a program that takes some numbers from the command line, and then print them, add to them, delete them, or reverse the order
*/
#include <iostream>
#include "linked_list.h"
using namespace std;
/* Program Notes:
* Need to work on getting command line arguements working
* Need to get reverse working.
* - A, D, P, Q options work
*/
// Functions:
char menu(); // Menu for the user

//*********************************************
int main(int argc, char** argv) {
  LinkedList<int> list;
  cout << "Please do lower case only!";

  // Two variables for the users choices
  int add_num;
  char choice;
  // While statement continues to run program until Q is entered
  while(choice != 'q'){
    choice = menu(); // takes the users choice, duh
    
    switch(choice){
//*********************************************
      // default status of you done messed up with entering an option!
      default:
        cout << "\nThis isnt a valid option, retry!" << endl;
        break;
//*********************************************
      // does literally nothing besides hurt performance probably
      case 'q':
        break;
//*********************************************
      // Prints List
      case 'p':
        cout << endl;
        list.print();
        cout << endl;
        break;
//*********************************************
      // Adds to front of list
      case 'a':
        cout << "\nPlease enter a number:";
        cin >> add_num;
        list.push_front(add_num);
        break;
//*********************************************
      // Deletes first value in list
      case 'd':
        list.pop_front();
        break;
      
      case 'r':
        list.reverse();
        break;
//*********************************************
    } // end of switch
  } // end of while
  cout << "\nYou have quit the program, have a great day!" << endl;

return 0;
} // end of main

//*********************************************
char menu(){
  char choice;
  int num = 0;
  // console menu:
  cout << "\na: Add the integer i to the front of the list. (push front)." << endl;
  cout << "d: Delete the first element of the list. (pop front)" << endl;
  cout << "r: reverse the list." << endl;
  cout << "p: Print the data value of each node in the list." << endl;
  cout << "q: Quit the program." << endl;
  cout << "Please type your choice:";
  cin >> choice;
  return choice;
}
//*********************************************
