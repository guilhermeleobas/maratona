// http://www.spoj.com/problems/ABCDEF/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

// a*b+c = d*(e+f)
// gen1 => a*b + c
map<int, int> gen1(const vector<int> &v){
  map<int, int> mapa;
  
  for (auto a: v){
    for (auto b: v){
      for (auto c: v){
        mapa[a*b + c] += 1;
      }
    }
  }
  
  return mapa;
}

// d*(e+f)
// don't use a second map/unordered_map here
// use a vector and get the intervals using upper_bound - lower_bound
vector<int> gen2(const vector<int> &v){
  vector<int> s;
  
  for (auto d: v){
    for (auto e: v){
      for (auto f: v){
        if (d == 0)
          continue;
        s.push_back (d*(e+f));
      }
    }
  }
  
  return s;
}

int main (){
  
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  
  map<int, int> mapa1 = gen1(v);
  vector<int> v2 = gen2(v);
  
  sort(begin(v2), end(v2));
  
  long long ans = 0;
  for (auto i: mapa1){
    int lb = lower_bound(begin(v2), end(v2), i.first) - begin(v2);
    int ub = upper_bound(begin(v2), end(v2), i.first) - begin(v2);
    ans += i.second*(ub-lb);
  }
  
  cout << ans << endl;
  
  
  return 0;
}
