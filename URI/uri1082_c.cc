#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef vector<vector<int> > graph;

vector<int> visited;
vector<int> _index;
vector<int> lowlink;
int index_count = 0;
vector<int> scc;
stack<int> s;

void dfs (graph g, int v){
  _index[v] = index_count;
  lowlink[v] = index_count;
  index_count++;

  s.push (v);
  visited[v] = true;

  for (int i=0; i<g[v].size(); i++){
    int w = g[v][i];
    if (_index[w] == -1){
      dfs (g, w);
      lowlink[v] = min (lowlink[v], lowlink[w]);
    }
    else if (visited[v]){
      lowlink[v] = min (lowlink[v], _index[w]);
    } 
  }

  // Existe uma SCC que contem V e ele é o cara de menor indice nela
  if (_index[v] == lowlink[v]){
    while (true){
      int w = s.top();
      s.pop();

      scc[w] = _index[v];

      if (v == w)
        break;
    }
  }
}

void tarjan (graph g){
  int n = g.size();
  
  _index.clear();
  lowlink.clear();
  visited.clear();
  scc.clear();
  index_count = 0;
  _index.resize (n, -1);
  lowlink.resize (n, 0x3f3f3f3f);
  visited.resize (n, false);
  scc.resize (n, 0);
  
  for (int i=0; i<n; i++)
    scc[i] = i;

  for (int i=0; i<n; i++){
    if (_index[i] == -1){
      dfs (g, i);
    }
  }
}

int main (){
  
  int t;
  cin >> t;
  int testcase = 1;
  while (t--){
    int n, m;
    cin >> n >> m;
    graph g (n);

    for (int i=0; i<m; i++){
      char a, b;
      cin >> a >> b;
      g[a-'a'].push_back (b-'a');
      g[b-'a'].push_back (a-'a');
    }

    tarjan (g);
    map<int, set<int> > mapa;
    for (int i=0; i<scc.size(); i++){
      mapa[scc[i]].insert (i);
    }

    cout << "Case #" << testcase++ << ":\n";
    for (map<int, set<int> >::iterator it = mapa.begin(); it != mapa.end(); it++){
      for (set<int>::iterator j = it->second.begin(); j != it->second.end(); j++){
        cout << (char)(*j+'a') << ",";
      }
      cout << endl;
    }
    cout << mapa.size() << " connected components\n\n";
  }

  return 0;
}
