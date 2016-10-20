#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<vector<int> > graph;

map<int, int> mapa;

int visited[1000000 + 100];
int perm[1000000 + 100];

void print (graph g){
  for (int i=0; i<g.size(); i++){
    cout << i << ": ";
    for (int j=0; j<g[i].size(); j++){
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }
}

void dfs (const graph& g, int v, int pos){
  stack<int> s;
  s.push(pos);
  
  vector<int> p, q;
  
  visited[pos] = true;
  
  while (not s.empty()){
    int pos = s.top();
    
    s.pop();
    
    q.push_back (pos);
    p.push_back (mapa[pos]);
    int topo = mapa[pos];
    
    // cout << "topo: " << topo << " pos: " << pos << endl;
    
    for (int i=0; i<g[pos].size(); i++){
      int pos_prox = g[pos][i];
      int prox = mapa[pos_prox];
      // cout << "prox: " << prox << " pos_prox: " << pos_prox << endl;
      
      if (visited[pos_prox])
        continue;
      
      visited[pos_prox] = true;
      
      s.push(pos_prox);
    }
  }
  
  sort (p.begin(), p.end(), std::greater<int>());
  sort (q.begin(), q.end() );
  
  int i = 0;   
  
  while (i < p.size()){
    perm[q[i]] = p[i];
    i++;
  }
}

int main (){
  
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  
  graph g (n);
  // vector<int> v (n);
  for (int i=0; i<n; i++){
    int aux;
    cin >> aux;
    // mapa[aux-1] = i;
    mapa[i] = aux-1;
    perm[i] = aux-1;
  }
  
  // for (auto i: mapa){
  //   cout << i.first << ' ' << i.second << endl;
  // }
  // cout << endl;
  
  for (int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back (b);
    g[b].push_back (a);
  }
  
  for (int i=0; i<n; i++){
    int pos = i; 
    int elem = mapa[i];
    if (not visited[pos]){
      dfs(g, elem, pos);
    } 
  }
  
  for (int i=0; i<n; i++){
    cout << perm[i]+1 << ' ';
  }
  cout << endl;
  
  return 0;
}
