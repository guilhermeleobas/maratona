#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iterator>

using namespace std;

#define PI acos(-1)
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	
  int n;
  cin >> n;
  multiset<int> s;

  for (int i=0; i<n; i++){
    int aux;
    cin >> aux;
    s.insert (aux);
  }
  
  multiset<int> ss;
  for (int i=0; i<n-1; i++){
    int aux;
    cin >> aux;
    ss.insert (aux);
    auto it = s.find (aux);
    s.erase (it);
  }

  cout << *s.begin() << endl;
  
  s.clear();

  for (int i=0; i<n-2; i++){
    int aux;
    cin >> aux;
    auto it = ss.find (aux);
    ss.erase (it);
  }

  cout << *ss.begin() << endl;
	
	return 0;
}
