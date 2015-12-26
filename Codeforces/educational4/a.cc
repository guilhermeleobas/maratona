#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

pair<int, int> solver (int n, int p, int q){
  for (int i=0; i<100; i++){
    for (int j=0; j<100; j++){
      if (p*i + q*j == n){
        return make_pair (i, j);
      }
    }
  }
  
  return make_pair (-1, -1);
}

void print (string s, int p, int q, int a, int b){
  for (int i=0; i<a; i++){
    for(int j=0; j<p; j++){
      cout << s[i*p + j];
    }
    cout << endl;
  }
  
  for (int i=0; i<b; i++){
    for (int j=0; j<q; j++){
      cout << s[a*p + i*q + j];
    }
    cout << endl;
  }
}

int main (){

  int n, p, q;
  cin >> n >> p >> q;
  string s;
  cin >> s;
  
  pair<int, int> par = solver (n, p, q);
  if (par.first == -1 and par.second == -1){
    cout << "-1" << endl;
  }
  else {
    cout << par.first + par.second << endl;
    print (s, p, q, par.first, par.second);
  }
  return 0;
}
