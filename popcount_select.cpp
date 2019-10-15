#include <iostream>
using namespace std;

int main(){
  // Number of available objects
  long long n;
  
  // 2^n
  long long p = 1<<n;
  
  

  for(int i=1; i<p; ++i){
    // Number of objects selected
    int z=__builtin_popcount(i);

    // How many objects should be selected at least
    if(z<2)
      continue;
    
    for(int j=0; j<n; ++j)
      if((i>>j) & 1){
        // TODO when j-th object is selected
      }
  }

  return 0;
}