#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string to_string (int n){
  stringstream ss;
  ss << n;
  string s;
  ss >> s;
  return s;
}

bool valid (string input, string k){
  int j = 0;
  for (int i=0; i<input.size(); i++){
    if (input[i] == k[j]){
      j++;
      if (j == k.size())
        return true;
    }
  }

  return false;
}

int main (){
  
  vector<string> v;
  for (int i=0; i<=1000; i++){
    if (i % 8 == 0)
      v.push_back (to_string(i));
  }

  string input;
  cin >> input;

  for (int i=0; i<v.size(); i++){
    if (valid (input, v[i])){
      cout << "YES\n";
      cout << v[i] << endl;
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}
