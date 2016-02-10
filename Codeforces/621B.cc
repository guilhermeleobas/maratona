#include <iostream>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main (){
  
  int n, ans = 0;
  
  cin >> n;
  
  map<int, int> r, l;
  
  for (int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    r[x-y]++;
    l[x+y]++;
  }
  
  for (auto i = r.begin(); i != r.end(); i++){
    ans += i->second * (i->second-1) / 2;
  }
  
  for (auto i = l.begin(); i != l.end(); i++){
    ans += i->second * (i->second-1) / 2;
  }
  
  cout << ans << endl;
  
  return 0;
}
