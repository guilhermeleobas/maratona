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
  
  if (t == 1)
    cout << "Top 1" << endl;
  else if (t <= 3)
    cout << "Top 3" << endl;
  else if (t <= 5)
    cout << "Top 5" << endl;
  else if (t <= 10)
    cout << "Top 10" << endl;
  else if (t <= 25)
    cout << "Top 25" << endl;
  else if (t <= 50)
    cout << "Top 50" << endl;
  else
    cout << "Top 100" << endl;

  return 0;
}
