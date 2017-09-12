#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main (){
  
  int s, n;
  
  cin >> s >> n;
  
  vector<pair<int, int> > p;
  
  for ( int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    
    p.push_back (make_pair (x, y));
    
  }
  
  sort (p.begin(), p.end());
  
  for (int i=0; i<n; i++){
    
    int x = p[i].first, y = p[i].second;
    
    if (s <= x){
      cout << "NO\n";
      return 0;
    }
    
    s += y;
  }
  
  cout << "YES\n";
  
  return 0;
}
