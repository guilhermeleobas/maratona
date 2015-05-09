#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;
typedef vector<vector<int> > graph;
graph g;
vector<pair<int, int> > v;
int e = 0;
void toposort (){

  vector<int> visited (g.size(), 0);
  
  while (not s.empty()){
    
    int a = s.top();
    s.pop();

    if (visited[a])
      continue;

    if (v[a].first == 0)
      continue;

    visited[a] = 1;

    int b = v[a].second;

    g[a].push_back (b);
    //g[b].push_back (a);

    v[a].first = 0;
    v[a].second = 0;

    v[b].first--;
    v[b].second ^= a;

    if (v[b].first == 1)
      s.push (b);

    e++;
  }
}

int main (){

  int n;
  cin >> n;
  g.resize (n);
  v.resize (n);
  
  for (int i=0; i<n; i++){
    cin >> v[i].first >> v[i].second;
    if (v[i].first == 1)
      s.push (i);
  }

  toposort ();
  cout << e << endl; 
  for (int i=0; i<g.size(); i++){
    for (int j=0; j<g[i].size(); j++){
      cout << i << ' ' << g[i][j] << endl;
    } 
  }

  return 0;
}
