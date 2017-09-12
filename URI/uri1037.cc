
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
  
  double a;
  cin >> a;
  
  if (a < 0.0){
    cout << "Fora de intervalo" << endl;
  }
  else if (a <= 25.0){
    cout << "Intervalo [0,25]" << endl;
  }
  else if (a <= 50.0){
    cout << "Intervalo (25,50]" << endl;
  }
  else if (a <= 75.0){
    cout << "Intervalo (50,75]" << endl;
  }
  else if (a <= 100.0){
    cout << "Intervalo (75,100]" << endl;
  }
  else {
    cout << "Fora de intervalo" << endl;
  }
  return 0;
}
