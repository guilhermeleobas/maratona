#include <algorithm>
#include <bitset>
#include <cmath>
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

ll max (ll x, ll y){
  if (x > y)
    return x;
  else
    return y;
}

bool check (ll num, ll c1, ll c2, ll x, ll y){
  ll both = num/(x*y);
  
  ll xx = num/y - both;
  ll yy = num/x - both;
  
  // cout << num/y << ' ' << num/x << ' ' << both << endl;
  // cout << max(c1-xx, 0) << ' ' << max(c2-y, 0) << endl;
  // cout << endl;
  // cout << "xx: " << xx << endl;
  // cout << "yy: " << yy << endl;
  // cout << "c1-xx: " << c1-xx << endl;
  // cout << "c2-yy: " << c2-yy << endl;
  //
  // num = num - both - num/x - num/y;

  ll left = max(0, c1-xx) + max(0, c2-yy);

  return (num - xx - yy - both) >= left; 
  
}

int bsearch (ll c1, ll c2, ll x, ll y){
  
  ll left = 1;
  ll right = 10000000000000 + 1;
  
  while (right > left){
    ll mid = (left+right)/2;
    
    // cout << left << ' ' << mid << ' ' << right << endl;
    
    if (check (mid, c1, c2, x, y)){
        right = mid;
    }
    else {
      left = mid+1;
    }
  }
  
  // cout << check (left, c1, c2, x, y) << endl;
  
  return left;
}


int main (){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
  
  ll c1, c2, x, y;
  
  cin >> c1 >> c2 >> x >> y;
  
  cout << bsearch (c1, c2, x, y) << endl;
  
  // for (int i=0; i<10; i++){
  //   cout << i << ' ' << x << ' ' << y << ' ' << check(i, c1, c2, x, y) << endl;
  //   cout << endl;
  // }
  
  return 0;
}
