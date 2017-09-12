
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
  
  int v[250][250];
  
  int n;
  cin >> n;
  
  set<int> s;
  
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> v[i][j];
  
  for (int i=0; i<2*n; i++){
    int a, b;
    cin >> a >> b;
    s.insert (v[a-1][b-1]);
  }
  
  cout << s.size() << endl;
  
  return 0;
}
