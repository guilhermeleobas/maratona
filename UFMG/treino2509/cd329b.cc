// http://codeforces.com/problemset/problem/329/B
#include <map>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef vector<string> graph;

vector<vector<int> > bfs (graph &g, pair<int, int> start){
  queue<pair<int, int> > q;
  vector<vector<int> > cost (g.size(), vector<int> (g[0].size(), 0x3f3f3f3f)), visited (g.size(), vector<int> (g[0].size(), 0));
  
  int r = g.size();
  int c = g[0].size();
  
  visited[start.first][start.second] = 1;
  cost[start.first][start.second] = 0;
  q.push (start);
  
  while (not q.empty()){
    pair<int, int> atual = q.front();
    q.pop();
    
    visited[atual.first][atual.second] = 1;
    
    if (atual.first - 1 >= 0 and !visited[atual.first - 1][atual.second]
        and cost[atual.first][atual.second] + 1 < cost[atual.first-1][atual.second]
        and g[atual.first-1][atual.second] != 'T'){
      
      cost[atual.first-1][atual.second] = cost[atual.first][atual.second] + 1;
      q.push (make_pair (atual.first-1, atual.second));
    }
    
    if (atual.first + 1 < r and !visited[atual.first+1][atual.second]
        and cost[atual.first][atual.second] + 1 < cost[atual.first+1][atual.second]
        and g[atual.first+1][atual.second] != 'T'){
      
      cost[atual.first+1][atual.second] = cost[atual.first][atual.second] + 1;
      q.push (make_pair (atual.first+1, atual.second));
    }
    
    if (atual.second - 1 >= 0 and !visited[atual.first][atual.second-1]
        and cost[atual.first][atual.second] + 1 < cost[atual.first][atual.second-1]
        and g[atual.first][atual.second-1] != 'T'){
      cost[atual.first][atual.second-1] = cost[atual.first][atual.second] + 1;
      q.push (make_pair (atual.first, atual.second-1));
    }
    
    if (atual.second + 1 < c and !visited[atual.first][atual.second+1]
        and cost[atual.first][atual.second] + 1 < cost[atual.first][atual.second+1]
        and g[atual.first][atual.second+1] != 'T'){
      cost[atual.first][atual.second+1] = cost[atual.first][atual.second] + 1;
      q.push (make_pair (atual.first, atual.second+1));
    }
  }
 
  return cost;
}

int main (){

  int r, c;
  cin >> r >> c;
  graph g;
  pair<int, int> e, st;
  map<pair<int, int>, int> mapa;
  for (int i=0; i<r; i++){
    string s;
    cin >> s;
    g.push_back (s);
    
    for (int j=0; j<s.size(); j++){
      if (s[j] == 'E'){
        e = make_pair (i, j);
      }
      else if (s[j] == 'S'){
        st = make_pair (i, j);
      }
      else if (s[j] != 'T'){
        mapa[make_pair (i, j)] = int (s[j]-'0');
      }
    }
  }
  
  vector<vector<int> > cost = bfs (g, e);
  
  int sum = 0;
  int dist = cost[st.first][st.second];
  for (auto it = mapa.begin(); it != mapa.end(); it++){
    int aux = cost[it->first.first][it->first.second];
    if (aux <= dist)
      sum += it->second;
  }
  
  cout << sum << endl;
  
  return 0;
}
