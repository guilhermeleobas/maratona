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

int main (){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  
  vector<pair<int, int>> v;
  
  for (int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair (a, b));
  }
  
  sort (v.begin(), v.end(), std::less<pair<int, int>>());
  
  int s = 0;
  int a = -1, b = -1;
  
  for (auto p : v){
    if (p.first > a){
      a = p.second;
      s++;
    }
    else if (p.first > b){
      b = p.second;
      s++;
    }
    else
      break;
  }
  
  if (s == n)
    cout << "YES\n";
  else
    cout << "NO\n";
  
  return 0;
}

