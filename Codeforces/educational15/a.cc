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
  
  vector<int> v (n);
  
  for (int i=0; i<n; i++)
    cin >> v[i];
  
  int s = 1, aux = 1;
  
  for (int i=1; i<n; i++){
    if (v[i] > v[i-1]){
      aux += 1;
      s = max(s, aux);
    }
    else {
      aux = 1;
    }
  }
  
  cout << s << endl;
  
  return 0;
}

