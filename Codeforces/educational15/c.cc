#include <algorithm>
#include <cmath>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<vector<int> > graph;

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

int main (){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  vector<ll> cities(n);
  vector<ll> towers(m);
  
  for (int i=0; i<n; i++){
    cin >> cities[i];
  }
  
  for (int i=0; i<m; i++){
    cin >> towers[i];
  }
  
  ll ans = 0;
  
  for (int i=0; i<n; i++){
    ll dcity = cities[i];
    
    auto it = lower_bound (towers.begin(), towers.end(), dcity)-towers.begin();
    
    if (it == towers.size())
      it--;
    ll l = towers[it];
    ll r = l;
   
    if (it-1 >= 0){
      l = towers[it-1];
    }
    
    
    ans = max (ans, min (
          abs (dcity-l),
          abs (dcity-r)
          ));
    
  }
  
  cout << ans << endl;
  return 0;
}

