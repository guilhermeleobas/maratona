#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

typedef vector<vector<int> > graph;

vector<int> bfs (const graph& g){
  int n = g.size();
  vector<int> visited(n, 0);
  vector<int> dist (n, 0x3f3f3f3f);
  queue<pair<int, int> > q;
  dist[0] = 0;
  visited[0] = true;
  
  q.push (make_pair (0, 0));
  
  while (not q.empty()){
    pair<int, int> atual = q.front();
    q.pop();
    
    visited[atual.first] = true;
    int node = atual.first;
    
    for (int i=0; i<g[node].size(); i++){
      int next = g[node][i];
      if (visited[next]) continue;
      
      if (dist[node] + 1 < dist[next]){
        dist[next] = dist[node] + 1;
        q.push (make_pair (next, dist[next]));
      }
    }
  }
  
  
  return dist;
}

vector<int> bfs_t (const graph& t, const vector<int> dist_other){
  int n = t.size();
  vector<int> visited(n, 0);
  vector<int> dist (n, 0x3f3f3f3f);
  queue<pair<int, int> > q;
  dist[0] = 0;
  visited[0] = true;
  
  q.push (make_pair (0, 0));
  
  while (not q.empty()){
    pair<int, int> atual = q.front();
    q.pop();
    
    visited[atual.first] = true;
    int node = atual.first;
    
    for (int i=0; i<t[node].size(); i++){
      int next = t[node][i];
      if (visited[next]) continue;
      
      if (dist[node] + 1 == dist_other[next]) continue;
        
      if (dist[node] + 1 <dist[next]){
        dist[next] = dist[node] + 1;
        q.push (make_pair (next, dist[next]));
      }
    }
  }
  
  return dist; 
}

void print (graph g){
  for (int i=0; i<g.size(); i++){
    cout << i << ": ";
    for (int j=0; j<g[i].size(); j++){
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }
}

int main (){
  
  int n, m;
  
  cin >> n >> m;
  
  graph g(n), t(n);
  graph c(n, vector<int> (n));
  
  for (int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    u--, v--;
    c[u][v] = 1;
    c[v][u] = 1;
  }
  
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (i == j) continue;
      if (c[i][j] == 1){
        g[i].push_back (j);
      }
      else {
        t[i].push_back (j);
      }
    }
  }
  
  vector<int> distA = bfs (g);
  vector<int> distB = bfs_t (t, distA);
  
  if (max (distA.back(), distB.back()) == 0x3f3f3f3f){
    cout << "-1" << endl;
  }
  else 
    cout << max (distA.back(), distB.back()) << endl;
  
  
  
  return 0;
}
