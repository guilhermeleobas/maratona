
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
  
  int n, c;
  cin >> n >> c;
  
  cout << "Total: R$ ";
  if (n == 1){
    cout << fixed << setprecision(2) << 4.0*c << endl;
  }
  else if (n == 2){
    cout << fixed << setprecision(2) << 4.5*c << endl;
  }
  else if (n == 3){
    cout << fixed << setprecision(2) << 5.0*c << endl;
  }
  else if (n == 4){
    cout << fixed << setprecision(2) << 2.0*c << endl;
  }
  else {
    cout << fixed << setprecision(2) << 1.5*c << endl;
  }
  return 0;
}
