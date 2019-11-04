#include <iostream>
#include <vector>
// #include <bits/stdc++.h> 

#define INT32_MAX 2147483647

using namespace std;

int isUB(vector<char> S) {
  if(S.size()%2==0) {
    for(int i=0; i<(S.size()/2); ++i) {
      if(S[i]!=S[((S.size()/2) -1) + 1])
        return 1;
    }
    return 0;
  }
  else
    return 1;
}

void display(vector<char> v) {
  for(int o=0; o<v.size(); o++) {
    if(v[o]=='y')
      cout<<"0";
    else if(v[o]=='Y')
      cout<<"1";
  }
    // cout<<v[o];
  cout<<endl;
}

void displayReverse(vector<char> v) {
  for(int o=v.size()-1; o>=0; o--)
    cout<<v[o];
}

int main() {
  int N;
  cin>>N;

  vector<char> A;

  for(int i=0; i<N; i++)
    A.push_back('y');

  int lUb = INT32_MAX;
  vector<char> lubs;

  long long p = 1<<N;

  for(int i=1; i<p; ++i) {
    vector<char> str = A;

    if( __builtin_popcount(i) > 0 ) {
      for(int j=0; j<N; ++j)
        if((i>>j) & 1)
          str[j] = 'Y';

      display(str);
      
      
    }
    else
      continue;
  }

  displayReverse(lubs);

  return 0;
}