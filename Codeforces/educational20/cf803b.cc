#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  
  int n;
  cin >> n;
  int v[1000000];
  int k[1000000];
  
  memset (k, 0x3f3f3f3f, sizeof(int)*(n+10));
  
  
  for (int i=0; i<n; i++){
    cin >> v[i];
    if (v[i] == 0)
      k[i] = 0;
  }
  
  for (int i=1; i<n; i++)
    if (v[i] == 0)
      k[i] = 0;
    else
      k[i] = k[i-1] + 1;
  
  for (int i=n-2; i>=0; i--)
    if (v[i] == 0)
      k[i] = 0;
    else
      k[i] = min(k[i+1]+1, k[i]);
  
  for (int i=0; i<n; i++)
    cout << k[i] << ' ';
  cout << endl;
  
  
  return 0;
}
