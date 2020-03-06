#include <iostream>
#include <string>
#include "huffman_tree.h"
#include "min_heap.h"
using namespace std;

void HuffmanTree::construct(const string message) {
  this->message = message;

  // Count the frequency of each letter in message
  // e.g. 
  //    message == "aaabbccccdd"
  //    frequencies == {a:3, b:2, c:4, d:2} 
  map<char, int> frequency_map;
  for (int i = 0; i < message.length(); ++i) {
    if (frequency_map.find(message[i]) != frequency_map.end())
      ++frequency_map[message[i]];
    else
      frequency_map[message[i]] = 1;
  }

  // Create HuffmanNode for each unique letter in message
  // and organize nodes into a min heap
  // e.g.
  //  heap == 
  //            {b:2}  
  //           /     \
  //        {d:2}   {a:3}
  //        /   \   /    \
  //      {c:4} 
  MinHeap<HuffmanNode*> heap;
  map<char, int>::iterator it = frequency_map.begin();
  for (; it != frequency_map.end(); ++it) {
    HuffmanNode* node = new HuffmanNode(
      it->first, it->second
    );
    heap.insert(node, it->second);
  }

  // Combine nodes with smallest frequency and insert
  // back into heap until heap size == 1. Along the way,
  // create binary tree out of combined nodes.
  // e.g.
  //  (1)
  //     {b:2} == heap.extract_min()
  //     {d:2} == heap.extract_min()
  //     parent ==
  //               {*:4}
  //              /     \
  //            {b:2}  {d:2}
  //
  //     heap == 
  //              {a:3}
  //             /     \
  //           {c:4}   {*:4}
  //
  //  (2)
  //     {a:3} == heap.extract_min()
  //     {c:4} == heap.extract_min()
  //     parent ==
  //              {*:7}
  //             /     \
  //          {a:3}   {*:4}
  //    
  //     heap ==
  //            {c:4}
  //           /
  //         {*:7}
  //
  //  (3)
  //     {*:4} == heap.extract_min()
  //     {*:7} == heap.extract_min()
  //     parent ==
  //            {*:11}
  //           /       \
  //      {c:4}        {*:7}
  //                  /     \
  //                {a:3}  {*:4}
  //                       /    \
  //                    {b:2}  {d:2}
  //
  //     heap == {*:11}
  while (heap.size() > 1) {
    HuffmanNode *left, *right;
    left = heap.extract_min();
    right = heap.extract_min();

    HuffmanNode *parent = new HuffmanNode(
      left->frequency + right->frequency
    );

    parent->left = left;
    parent->right = right;
    
    heap.insert(parent, parent->frequency);
  }

  // Get root of huffman tree. e.g. {*:11}
  this->root = heap.peek();
}

void HuffmanTree::print() const {   
  // Print the Huffman encoding of this->message.
  // Append 0 to a character's encoding if moving left in Huffman tree.
  // Append 1 to a character's encoding if moving right in Huffman tree.

  // Remember, your Huffman tree is pointed at by this->root, so start your
  // character searches from there.

  // Also, feel free to add a print helper function.

  map<char, string> map;                                                                                // maps work like: <key, element>

  encode(root, "", map);
  
  char ch;
  for(int i = 0; i < message.size(); i++){
    ch = message[i];
    cout << map[ch] << " ";
  }
  cout << endl;
}
/**
 * opossum: 11 00 11 10 10 011 010
 * hello world: 010 011 10 10 00 1100 1101 00 1110 10 1111
 * message: 011 10 11 11 010 00 10
 * To write the map: 
  for(auto it = map.cbegin(); it != map.cend(); ++it)                                                     // printing element of the map
    cout << it -> first << it -> second << " ";
 *  
 */

void HuffmanTree::encode(const HuffmanNode* current, string hold, map<char, string> &map)const{
  
  if(current == NULL)
    return;
  if(current -> left == NULL && current -> right == NULL)                                                 // If its a leaf
    map.insert(pair<char, string>(current -> character, hold));
  else{
    encode(current -> left, hold + "0", map);                                                             // Append 0
    encode(current -> right, hold + "1", map);                                                            // Append 1
  }

}       
