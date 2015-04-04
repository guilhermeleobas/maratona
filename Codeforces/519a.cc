#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main (){
  
  string s;
  map<char, int> m;
  m['Q'] = 9;
  m['q'] = -9;
  m['R'] = 5;
  m['r'] = -5;
  m['B'] = 3;
  m['b'] = -3;
  m['N'] = 3;
  m['n'] = -3;
  m['P'] = 1;
  m['p'] = -1;
  m['K'] = 0;
  m['k'] = 0;
  m['.'] = 0;
  int sum = 0;
  for (int i=0; i<8; i++){
    cin >> s;

    for (int j=0; j<s.size(); j++){
      sum += m[s[j]];
    }
  }
  

  if (sum > 0){
    cout << "White\n";
  }
  else if (sum < 0){
    cout << "Black\n";
  }
  else{
    cout << "Draw\n";
  }
  return 0;
}
