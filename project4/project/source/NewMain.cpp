#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct nodestruct{
  int e, i, j; // E = element, i = vector index, j = element index
  friend bool operator >(const nodestruct &n1, const nodestruct &n2) {return n1.e > n2.e;}
};
//---------------------------------------------------------------------------------
int partition(vector<int>& list, int first, int last) {
  // The pivot should be the median of the
  // first, middle, and last elements.
  // Initializing middle
  int mid = first + (last - first) / 2;
//---------------------------------------------
  // Comparing
  if(list[mid] <= list[first])
    swap(list[mid], list[first]);
  if(list[mid] >= list[last])
    swap(list[mid], list[last]);
  if(list[first] >= list[last])
    swap(list[first], list[last]);
//---------------------------------------------
  // sorting
  int p = list[first];
  for(int i = first - 1; list[i] < p; i++){
    for(int j = last + 1; list[j] > p; j--){
      if(i >= j)
        return j;
      swap(list[i], list[j]);
    }
  }
}
//---------------------------------------------------------------------------------
void quicksort(vector<int>& list, int first, int last){ 
  if(first < last)
    partition(list, first, last);
  
}
//---------------------------------------------------------------------------------
void multiway_merge(vector<vector<int> >& input_lists, vector<int>& output_list){
  priority_queue<nodestruct, vector<nodestruct>, greater<nodestruct> > MinHeap; 
  nodestruct node;
//---------------------------------------------
  for(int i = 0; i < input_lists.size(); i++){
    node.e = input_lists[i][0];
    node.i = i, node.j = 1;
    MinHeap.push(node);
  }
//---------------------------------------------
  for(int i = 0; i < (input_lists.size() * input_lists[0].size()); i++){
    nodestruct root = MinHeap.top();
    MinHeap.pop();
    if(root.j + 1 < input_lists[root.i][root.j]){
      node.e = input_lists[root.i][root.j];
      node.i = root.i, node.j = root.j + 1;
      MinHeap.push(node);
    }
    output_list[i] = root.e;
  }

} 
//---------------------------------------------------------------------------------
int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > input_lists(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input_lists[i][j];
    }
  }
  
  // Quicksort k sublists
  for (int i = 0; i < input_lists.size(); ++i)
    quicksort(input_lists[i], 0, m-1); // breaking here

  // Merge n input sublists into one sorted list
  vector<int> output_list(n * m);
  multiway_merge(input_lists, output_list); 
  
  for (int i = 0; i < output_list.size(); ++i)
    cout << output_list[i] << " ";
  
  cout << endl;
}

/**
 * Correct Output:
 *  0 1 3 4 22 23 28 41 42 49 58 79 83 100 222 422 425 444 599 934
 * 
 *  Seems to be good up until 83
*/