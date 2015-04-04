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

int min (int a, int b){
  if (a < b)
    return a;
  else
    return b;
}

int main (){

	ios::sync_with_stdio(false);
	
	vector<int> pr, ma, pe;
  int n;

  cin >> n;

  for (int i=1; i<=n; i++){
    int aux;
    cin >> aux;
    if (aux == 1){
      pr.push_back (i);
    }
    else if (aux == 2){
      ma.push_back (i);
    }
    else {
      pe.push_back (i);
    }
  }

  int m = min (pr.size(), ma.size());
  m = min (m, pe.size());
  cout << m << endl;
  while (not pr.empty() and not ma.empty() and not pe.empty()){
    cout << pr.back() << ' ' << ma.back() << ' ' << pe.back() << endl;
    pr.pop_back();
    ma.pop_back();
    pe.pop_back();
  }

	return 0;
}
