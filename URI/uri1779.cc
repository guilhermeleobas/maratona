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
  
  int t;
  cin >> t;
  
  int caso = 1;
  
  while (t--){
    int n;
    cin >> n;
    
    int v[100000];
    int maximo = v[0];
    
    for (int i=0; i<n; i++){
      cin >> v[i];
      if (i == 0) maximo = v[0];
      if (maximo < v[i]) maximo = v[i];
    }
    
    int ans = 0;
    int x = 0;
    
    for (int i=0; i<n; i++){
      if (v[i] != maximo) x = 0;
      else {
        x++;
        ans = max (ans, x);
      }
    }
      
    cout << "Caso #" << caso++ << ": " << ans << endl;
  } 
  
  return 0;
}
