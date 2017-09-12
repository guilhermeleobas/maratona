
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
  int caso = 1;
  
  for (int i=0; i<n; i++){
    string pokemon;
    int l;
    cin >> pokemon >> l;
    
    int bs, iv;
    float ev, aux;
    
    
    cout << "Caso #" << caso++ << ": " << pokemon << " nivel " << l << endl;
    
    cin >> bs >> iv >> ev;
    aux = sqrt(ev)/8;
    cout << "HP: " << int( ( ( iv + bs + aux + 50 ) * l)/50 + 10) << endl;
    
    cin >> bs >> iv >> ev;
    aux = sqrt(ev)/8;
    cout << "AT: " << int( ( ( iv + bs + aux ) * l)/50 + 5) << endl;
    
    cin >> bs >> iv >> ev;
    aux = sqrt(ev)/8;
    cout << "DF: " << int(( ( iv + bs + aux ) * l)/50 + 5) << endl;
    
    cin >> bs >> iv >> ev;
    aux = sqrt(ev)/8;
    cout << "SP: " << int(( ( iv + bs + aux ) * l)/50 + 5) << endl;
  }
  
  return 0;
}

