// http://br.spoj.com/problems/DESVRUA/

#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

typedef vector<vector<int> > graph;

bool bfs (graph &g, int s){
  queue<int> q;
  vector<int> visited (g.size(), false);
  
  q.push (s);
  visited[s] = true;
  
  while (not q.empty()){
    int tail = q.front();
    q.pop();
    
    visited[tail] = true;
    
    for (int i=0; i<g[tail].size(); i++){
      int head = g[tail][i];
      if (visited[head])
        continue;
      
      q.push (head);
    }
  }
  
  for (int i=0; i<visited.size(); i++)
    if (not visited[i])
      return false;
  
  return true; 
}

class tarjan_bridge {
 private:
  int bridges;
  vector<int> disc, low, parent;
  vector<pair<int, int> > edges;
  int counter;
 public:
  tarjan_bridge (): bridges (0), counter (0)
  {
    //
  }
  
  void dfs (graph g, int tail){
    disc[tail] = low[tail] = counter++;
    
    for (int i=0; i<g[tail].size(); i++){
      int head = g[tail][i];
      if (disc[head] == -1){
        parent[head] = tail;
        dfs (g, head);
        low[tail] = min (low[tail], low[head]);
        
        if (low[head] > disc[tail]){
          edges.push_back (make_pair (tail, head));
          bridges++;
        }
      }
      else  if (head != parent[tail]){
        low[tail] = min (low[tail], disc[head]);
      }
    }
    
  }
  
  vector<pair<int, int> > get_edges (){
    return edges;
  }
  
  int calc_bridges (graph g){
    low.resize (g.size(), -1);
    disc.resize (g.size(), -1);
    parent.resize (g.size(), -1);
    
    for (int i=0; i<parent.size(); i++)
      parent[i] = i;
    
    for (int v=0; v<g.size(); v++)
      if (disc[v] == -1){
        dfs (g, v);
      }
    
    return bridges;
  }
  
  
};

void print (graph g){
  for (int i=0; i<g.size(); i++){
    cout << i << ": ";
    for(int j=0; j<g[i].size(); j++){
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }
}

int main (){
  
  ios::sync_with_stdio (false);
 
  while (true){
    int n, m;
    cin >> n >> m;
    if (not cin)
      break;
    
    graph g (n), r (n), c (n);
    
    // g - original graph
    // r - reverse graph
    // original graph without directions
    
    map<pair<int, int>, int> mapa;
    
    for (int i=0; i<m; i++){
      int a, b, t;
      cin >> a >> b >> t;
      a--, b--;
      
      mapa[make_pair (a, b)] = t;
      
      if (i == 0){
        continue;
      }
      
      c[a].push_back (b);
      c[b].push_back (a);
      g[a].push_back (b);
      r[b].push_back (a);
      if (t == 2){
        g[b].push_back (a);
        r[a].push_back (b);
      } 
    }
    
    tarjan_bridge tb;
    int bridges = tb.calc_bridges (c);
    
    vector<pair<int, int> > edges = tb.get_edges();
    for (int i=0; i<edges.size(); i++){
      if (mapa[edges[i]] == 2){
        bridges--;
      }
    }
    
    int s = 0;
    if (bfs (g, s) and bfs (r, s)){
      cout << "-" << endl;
    }
    else if (not bfs (c, s)){
      cout << "*" << endl;
    }
    else if (bridges == 0){
      cout << "1\n";
    }
    else {
      cout << "2\n";
    }
  }
  
  
  return 0;
}
