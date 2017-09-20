#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

typedef vector<vector<pair<int, int>>> graph;
#define INF 0x3f3f3f3f
#define MAX 500 + 10

int mt[MAX][MAX];

int dijkstra (graph g, int n, int start, int x){

  set<pair<int,int>> s;
  vector<int> dist (n, INF);
  
  dist[start] = 0;
  s.insert(make_pair (0, start));
  
  while (!s.empty()){
    auto p = *s.begin();
    s.erase(s.begin());
    
    int u = p.second;
    
    for (auto it : g[u]){
      int v = it.second;
      int cost = it.first;
      
      if (mt[u][v] && mt[v][u]){
        cost = 0;
      }
      
      if (dist[v] > dist[u] + cost){
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

void bfs (const graph &g, int start){
  
  queue<int> q;
  
  q.push(start);
  mt[start][start] = true;
  
  while (!q.empty()){
    int u = q.front(); q.pop();
    
    for (auto it : g[u]){
      int v = it.second;
      if (!mt[start][v]){
        mt[start][v] = true;
        q.push(v);
      }
    }
  }

}

void print_mt(int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++)
      cout << mt[i][j] << ' ';
    cout << endl;
  }
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  
  int t = 1;
  
  while (true){
    int n, m;
    cin >> n >> m;
    
    if (n == 0 and m == 0)
      break;
    
    graph g(n);
    
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        mt[i][j] = 0;
    
    for (int i=0; i<m; i++){
      int u, v, c;
      cin >> u >> v >> c;
      u--; v--;
      
      g[u].push_back(make_pair (c, v));
    }
    
    for (int i=0; i<n; i++)
      bfs(g, i);
    
    int k;
    cin >> k;
    
    for (int i=0; i<k; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      
      int ans = dijkstra(g, n, u, v);
      if (ans == INF)
        cout << "Nao e possivel entregar a carta" << endl;
      else
        cout << ans << endl;
    }
    cout << endl;
  }
  
  
  return 0;
}
