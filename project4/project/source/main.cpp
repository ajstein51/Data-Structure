#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//************************************************************************************
int partition(vector<int>& list, int first, int last) {
  // The pivot should be the median of the
  // first, middle, and last elements.

  // Initializing middle
  int mid = first + (last - first) / 2;
  //*****************************************
  // Checking if they are all valued correctly
  if(list[mid] <= list[first])
    swap(list[mid], list[first]);
  if(list[mid] >= list[last])
    swap(list[mid], list[last]);
  if(list[first] >= list[last])
    swap(list[first], list[last]);
  //*****************************************
  // sorting
  int p = list[first], j = last + 1, i = first - 1;
  while(list[i] < p && list[j] > p){
    i++, j--;
    if(i >= j)
      return j;
    swap(list[i], list[j]);
  }
}
//************************************************************************************
void quicksort(vector<int>& list, int first, int last){
  if(first < last){
    int t = partition(list, first, last);
    quicksort(list, first, t - 1);
    quicksort(list, t + 1, last);
  }
}
//************************************************************************************
void multiway_merge(vector<vector<int> >& input_lists, vector<int>& output_list){
  int listsize = input_lists.size(), firstelement = input_lists[0].size();
  priority_queue<int, vector<int>, greater<int> > MinHeap; // Note: not exactly sure what greater<int> is but thats what was on the link
  for(int i = 0; i < listsize; i++){
    for(int j = 0; j < firstelement; j++){
        MinHeap.push(input_lists[i][j]);
    }
  }
  while(MinHeap.size()){
    output_list.push_back(MinHeap.top());
    MinHeap.pop();
  }

} 
//************************************************************************************
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
    quicksort(input_lists[i], 0, m-1);

  // Merge n input sublists into one sorted list
  vector<int> output_list(n * m);
  multiway_merge(input_lists, output_list);

  for (int i = 0; i < output_list.size(); ++i)
    cout << output_list[i] << " ";
  
  cout << endl;
}
