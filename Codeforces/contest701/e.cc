#include <iostream>
#include <numeric>
#include <functional>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<vector<int> > graph;

int counter[200000 + 200];
int visited[200000 + 200];

int dfs (const graph& g, const vector<int>& college, const int v){
  
  visited[v] = 1;
  
  counter[v] = college[v];
  
  // cout << "v: " << v << endl;
  
  for (int i=0; i<g[v].size(); i++){
    int u = g[v][i];
    // cout << "u: " << u << endl;
    if (visited[u])
      continue;
    // cout << "chamou u: " << u << endl;
    
    counter[v] += dfs (g, college, u);
  }
  // cout << "fechou v: " << v << " com c[v]: " << counter[v] << endl;
  return counter[v];
}

int main (){

  int n, k;
  cin >> n >> k;
  
  vector<int> college(n);
  graph g(n);
  
  for (int i=0; i<2*k; i++){
    int c;
    cin >> c;
    c--;
    college[c] = 1;
  }
  
  for (int i=0; i<n-1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  // for (int i=0; i<n; i++){
  //   cout << i << ": ";
  //   for (int j=0; j<g[i].size(); j++){
  //     cout << g[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  
  dfs(g, college, 0);
  long long s = 0;
  
  for (auto i: counter){
    s += min (i, 2*k-i); 
  } 
  cout << s<< endl;
  
  // for (int i=0; i<n; i++){
  //   cout << counter[i] << ' ';
  // }
  // cout << endl;
  return 0;
}
