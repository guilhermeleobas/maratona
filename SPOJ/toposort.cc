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
#define MAX 10000 + 10

int d[MAX];
set<int> s;
vector<int> ans;

void dfs (graph &g){
  while (!s.empty()){
    int u = *s.begin();
    s.erase(s.begin());
    
    ans.push_back(u);
    
    for (auto v : g[u]){
      d[v]--;
      if (!d[v])
        s.insert(v);
    }
  }
  
}

bool bfs (graph &g, int u){
  queue<int> q;
  int n = g.size();
  vector<bool> visited(n, false);
  
  visited[u] = true;
  q.push(u);
  
  while (!q.empty()){
    int u = q.front(); q.pop();
    
    for (auto v : g[u]){
      if (visited[v]) return false;
      visited[v] = true;
      q.push(v);
    }
  }
  
  return true;
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  
  int n, m;
  scanf("%d%d", &n, &m);
  
  graph g(n);
  
  for (int i=0; i<m; i++){
    int u, v;
    scanf ("%d%d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    d[v]++;
  }
  
  for (int i=0; i<n; i++){
    if (d[i] == 0){
      s.insert(i);
    }
  }
  
  if (s.size() == 0){
    printf("Sandro fails.\n");
    return 0;
  }
  else{
    dfs (g);
    if (ans.size() != n){
      printf("Sandro fails.\n");
      return 0;
    }
    else {
      printf("%d", ans[0]+1);
      for (int i=1; i<ans.size(); i++)
        printf(" %d", ans[i]+1);
      printf("\n");
    }
  }
  
  
  return 0;
}
