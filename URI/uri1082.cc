#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

typedef vector<vector<int> > graph;

int components = 0;

void dfs (graph &g, vector<int> &parent, int v){

  vector<int> ans;
  stack<int> s;

  s.push (v);
  ans.push_back (v);

  while (!s.empty()){
    int v = s.top();
    s.pop();

    parent[v] = components;

    for (int i=0; i<g[v].size(); i++){
      int u = g[v][i];

      if (parent[u] != -1)
        continue;

      parent[u] = components;

      ans.push_back (u);
      s.push (u);
    }
  }

  components++;

  sort (ans.begin(), ans.end());

  for (int i=0; i<ans.size(); i++)
    cout << (char)(ans[i] + 'a') << ',';
  cout << endl;
}

int main (){
  
  int t;

  cin >> t;
  int count = 1;

  while (t--){
    int v, e;
    cin >> v >> e;

    vector<int> parent (v, -1);
    graph g (v);

    for (int i=0; i<e; i++){
      char a, b;
      cin >> a >> b;
      g[a - 'a'].push_back (b-'a');
      g[b-'a'].push_back (a-'a');
    }

    components = 0;

    cout << "Case #" << count++ << ":\n";
    for (int i=0; i<v; i++)
      if (parent[i] == -1)
        dfs (g, parent, i);

    cout << components << " connected components\n\n";

  }

  return 0;
}
