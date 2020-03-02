#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}
  bool operator<(const HeapNode<T>& rhs) {return this->key < rhs.key;}
  bool operator<=(const HeapNode<T>& rhs) {return this->key <= rhs.key;}

  T data;
  int key;
};

template <typename T>
class MinHeap {
public:
  // default constructor and destructor
  MinHeap();       
  ~MinHeap();

  void insert(const T data, const int key);    // Need to do
  T extract_min();                             // Need to do
  T peek() const;                              // Should be functional                 
  int size() const                             // Returns the size of the vector/heap, should be functional
    {return heap.size();}                                    

private:
  vector<HeapNode<T> > heap;                   // KEEP IN MIND ITS A VECTOR
};

#include "min_heap.template"