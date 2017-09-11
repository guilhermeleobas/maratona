#include <bits/stdc++.h>

using namespace std;


typedef pair<int, pair<int, int>> edge;
typedef set<edge> graph;

int mst_find (const vector<int> &parent, int u){
  return u == parent[u] ? u : mst_find(parent, parent[u]);
}

void mst_union (vector<int> &parent, int u, int v){
  parent[mst_find(parent, u)] = mst_find(parent, v);
}

int kruskal(const graph &g, int n){

  vector<int> parent (n);
  int ans = 0;

  for (int i=0; i<n; i++)
    parent[i] = i;

  for (auto p : g){
    int cost = p.first;
    int u = p.second.first;
    int v = p.second.second;

    if (mst_find(parent, u) != mst_find(parent, v)){
      ans += cost;
      mst_union(parent, u, v);
    }
  }
  return ans;
}

int main (){

  int n, m;

  while (true){
    cin >> n >> m;
    if (n == 0 and m == 0)
      break;

    graph g;

    int total = 0;

    for (int i=0; i<m; i++){
      int a, b, c;
      cin >> a >> b >> c;

      g.insert(make_pair (c, make_pair (a, b)));
      g.insert(make_pair (c, make_pair (b, a)));
      total += c;
    }
    
    cout << kruskal(g, n) << endl;
  }

  return 0;
}
