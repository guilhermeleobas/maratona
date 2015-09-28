// http://codeforces.com/contest/554/problem/C

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MOD 1000000007

long long binomial (int n, int r, int mod){
  vector< vector<long long> > C(n+1,vector<long long> (r+1,0));
 
  for (int i=0; i<=n; i++){
    for (int k=0; k<=r && k<=i; k++)
      if (k==0 || k==i)
        C[i][k] = 1;
      else
        C[i][k] = (C[i-1][k-1] + C[i-1][k])%mod;
    }
  return C[n][r];
}

long long solver (vector<int> v){
  long long ans = 1;
  int sum = v[0];
  for (int i=1; i<v.size(); i++){
    long long aux = binomial (sum + v[i]-1, v[i]-1, MOD);
    ans = (aux*ans)%MOD;
    ans = (ans + MOD)%MOD;
    sum += v[i];
  }
  
  return ans;
}

int main (){
  
  int n;
  cin >> n;
  
  vector<int> v (n);
  
  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  
  cout << solver (v) << endl;
  return 0;
}
