// http://www.spoj.com/problems/HISTOGRA/

#include <algorithm>
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

ll solve (const vector<ll> &v){
  stack<ll> s;
  int i = 0;
  int n = v.size();
  ll ans = -1;
  while (i < n){
    if (s.empty() || v[i] >= v[s.top()])
      s.push(i++);
    else {
      ll x = s.top(); s.pop();

      ll area = v[x] * (s.empty() ? i : i - s.top() - 1);
      ans = max (area, ans);
    }
  }

  while (not s.empty()){
    ll x = s.top(); s.pop();
    ll area = v[x] * (s.empty() ? i : i - s.top() - 1);
    ans = max (area, ans);
  }

  return ans;
}

int main (){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  while (true){
    int n;
    cin >> n;

    if (n == 0)
      break;

    vector<ll> v (n);
    for (int i=0; i<n; i++)
      cin >> v[i];

    cout << solve(v) << endl;
  }

  return 0;
}
