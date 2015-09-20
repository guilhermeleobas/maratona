// http://codeforces.com/problemset/problem/538/B

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int get (int num){
  int aux = 0;
  for (int i=0; i<6; i++){
    if (num & (1 << i)){
      aux += pow (10, i);
    }
  }
  return aux;
}

vector<int> gen (){
  vector<int> v;
  for (int i=0; i<64; i++){
    v.push_back (get(i));
  }
  
  return v;
}

void solver (int n){
  vector<int> qb = gen();
  
  vector<int> dp (n+10, 0x3f3f3f3f), prev (n+10, 0x3f3f3f3f);
  dp[1] = 1;
  dp[0] = 0;
  prev[1] = 0;
  
  for (int i=2; i<n+1; i++){
    for (int j=0; j<qb.size(); j++){
      if (qb[j] > i){
        break;
      }
      
      if (dp[i] > dp[i-qb[j]] + 1){
        dp[i] = dp[i-qb[j]] + 1;
        prev[i] = i-qb[j];
      }
    }
  }
  
  for (int i=0; i<=n; i++){
    cout << i << ' ' << dp[i] << endl;
  }
  cout << endl;
  cout << dp[n] << endl;
  
  while (n > 0){
    int diff = n - prev[n];
    n = prev[n];
    cout << diff << ' ';
  }
  cout << endl;
}

int main (){
  
  gen ();
  int n;
  cin >> n;
  
  solver (n);
   
  return 0;
}
