#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef vector<vector<pair<int, int>>> graph;
#define INF 0x3f3f3f3f

int dijkstra (graph g, int n, int x){

  set<pair<int,int>> s;
  vector<int> dist (n, INF);
  
  dist[0] = 0;
  s.insert(make_pair (0, 0));
  
  while (!s.empty()){
    auto p = *s.begin();
    s.erase(s.begin());
    
    int u = p.second;
    
    for (auto it : g[u]){
      int v = it.second;
      int cost = it.first;
      
      if (dist[v] >= dist[u] + cost){
        dist[v] = dist[u] + cost;
        s.insert(make_pair (dist[v], v));
      }
    }
  }
  
  return dist[x];
}

void print (const graph &g){
  for (int i=0; i<g.size(); i++){
    cout << i+1 << ": ";
    for (int j=0; j<g[i].size(); j++){
      cout << g[i][j].second+1 << "(" << g[i][j].first <<  ") ";
    }
    cout << endl;
  }
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  
  
  graph g(n);
  
  for (int i=0; i<m; i++){
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    
    g[u].push_back(make_pair (c, v));
    g[v].push_back(make_pair (c, u));
  }
  
  graph gg(n);
  
  for (int i=0; i<n; i++){
    int u = i;
    for (int j=0; j<g[i].size(); j++){
      int c1 = g[i][j].first;
      int v = g[i][j].second;
      for (int k=0; k<g[v].size(); k++){
        int c2 = g[v][k].first;
        int w = g[v][k].second;
        
        gg[u].push_back(make_pair (c1+c2, w));
        gg[w].push_back(make_pair (c1+c2, u));
      }
    }
  }
  
  int ans = dijkstra(gg, n, n-1);
  if (ans == INF)
    cout << "-1\n";
  else
    cout << ans << endl;

  return 0;
}
