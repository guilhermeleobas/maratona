#include <iostream>
#include <cmath>
#include "bits/stdc++.h"
using namespace std;

long long lcm (long long a, long long b){
  return (a*b)/__gcd(a,b);
}

int main (){
  
  long long n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  
  long long ans = 0;
  
  long long aa = (n/a);
  long long bb = (n/b);
  long long eq = (n/lcm(a, b));
  
  aa -= eq;
  bb -= eq;
  
  ans += (aa*p);
  ans += (bb*q);
  ans += (eq*max(p, q));
  cout << ans << endl;
  return 0;
}
