#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr;
  // Input

  // Number of available objects
  long long n = arr.size();
  
  // 2^n
  long long p = 1<<n;
  
  int k;

  for(int i=1; i<p; ++i){
    // Number of objects selected
    int z=__builtin_popcount(i);

    vector<int> sel;

    // How many objects should be selected at least
    if(z==k)
      for(int j=0; j<n; ++j)
        if((i>>j) & 1){
          // TODO when j-th object is selected
          sel.push_back(arr[j]);
        }
    else
      continue;
  }

  return 0;
}