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
  vector<int> v (n, 0);
	vector<pair<int, int> > p;
  for (int i=0; i<n; i++)
    cin >> v[i];

  for (int i=0; i<v.size(); i++){
    bool trocou = false;
    int m = i;
    for (int j=i; j<v.size(); j++){
      if (v[m] > v[j]){
        m = j;
        trocou = true;
      }
    }

    if (trocou){
      p.push_back (make_pair (i, m));
      swap (v[i], v[m]);
    }
  }

  cout << p.size() << endl;
  for (int i=0; i<p.size(); i++)
    cout << p[i].first << ' ' << p[i].second << endl;

	return 0;
}
