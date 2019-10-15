#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <cctype>  

using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

/**
 * Basic program to extract ints from string
 * when number of inputs is not known.
*/

int main() {
  // Number of test cases
  int N;
  cin>>N;

  string t_P; // Inputs in a string
  vector<string> tt_P; // Splitted inputs

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, t_P);
  
  tt_P = split_string(t_P);
  
  vector<int> P; // Inputs
  // Converting splitted inputs to ints
  for(int i=0; i<tt_P.size(); i++)
    P.push_back(stoi(tt_P[i]));

  // 
  // TODO: Program logic
  // 
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
    return x == y && x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}