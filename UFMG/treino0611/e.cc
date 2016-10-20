#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main (){
  
  int t;
  cin >> t;
  
  while (t--){
    int n;
    cin >> n;
    vector<int> v (n);
    
    for (int i=0; i<n; i++) cin >> v[i];
    
    int ans = 0;
    
    sort (v.begin(), v.end());
    
    int j = 1;
    for (int i=0; i<n; i++){
      while (j < n and v[j] - v[i] < 32){
        j++;
      }
      ans += j-i-1;
    }
    cout << ans << endl;
  }
  
  return 0;
}
