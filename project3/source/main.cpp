/** 
 * AJ Stein
 * Data Structure
 * March 4, 2020
*/
#include <iostream>
#include <string>
#include "huffman_tree.h"
#include "min_heap.h"
using namespace std;

int main(int argc, char** argv) {
  // Create a HuffmanTree object and read the input messages into the
  // HuffmanTree construct function. Next, print the encoded message.
  // Finally, destruct the huffman tree and move on to the next test case.
  
  HuffmanTree t;
  
  // User Prompt for messages
  int input;
  cout << "Please give the number of messages: ";
  cin >> input;
  cin.ignore();
  
  // Messages (strings) to be encoded.
  string words = "";
  for(size_t i = 1; i <= input; i++){
    cout << "\nPlease enter the messages now: ";
    getline(cin, words);
    t.construct(words);
    cout << "Test Case: " << i << endl;
    t.print();
    t.destruct();
  }
  return 0;
}

/**
 * Main is done.
 */