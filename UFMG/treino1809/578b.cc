#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long exp (int a, int e){
  long long ans = 1;
  for (int i=0; i<e; i++)
    ans *= a;
  return ans;
}

int main (){
  
  int n, k, x;
  cin >> n >> k >> x;
  
  vector<int> v (n);
  
  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  
  if (n == 1){
    cout << v[0] * exp (x, k) << endl;
    return 0;
  }
  
  vector<int> prefix (n), suffix (n);
  
  prefix[0] = v[0];
  for (int i=1; i<n; i++)
    prefix[i] |= v[i] | prefix[i-1];
  
  suffix[n-1] = v[n-1];
  for (int i=n-2; i>=0; i--)
    suffix[i] |= v[i] | suffix[i+1];
   
  long long ans = 0;
  for (int i=0; i<n; i++){
    long long aux = v[i] * exp (x, k);
    //cout << "aux: " << aux << endl;
    if (i == 0 and n > 1){
      aux |= suffix[i+1];
    }
    else if (i == n-1 and n > 1){
      aux |= prefix[i-1];
    }
    else {
      aux = aux | suffix[i+1] | prefix[i-1];
    }
    ans = max (ans, aux);
  }
  
  cout << ans << endl;
  
  return 0;
}
