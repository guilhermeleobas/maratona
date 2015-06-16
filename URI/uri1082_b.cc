#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>

using namespace std;

typedef vector<vector<int> > graph;

stack<int> s;
vector<int> visited;

void first_dfs (graph g, int vertex){
  //cout << "iniciou dfs com vertex=" << vertex << endl;
  visited[vertex] = 1;
  for (int i=0; i<g[vertex].size(); i++){
    int next_vertex = g[vertex][i];
    
    if (visited[next_vertex])
      continue;
    
    //cout << "chamou dfs com vertex=" << vertex << endl;
    first_dfs (g, next_vertex);

  }
  //cout << "push no vertex=" << vertex << endl;
  s.push (vertex);
}

void second_dfs (graph r, vector<int>& gcc, int belongs, int vertex){
  
  //cout << "dfs 2=" << vertex << " belongs=" << belongs << endl;
  visited[vertex] = true;
  gcc[vertex] = belongs;

  for (int i=0; i<r[vertex].size(); i++){
    int next_vertex = r[vertex][i];

    if (visited[next_vertex])
      continue;
    
    second_dfs (r, gcc, belongs, next_vertex);
  }
}

vector<int> kosaraju (graph g, graph r){
  int n = g.size();
  visited.clear();
  visited.resize (n, 0);

  for (int i=0; i<n; i++)
    if (not visited[i])
      first_dfs (g, i);
      
  vector<int> gcc (n);
  for (int i=0; i<gcc.size(); i++)
    gcc[i] = i;

  fill (visited.begin(), visited.end(), 0);

  while (not s.empty()){
    
    int vertex = s.top();
    s.pop();
      
    //cout << "vertex: " << vertex << endl;

    if (visited[vertex])
      continue;

    second_dfs (r, gcc, vertex, vertex);
  }

  return gcc;
}

int main (){
  
  int t;
  cin >> t;
  int testcase = 1;
  while (t--){
    int n, m;
    cin >> n >> m;
    graph g(n);
    

    for (int i=0; i<m; i++){
      char a, b;
      cin >> a >> b;
      g[a-'a'].push_back (b-'a');
      g[b-'a'].push_back (a-'a');
    }

    vector<int> scc = kosaraju (g, g);
    
    map<int, set<int> > mapa;
    for (int i=0; i<scc.size(); i++){
      mapa[scc[i]].insert (i);
    }

    int cnt = mapa.size();
    
    cout << "Case #" << testcase << ":\n";
    for (map<int, set<int> >::iterator it = mapa.begin(); it != mapa.end(); it++){
      for (set<int>::iterator j = it->second.begin(); j != it->second.end(); j++){
        cout << (char)(*j+'a') << ',';
      }
      cout << endl;
    }
    cout << cnt << " connected components\n\n";
    testcase++;
 }

  return 0;
}
