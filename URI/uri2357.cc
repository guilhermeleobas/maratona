#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef vector<vector<int> > graph;

vector<int> visited;
vector<int> parent;

bool has_cycle(const graph& g, int start){
  stack<int> s;
  
  s.push(start);
  
  while (!s.empty()){
    int t = s.top();
    s.pop();
    
    if (visited[t])
      continue;
    
    visited[t] = true;
    
    for (int i=0; i<g[t].size(); i++){
      int prox = g[t][i];
      
      if (parent[t] == prox)
        continue;
      
      if (visited[prox])
        return true;
      
      
      if (parent[prox] == t)
        return true;
      
      parent[prox] = t;
      s.push(prox);
    }
    
  }
  
  return false;
}

int main (){
  
  while (true){
    int n, m;
    cin >> n >> m;
    
    if (not cin) 
      break;
    
    graph g(n);
    
    bool invalid = false;
    
    for (int i=0; i<m; i++){
      int u, v;
      cin >> u >> v;
      
      if (u == v)
        invalid = true;
      
      g[u-1].push_back(v-1);
      g[v-1].push_back(u-1);
    }
    
    visited.clear();
    visited.resize(g.size(), 0);
    parent.clear();
    parent.resize(g.size(), 0);
    
    
    for (int i=0; i<n; i++)
      parent[i] = i;
    
    for (int i=0; i<g.size(); i++){
      if (!visited[i])
        invalid |= has_cycle(g, i);
      
      if (invalid)
        break;
    }
    
    if (invalid)
      cout << "Inseguro\n";
    else
      cout << "Seguro\n";
  }
  
  return 0;
}
