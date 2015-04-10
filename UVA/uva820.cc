// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<vector<int> > graph;

#define INF 1100000000

long long edmonds_karp (graph &g, vector<vector<int> >& capacity, int s, int t){
  int n = g.size();
  vector<vector<int> > flow (n, vector<int> (n, 0));

  while (true){
    vector<int> parent (n);
    fill (parent.begin(), parent.end(), -1);
    vector<int> M (n, 0);
    
    queue<int> q;
    q.push (s);
    parent[s] = s;
    M[s] = INF;
    while (not q.empty()){
      int u = q.front();
      q.pop();

      if (u == t)
        break;

      for (int i=0; i<g[u].size(); i++){
        int v = g[u][i];

        if (parent[v] != -1)
          continue;

        if (capacity[u][v] - flow[u][v] > 0){
          parent[v] = u;
          M[v] = min (M[u], capacity[u][v] - flow[u][v]);
          
          if (v != t){
            q.push (v);
          }
          else {
            while (v != parent[v]){
              u = parent[v];
              flow[u][v] += M[t];
              flow[v][u] -= M[t];
              v = u;
            }
            break;
          }
        }
      }
    }

    if (parent[t] == -1){
      // nao encontrou um caminho de s ---> t
      int sum = 0;
      for (int i=0; i<n; i++){
        sum += flow[s][i];
      }

      return sum;
    }
  }

}

void uva820 (){

  int count = 1;
  while (true){
    int n;
    cin >> n;
    if (n == 0) break;

    int s, t, m;
    cin >> s >> t >> m;
    

    vector<vector<int> > capacity (n, vector<int> (n, 0));
    graph g (n);

    for (int i=0; i<m; i++){
      int u, v, c;
      cin >> u >> v >> c;
      if (capacity[u-1][v-1] == 0){
        g[u-1].push_back (v-1);
        g[v-1].push_back (u-1);
      }
      capacity[u-1][v-1] += c;
      capacity[v-1][u-1] += c;
    }

    cout << "Network " << count++ << endl;
    cout << "The bandwidth is " << edmonds_karp (g, capacity, s-1, t-1) << ".\n";
    cout << endl;
  }
}

int main (){
  
  uva820 ();
  return 0;
}
