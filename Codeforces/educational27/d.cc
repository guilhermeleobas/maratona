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
  
  int overtake = 0;
  int speed = INF;
  int ans = 0;
  
  for (int i=0; i<n; i++){
    int s;
    cin >> s;
    switch (s){
      case 1:
        cin >> speed;
        break;
      case 2:
        if (overtake != 0) ans += overtake;
        overtake = 0;
        break;
      case 3:
        int sp;
        cin >> sp;
        if (speed > sp) ans++;
        break;
      case 4:
        overtake = 0;
        break;
      case 5:
        speed = INF;
        break;
      case 6:
        overtake += 1;
        break;
      default:
        break;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}

