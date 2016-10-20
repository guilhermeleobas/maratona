
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
  
  int n, k;
  cin >> n >> k;
  vector<int> v (n+100, 0);
  
  bool inv = false;
  int num = 1;
  
  while (k > 0){
    cout << num << ' ';
    
    v[num] = true;
    
    if (inv)
      num -= k;
    else
      num += k;
    
    inv = !inv;
    k--;
  }
  
  for (int i=1; i<=n; i++)
    if (v[i] == false)
      cout << i << ' ';
  cout << endl;
  
  
  return 0;
}
