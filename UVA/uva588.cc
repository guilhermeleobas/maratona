// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=499
// Bellman-ford algorithm

#include <iostream>
#include <vector>
#include <set>
#include <cmath>


using namespace std;

#define INF 0x3f3f3f3f
typedef vector<vector<pair<int, int>>> graph;

bool bellman_ford (const graph& g, int start){
  vector<int> dist(g.size(), INF);
  dist[start] = 0;
  
  // relax edges
  for (int i=0; i<g.size(); i++){
    for (int j=0; j<g.size(); j++){
      int u = j;
      for (auto it : g[j]){
        int v = it.second;
        int cost = it.first;
        
        if (dist[u] + cost < dist[v]){
          dist[v] = dist[u] + cost;
        }
        
      }
    }
  }
  
  // check for negative cycle
  for (int i=0; i<g.size(); i++){
    int u = i;
    for (auto it : g[i]){
      int cost = it.first; 
      int v = it.second;
      
      if (dist[u] + cost < dist[v])
        return false;
    }
  }
  
  return true;
}

int main (){
  
  int t;
  cin >> t;

  while (t--){
    int n, m;
    cin >> n >> m;
    
    graph g(n);
    
    for (int i=0; i<m; i++){
      int u, v, c;
      cin >> u >> v >> c;
      g[u].push_back (make_pair (c, v));
    }
    
    if (bellman_ford (g, 0) == true){
      cout << "not possible\n";
    }
    else{
      cout << "possible\n";
    }
  }
  return 0;
}
