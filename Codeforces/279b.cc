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

int getnum (map<int, vector<int> > &mapa){
  map<int, vector<int> >::iterator it;

  for (it = mapa.begin(); it != mapa.end(); it++){
    if (it->second[1] == -1)
      return it->first;
  }
}

void solver (map<int, vector<int> > &mapa, vector<pair<int, int> > &v){
  vector<int> ans (mapa.size() + 1, 0);
  int pos = mapa[0][0];
  int next = v[pos].second;
  int i = 2;
  while (true){
    if (next == 0)
      break;
    ans[i] = next;
    pos = mapa[next][0];
    next = v[pos].second;
    i += 2;
  }

  if (v.size() % 2 == 0){
    i -= 3;
    pos = mapa[0][1];
    next = v[pos].first;
    while (true){
      ans[i] = next;
      pos = mapa[next][1];
      next = v[pos].first;
      if (pos == -1)
        break;
      i -= 2;
    }
  }
  else {
    next = getnum (mapa);
    i = 1;

    while (true){
      ans[i] = next;
      pos = mapa[next][0];
      next = v[pos].second;
      if (pos == -1)
        break;
      i += 2;
    }
  }

  for (int i=1; i<ans.size()-1; i++)
    cout << ans[i] << ' ';
  cout << endl;
}

int main (){

	ios::sync_with_stdio(false);
	
	map<int, vector<int> > mapa;
  vector<pair<int, int> > v;
  int n;

  cin >> n;

  for (int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    mapa[a].push_back (-1);
    mapa[a].push_back (-1);
    mapa[b].push_back (-1);
    mapa[b].push_back (-1);
    v.push_back (make_pair (a, b));
  }
  
  for (int i=0; i<n; i++){
    int a = v[i].first, b = v[i].second;
    mapa[a][0] = i;
    mapa[b][1] = i;
  }

  solver (mapa, v);

	return 0;
}
