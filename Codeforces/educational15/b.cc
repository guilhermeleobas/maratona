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
  
  vector<ll> p2;
  
  p2.push_back (1);
  p2.push_back (2);
  
  for (int i=0; i<40; i++)
    p2.push_back (p2.back()*2);
  
  map<ll,ll> m;
  
  for (int i=0; i<n; i++){
    int aux;
    cin >> aux;
    m[aux] += 1;
  }
  
  ll s = 0;
  for (auto i: m){
    int elem = i.first, quant = m[elem];
    
    auto it = upper_bound(p2.begin(), p2.end(), elem);
    
    int prox = *it - elem;
    
    // cout << *it << ' ' << elem << ' ' << prox << ' ' << m[prox] << ' ' << m[elem] << endl;
    
    if (*it != elem + prox)
      continue;
    
    if (elem == prox)
      s += (m[elem]*(m[prox]-1))/2;
    else
      s += (m[elem]*m[prox]);
    // if (elem == prox){
    //   cout << "min \n";
    // }
  }
  
  cout << s << endl;
  
  return 0;
}

