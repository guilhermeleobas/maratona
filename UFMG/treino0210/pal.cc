#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int M[2001][2001];
int C[2001];

inline bool check (const string &s, int i, int j){
  while (i < j){
    if (i == j) break;
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  
  return true;
}

void build_M (const string &s){
  for (int i=0; i<s.size(); i++){
    for (int j=i; j<s.size(); j++){
      if (i == j){
        M[i][j] = 1;
        continue;
      }
      if (check(s, i, j)){
        M[i][j] = 1;
      }
      else {
        M[i][j] = 0;
      }
    } 
  }
}

void build_C(int len){
  memset (C, -1, sizeof(int)*len);
  C[0] = 1;
  
  for (int i=0; i<len; i++){
    if (M[0][i] == 1){
      C[i] = 1;
      continue;
    }
    for (int k=0; k<i; k++){
      if (M[k+1][i] and (C[i] == -1 or C[i] > C[k]+1))
        C[i] = C[k] + 1;
    }
  }
  
}

int main (){
  ios::sync_with_stdio(false);
  int n, t = 1;
  while (true){
    cin >> n;
    if (n == 0) break;
    
    string s;
    cin >> s;
    
    build_M(s);
    build_C(s.size());
    
    printf ("Teste %d\n", t++);
    printf ("%d\n\n", C[s.size()-1]);
  }
  return 0;
}
