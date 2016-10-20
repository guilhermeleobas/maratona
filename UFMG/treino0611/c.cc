#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main (){
  int t;
  cin >> t;
  
  while (t--){
    int k, m, n;
    cin >> k >> m >> n;
    
    vector<int> v (n);
    int sum = 0;
    for (int i=0; i<n; i++){
      cin >> v[i];
      sum += v[i];
    }
    
    sort (v.begin(), v.end());
    
    m -= (k-sum);
    
    int ans = 0;
    int j = v.size()-1;
    while (m > 0){
      ans++;
      m -= v[j--];
    }
    
    cout << ans << endl;
    
  }
  
  
  return 0;
}
