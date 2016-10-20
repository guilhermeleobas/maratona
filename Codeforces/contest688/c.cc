#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<int> > graph;

vector<int> visited;
vector<int> parent;

int bfs (const graph& g, int start, int p){
  // cout << "chamou bfs com start: " << start << endl;
  queue<int> q;
  
  q.push(start);
  visited[start] = p;
  while (not q.empty()){
    int v = q.front();
    q.pop();
    p = visited[v];
    
    // cout << "v: " << v+1 << endl;
    // cout << "p: " << p <<endl;
    
    for (int i=0; i<g[v].size(); i++){
      int u = g[v][i];
      // cout << "u: " << u+1 << " visited[u]: " << visited[u] << endl; 
      if (visited[u] != -1){
        // cout << visited[u] << ' ' << p << endl;
        if (visited[u] == p){
          return -1;
        }
        else if (visited[u] != p)
          continue;
      }
      
      parent[u] = v;
      
      if (visited[u] == -1)
        q.push(u);
      if (p == 1)
        visited[u] = 2;
      else
        visited[u] = 1;
      
      
    }
  }
  return 0;
}

int main (){
  
  int n, m;
  cin >> n >> m;
  graph g (n);
  visited.resize(n, -1);
  parent.resize(n, 0);
  for (int i=0; i<n; i++)
    parent[i] = i;
  
  for (int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back (v);
    g[v].push_back (u);
  }
  
  for (int i=0; i<n; i++){
    if (g[i].size() > 0 and visited[i] == -1 ){
      int status = bfs(g, i, 1);
      if (status == -1){
        cout << "-1\n";
        return 0;
      }
    }
  }
  
  // int status = bfs(g, 0, 1);
  // if (status == -1){
  //   cout << "-1\n";
  //   return 0;
  // }
  
  vector<int> first, second;
  for (int i=0; i<visited.size(); i++){
    if (visited[i] == 1)
      first.push_back(i);
    else if (visited[i] == 2)
      second.push_back(i);
  }
 
  cout << first.size() << endl;
  for (int i=0; i<first.size(); i++){
    cout << first[i]+1 << ' ';
  }
  cout << endl;
  
  cout << second.size() << endl;
  for (int i=0; i<second.size(); i++){
    cout << second[i]+1 << ' ';
  }
  cout << endl;
  
  return 0;
}
