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
#define INF 0x3f3f3f3f
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

int max (int a, int b){
  if (a == INF)
    return b;
  if (b == INF)
    return a;
  return a > b ? a : b;
}

int dijkstra (graph &g, int n, int x, int y){

  set<pair<int, int>> s;
  vector<int> dist(n, INF);
  vector<int> h(n, INF);
  
  dist[x] = 0;
  h[x] = INF;
  s.insert(make_pair(0, x));
  
  // cout << "comecou " << x << endl;
  
  if (x == y)
    return 0;
  
  while (!s.empty()){
    auto p = *s.begin(); s.erase(s.begin());
    
    int u = p.second;
    
    if (u == y) break;
    
    for (auto it : g[u]){
      int v = it.second;
      int cost = it.first;
      
      // if (dist[u] + cost < dist[v]){
      //   dist[v] = dist[u] + cost;
      //   s.insert (make_pair (dist[v], v));
      //   h[v] = max(h[u], cost);
      // }
      
      if (h[v] > max(h[u], cost)){
        h[v] = min(h[v], max(h[u], cost));
        s.insert(make_pair(h[v], v));
      }
    }
  }
  
  return h[y]; 
}
 
void print (graph &g){
  for (int i=0; i<g.size(); i++){
    cout << i+1 << ": ";
    for (int j=0; j<g[i].size(); j++){
      cout << g[i][j].second+1 << ' ';
    }
    cout << endl;
  }
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  
  int t = 1;
  
  while (true){

    int n, m;
    cin >> n >> m;
    if (n == 0 and m == 0) break;
    
    // vector<vector<int>> g(n, vector<int>(n, INF));
    // vector<vector<int>> h(n, vector<int>(n, INF));
    
    graph g(n);
    
    for (int i=0; i<m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      
      g[a].push_back (make_pair (c, b));
      g[b].push_back (make_pair (c, a));
      
      // g[a][b] = g[b][a] = c;
    }
    
    // print(g);
    
    cout << "Instancia " << t++ << endl;
    
    int k;
    cin >> k;
    for (int i=0; i<k; i++){
      int u, v;
      cin >> u >> v;
      cout << dijkstra(g, n, u-1, v-1) << endl;
    }
    cout << endl;
    
    // for (int k=0; k<n; k++){
    //   for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //       if (g[i][j] > g[i][k] + g[k][j]){
    //         g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    //         h[i][j] = 
    //       }
    //     }
    //   }
    // }
  }


  return 0;
}
