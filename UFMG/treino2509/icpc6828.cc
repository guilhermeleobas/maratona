#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main (){
  
  while (true){
    int n;
    cin >> n;
    if (not cin) break;
    
    vector<int> v (n);
    for (int i=0; i<n; i++)
      cin >> v[i];
    
    sort (v.begin(), v.end());
    
    int x = min (abs(v[0]-v[1]), 24-(abs(v[0]-v[1])));
    
    for (int i=2; i<n; i+=2){
      x += min (abs(v[i]-v[i+1]), 24-(abs(v[i]-v[i+1])));
    }
    
    int ans = x;
    
    x = min (abs(v[0]-v[n-1]), 24-(abs(v[0]-v[n-1])));
    
    for(int i=1; i<n-1; i+=2){
      x += min (abs(v[i]-v[i+1]), 24-(abs(v[i]-v[i+1])));
    }
    
    cout << min (x, ans) << endl;
  }
  return 0;
}
