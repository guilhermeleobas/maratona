// kosaraju
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
#include <stack>

using namespace std;

typedef vector<vector<int>> graph;
#define INF 0x3f3f3f3f
#define MAX 100 + 10

stack<int> s;
int visited[MAX];
int scc[MAX];

void dfs (graph &g, int u){
  visited[u] = true;
  for (auto v : g[u]){
    if (!visited[v])
      dfs (g, v);
  }
  s.push(u);
}

void dfs2 (graph &r, int u){
  visited[u] = true;
  for (auto v : r[u]){
    if (!visited[v]){
      scc[v] = scc[u];
      dfs2(r, v);
    }
  }
}

void kosaraju (graph &g, graph &r){
  for (int i=0; i<g.size(); i++)
    visited[i] = 0;
  
  for (int u=0; u<g.size(); u++)
    if (!visited[u])
      dfs(g, u);
  
  for (int i=0; i<g.size(); i++)
    visited[i] = 0;

  while (!s.empty()){
    int u = s.top(); s.pop();
    if (!visited[u]){
      scc[u] = u;
      dfs2 (r, u);
    }
  }
}


int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  
  int t;
  cin >> t;
  int c = 1;
  while (t--){
    int n, m;
    cin >> n >> m;
    
    graph g(n);
    
    for (int i=0; i<m; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      
      g[u].push_back (v);
      g[v].push_back(u);
    }
    
    kosaraju (g, g);
    
    cout << "Caso #" << c++ << ": ";
    
    set<int> s;
    for (int i=0; i<n; i++)
      s.insert (scc[i]);
    
    if (s.size() == 1)
      cout << "a promessa foi cumprida\n";
    else
      cout << "ainda falta(m) " << s.size()-1 << " estrada(s)\n";
    
  }
  
  
  return 0;
}
