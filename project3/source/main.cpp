#include <iostream>
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
  cout << "\nPlease give the number of messages: ";
  cin >> input;
  cin.ignore();
  // Messages (strings) to be encoded.
  string words = "";
  getline(cin, words, '\n');

  for(size_t i = 1; i <= input; i++){
    getline(cin, words, '\n');
    t.construct(words);
    cout << "\nTest Case: " << i << endl;
    t.print();
    t.destruct();
  }


  return 0;
}
