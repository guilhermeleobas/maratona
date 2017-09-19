#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1000+10
#define INF 0x3f3f3f3f
typedef vector<vector<int>> graph;

int parent[MAX];
int ranq[MAX];

void build_parent (int n){
  for (int i=0; i<=n; i++){
    parent[i] = i;
    ranq[i] = 1;
  }   
}


int kruskal_find(int u){
  return u == parent[u] ? u : kruskal_find(parent[u]);
}

void kruskal_union(int u, int v){
  if (ranq[u] >= ranq[v]){
    parent[kruskal_find(v)] = kruskal_find(u);
  }
  else{
    parent[kruskal_find(u)] = kruskal_find(v);
  }
  ranq[u] = ranq[v] = ranq[u] + ranq[v];
}

void kruskal(vector<pair<int, pair<int, int>>> &s, int n){
  build_parent(n);
  
  int total = 0;
  int count = 0;
  
  for (auto p : s){
    int cost = p.first;
    int u = p.second.first;
    int v = p.second.second;
    
    if (kruskal_find(u) != kruskal_find(v)){
      kruskal_union(u, v);
      total += cost;
      count++;
    }
  }
  
  if (count+1 != n)
    printf ("impossivel\n");
  else
    printf("%d\n", total);
  
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  int n, m;
  
  while (scanf("%d%d", &n, &m) == 2){
    // graph g (n);
    vector<pair<int, pair<int, int>>> s;
    
    for (int i=0; i<m; i++){
      int a, b, c;
      scanf ("%d%d%d", &a, &b, &c);
      s.push_back(make_pair(c, make_pair (a, b)));
      // g[a-1].push_back(b-1);
      // g[b-1].push_back(a-1);
    }
    
    sort(s.begin(), s.end());
    
    kruskal(s, n);
    
  }

  
  return 0;
}
