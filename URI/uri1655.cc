#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;

typedef vector<vector<pair<double, int>>> graph;
#define INF 0x3f3f3f3f
#define MAX 500 + 10

double g[MAX][MAX];

double floyd (int n){
  for (int k=0; k<n; k++){
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        if (!(g[i][k] && g[k][j])) continue;
        if (g[i][j] < g[i][k] * g[k][j]){
          g[i][j] = g[i][k] * g[k][j];
        }
      }
    }
  }
  
  return g[0][n-1] * 100.0;
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  
  int t = 1;
  
  while (true){
    int n, m;
    
    cin >> n;
    if (n == 0) break;
    
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        g[i][j] = 0.0;
    
    cin >> m;
    
    for (int i=0; i<m; i++){
      int u, v;
      double c;
      cin >> u >> v >> c;
      u--; v--;
      
      g[u][v] = g[v][u] = c/100.0;
      
    }
    
    cout << fixed << setprecision(6) << floyd (n) << " percent" << endl;
    
  }
  
  
  return 0;
}
