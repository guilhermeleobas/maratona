
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
  
  double a, b, c;
  
  cin >> a >> b >> c;
  
  double delta = b*b - 4*a*c;
  
  
  if (delta <= 0.0 or a == 0.0){
    cout << "Impossivel calcular" << endl;
  }
  else {
    double R1 = (-b - sqrt(delta))/(2*a);
    double R2 = (-b + sqrt(delta))/(2*a);
    cout << fixed << setprecision(5) << "R1 = " << R2 << endl;
    cout << fixed << setprecision(5) << "R2 = " << R1 << endl;
  }
  
  return 0;
}
