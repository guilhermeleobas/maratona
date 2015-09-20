// http://codeforces.com/problemset/problem/538/A

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check (string s, int i, int j){
  string cf = "CODEFORCES";
  
  s.erase (i, j-i+1);
  
  if (s == "CODEFORCES")
    return true;
  else
    return false;
}

bool solver (string s){
  string cf = "CODEFORCES";
  
  for (int i=0; i<s.size(); i++){
    for (int j=0; j<s.size(); j++){
      if (check (s, i, j))
        return true;
    }
  }
  return false;
}

int main (){

  string s;
  
  cin >> s;
  
  if (solver (s))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
