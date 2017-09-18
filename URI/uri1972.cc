#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef vector<vector<pair<int, int>>> graph;
#define INF 0x3f3f3f3f

int convert(vector<vector<char>> &g, int i, int j){
  if (g[i][j] == 'E' || g[i][j] == 'H' || g[i][j] == '.')
    return 0;
  else if (g[i][j] == '#')
    return INF;
  return (int)g[i][j] - '0';
}

int dijkstra (vector<vector<char>> &g, int n, int m, pair<int, int> start){

  set<pair<int,pair<int, int>>> s;
  vector<vector<int>> dist (n, vector<int> (m, INF));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  
  dist[start.first][start.second] = 0;
  s.insert(make_pair (0, start));
  
  while (!s.empty()){
    auto p = *s.begin();
    s.erase(s.begin());
    
    auto u = p.second;
    int i = u.first;
    int j = u.second;
    
    visited[i][j] = true;
    
    // cout << i << ' ' << j << ' ' << g[i][j] << ' ' << dist[i][j] << endl;
    
    if (g[i][j] == 'E')
      return dist[i][j];
    
    if (i+1 < n){
      int cost = convert(g, i+1, j);
      // cout << "in: " << i+1 << ' ' <<  j << ' ' << cost <<  endl;
      if (!visited[i+1][j] && dist[i+1][j] >= dist[i][j] + cost){
        dist[i+1][j] = dist[i][j] + cost;
        s.insert(make_pair (dist[i+1][j], make_pair(i+1, j)) );
      }
      // cout << dist[i+1][j] << endl;
    }
    
    if (i-1 >= 0){
      int cost = convert(g, i-1, j);
      // cout << "in: " << i-1 << ' ' <<  j << ' ' << cost <<  endl;
      if (!visited[i-1][j] && dist[i-1][j] >= dist[i][j] + cost){
        dist[i-1][j] = dist[i][j] + cost;
        s.insert(make_pair (dist[i-1][j], make_pair(i-1, j)) );
      }
      // cout << dist[i-1][j] << endl;
    }
    
    if (j+1 < m){
      int cost = convert(g, i, j+1);
      // cout << "in: " << i << ' ' <<  j+1 << ' ' << cost <<  endl;
      if (!visited[i][j+1] && dist[i][j+1] >= dist[i][j] + cost){
        dist[i][j+1] = dist[i][j] + cost;
        s.insert(make_pair (dist[i][j+1], make_pair(i, j+1)) );
      }
      // cout << dist[i][j+1] << endl;
    }
    
    if (j-1 >= 0){
      int cost = convert(g, i, j-1);
      // cout << "in: " << i << ' ' <<  j-1 << ' ' << cost <<  endl;
      if (!visited[i][j-1] && dist[i][j-1] >= dist[i][j] + cost){
        dist[i][j-1] = dist[i][j] + cost;
        s.insert(make_pair (dist[i][j-1], make_pair(i, j-1)) );
      }
      // cout << dist[i][j-1] << endl;
    }
  }  
  return INF;
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
  
  vector<vector<char>> g (n, vector<char>(n, '0'));
  
  pair<int, int> start;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> g[i][j];
      if (g[i][j] == 'H')
        start.first = i, start.second = j;
    }
  }
  
  int ans = dijkstra(g, n, m, start);
  if (ans == INF)
    cout << "ARTSKJID\n";
  else
    cout << ans << endl;

  return 0;
}
