#include "huffman_tree.h"
#include "min_heap.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

//*******************************************************************************************
// Returns the min element, since we are doing a min heap the min element should always be the first element. (*doesn't remove*)
template <typename T>
T MinHeap<T>::peek()const{
  if(heap.empty()){
    cout << "\nHeap is empty, ending program!" << endl;
    exit(1);
  } 
  else
    return heap[0]; // first elements, also the lowest/min
}
//*******************************************************************************************
// Personal Note: act like its a linked list?
template <typename T>
void MinHeap<T>::insert(const T data, const int key) {  // need to implement this function
  if(heap.empty())
    // If the heap is empty or otherwise this is the first node.
    heap.push_back(HeapNode<T>(data, key));
  
  else{
    heap.push_back(HeapNode<T>(data, key));
    size_t i = heap.size() - 1;
    while(i != 0){
      i--;
      int left = 2 * i + 1, right = 2 * i + 2;
      if(left > heap.size())
        return;
      int min = i;
      if(heap[i] > heap[left])
        min = left;
      if(heap.size() > heap[i] && heap[min] > heap[right])
        min = right;
      if(min != i)
        swap(heap[i], heap[min]);
    }
  }
}
//*******************************************************************************************
template <typename T>
T MinHeap<T>::extract_min() {                          // need to implement this function

  T data;
  
   return data;
}
//*******************************************************************************************
