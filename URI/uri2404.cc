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
#define cnt PI/180
#define INF 1e10
#define MAX 500+10

int parent[MAX];

void build_parent(int n){
  for (int i=0; i<n; i++){
    parent[i] = i;
  }
}

int Find(int u){
  return u == parent[u] ? u : Find(parent[u]);
}

void Union (int u, int v){
  parent[Find(u)] = Find(v);
}

int kruskal (vector<pair<int, pair<int, int>>> &g, int n){
  build_parent(n);

  double total = 0.0;

  for (auto p : g){
    int u = p.second.first;
    int v = p.second.second;
    double cost = p.first;
  
    if (Find(u) != Find(v)){
      total += cost;
      Union (u, v);
    }
  }

  return total;
}

int main (){
  
  int n, m;
  cin >> n >> m;
  
  vector<pair<int, pair<int, int>>> pairs;

  for (int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;

    pairs.push_back (make_pair(c, make_pair(a, b)));
  }

  sort (begin(pairs), end(pairs));

  cout << kruskal (pairs, n) << endl;



  return 0;
}
